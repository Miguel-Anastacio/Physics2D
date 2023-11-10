#pragma once
#include "Dynamics/RigidBody.h"
#include"Dynamics/Solver.h"
#include <memory>
#include <vector>
namespace Physics2D
{
	class PhysicsWorld
	{
	public:
		PhysicsWorld();

		//void AddCollisionBody();
		

		void CleanupCollisionBodies(const std::vector<uint64_t>& ids);
		void Step(float dt);

		std::vector<std::shared_ptr<CollisionBody>> m_CollisionBodies;
	private:

		std::vector<Solver> m_Solvers;

		void ApplyGravity(Rigidbody* object, const float& dt);
		void ResolveCollisions(const float& dt);

		//ObjectManager m_ObjectManager;

		Vector2 m_Gravity = Vector2(0, 98.f);


	};
}
