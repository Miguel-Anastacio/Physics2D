#include "PhysicsWorld.h"

namespace Physics2D
{
	PhysicsWorld::PhysicsWorld()
	{

	}

	void PhysicsWorld::Step(float dt)
	{
		for (auto& body : *m_CollisionBodies)
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
		DetectCollisions();
	}

	void PhysicsWorld::SetCollisionBodiesReference(std::vector<std::shared_ptr<CollisionBody>>* bodies)
	{
		m_CollisionBodies = bodies;
	}



	void PhysicsWorld::ApplyGravity(Rigidbody* rb, const float& dt)
	{
		rb->SetForce(rb->GetForce() + m_Gravity * rb->GetMass());

		rb->SetVelocity(rb->GetVelocity() + rb->GetForce() / rb->GetMass() * dt);
		//rb->SetPosition(rb->GetPosition() + rb->GetVelocity() * dt);

		rb->SetForce(Vector2(0, 0));
	}

	void PhysicsWorld::DetectCollisions()
	{
		Manifold test;
		for (int i = 0; i < m_CollisionBodies->size(); i++)
		{
			for (int j = 0; j < m_CollisionBodies->size(); j++)
			{
				if (i == j)
					break;
				test = (*m_CollisionBodies)[i]->GetCollider()->TestCollision((*m_CollisionBodies)[i]->GetTransform(),
					(*m_CollisionBodies)[j]->GetCollider(), (*m_CollisionBodies)[j]->GetTransform());
			}
			

		}
	}
}