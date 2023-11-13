#include "PhysicsWorld.h"
#include <iostream>
#include "Dynamics/Solvers/ImpulseSolver.h"
#include "Dynamics/Solvers/SmoothPositionSolver.h"
#include "Collision/QuadTree.h"
namespace Physics2D
{
	PhysicsWorld::PhysicsWorld()
	{
		m_ImpulseSolver = new ImpulseSolver();
		m_Solvers.push_back(m_ImpulseSolver);
		m_SmoothPositionSolver = new SmoothPositionSolver();
		m_Solvers.push_back(m_SmoothPositionSolver);
	}

	PhysicsWorld::~PhysicsWorld()
	{
		if (m_ImpulseSolver != nullptr)
			delete m_ImpulseSolver;
		if (m_SmoothPositionSolver != nullptr)
			delete m_SmoothPositionSolver;
	}

	void PhysicsWorld::Step(float dt)
	{
		ApplyGravity();
		ResolveCollisions(dt);
		MoveBodies(dt);
	}

	void PhysicsWorld::CleanupCollisionBodies(const std::vector<uint64_t>& ids)
	{
		for (const auto& id : ids)
		{
			for (std::vector<std::shared_ptr<CollisionBody>>::iterator it = m_CollisionBodies.begin(); it != m_CollisionBodies.end();)
			{
				if (it->get()->GetID() == id)
				{
					it = m_CollisionBodies.erase(it);
					break;
				}
				else
				{
					it++;
				}
			}
		}
	}

	void PhysicsWorld::ApplyGravity()
	{
		for (auto& body : m_CollisionBodies)
		{
			Rigidbody* rb = static_cast<Rigidbody*>(body.get());
			if (rb != NULL && rb->IsKinematic())
			{
				rb->AddForce(m_Gravity * rb->GetGravityScale() * rb->GetMass());
			}
		}
	}

	void PhysicsWorld::BroadPhase()
	{
		m_BroadphaseCollisions.clear();
		QuadTree<CollisionBody*> tree(Vector2(512, 512), 2, 5);
		for (auto& body : m_CollisionBodies)
		{
			Aabb boundingBox;
			if (!body->GetAabb(boundingBox))
				continue;

			tree.Insert(body.get(), boundingBox.Centre, boundingBox.HalfSize);
		}

		tree.OperateOnContents([&](std::list<QuadTreeEntry<CollisionBody*>>& data) 
			{
				CollisionPair pair;
				for (auto i = data.begin(); i != data.end();i++)
				{
					for (auto j = std::next(i); j != data.end(); j++)
					{
						pair.bodyA = std::min(i->Object, j->Object);
						pair.bodyB = std::max(i->Object, j->Object);
						m_BroadphaseCollisions.insert(pair);
					}
				}
			})

		if (m_CollisionBodies.size() > 20)
		{
			int a = 0;
		}
	}

	void PhysicsWorld::ResolveCollisions(const float& dt)
	{
		std::vector<Collision> collisions;
		Manifold manifold;


		// Broad Phase
		BroadPhase();


		int maxBody = m_CollisionBodies.size();
		if (m_CollisionBodies.size() > 10000)
		{
			maxBody = 10000;
		}
		for (int i = 0; i < maxBody; i++)
		{
			for (int j = i+1; j < maxBody; j++)
			{
	
				if (i == j)
					break;
				Collider* col = m_CollisionBodies[i]->GetColliderShared().get();
				Collider* col2 = m_CollisionBodies[j]->GetColliderShared().get();
				Transform t2 = m_CollisionBodies[j]->GetTransform();
				manifold = col->TestCollision(m_CollisionBodies[i]->GetTransform(), col2, t2);
				if (manifold.HasCollision)
				{
					collisions.emplace_back(manifold, m_CollisionBodies[i].get(), m_CollisionBodies[j].get());
					//collisions.back().Print();
				}
			}
		}

		// resolve collisions
		for (Solver* solver : m_Solvers)
		{
			solver->Solve(collisions, dt);
		}
		//return collisions;
	}

	void PhysicsWorld::MoveBodies(const float& dt) const
	{
		for (auto& body : m_CollisionBodies)
		{
			Rigidbody* rb = dynamic_cast<Rigidbody*>(body.get());
			if (rb != NULL && rb->IsKinematic())
			{
				rb->SetVelocity(rb->GetVelocity() + rb->GetForce() * rb->GetInvMass() * dt);

				rb->SetPosition(rb->GetPosition() + rb->GetVelocity() * dt);

				rb->SetForce(Vector2(0, 0));
			}


		}
	}
}