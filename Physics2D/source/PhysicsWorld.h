#pragma once
#include "Dynamics/RigidBody.h"
#include <memory>
#include <vector>
namespace Physics2D
{
	class PhysicsWorld
	{
	public:
		PhysicsWorld();
		void Step(float dt);

		void SetCollisionBodiesReference(std::vector<std::shared_ptr<CollisionBody>>* bodies);
		

	private:

		void ApplyGravity(Rigidbody* object, const float&dt);
		void DetectCollisions();

		//ObjectManager m_ObjectManager;
		std::vector<std::shared_ptr<CollisionBody>>* m_CollisionBodies = NULL;
		Vector2 m_Gravity = Vector2(0, 98.f);


	};
}
