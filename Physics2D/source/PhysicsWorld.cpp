#include "PhysicsWorld.h"
#include <iostream>
namespace Physics2D
{
	PhysicsWorld::PhysicsWorld()
	{

	}

	void PhysicsWorld::Step(float dt)
	{
		for (auto& body : m_CollisionBodies)
		{
			/*	obj->SetForce(obj->GetForce() + m_Gravity * obj->GetMass());

				obj->SetVelocity(obj->GetVelocity() + obj->GetForce() / obj->GetMass() * dt);
				obj->SetPosition(obj->GetPosition() + obj->GetVelocity() * dt);

				obj->SetForce(Vector2(0, 0));*/

			Rigidbody* rb = static_cast<Rigidbody*>(body.get());
			if (rb != NULL)
			{
				ApplyGravity(rb, dt);
				rb->SetPosition(rb->GetPosition() + rb->GetVelocity() * dt);
			}
		}
		ResolveCollisions(dt);
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

	void PhysicsWorld::ApplyGravity(Rigidbody* rb, const float& dt)
	{
		rb->SetForce(rb->GetForce() + m_Gravity / rb->GetMass());
		rb->SetVelocity(rb->GetVelocity() + rb->GetForce() * rb->GetMass() * dt);

		rb->SetForce(Vector2(0, 0));
	}

	void PhysicsWorld::ResolveCollisions(const float& dt)
	{
		std::vector<Collision> collisions;
		Manifold manifold;
		for (int i = 0; i < m_CollisionBodies.size(); i++)
		{
			for (int j = 0; j < m_CollisionBodies.size(); j++)
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
					collisions.back().Print();
					int a = 0;
				}
			}
		}

		// resolve collisions
		for (Solver& solver : m_Solvers)
		{
			solver.Solve(collisions, dt);
		}
		//return collisions;
	}
}