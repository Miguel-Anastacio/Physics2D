#pragma once
#include "Dynamics/RigidBody.h"
#include "Dynamics/Solvers/Solver.h"
#include <memory>
#include <vector>
#include <set>
namespace Physics2D
{
	class ImpulseSolver;
	class SmoothPositionSolver;
	class PhysicsWorld
	{
	public:
		PhysicsWorld();
		~PhysicsWorld();

		//void AddCollisionBody();

		void CleanupCollisionBodies(const std::vector<uint64_t>& ids);
		void Step(float dt);

		std::vector<std::shared_ptr<CollisionBody>> m_CollisionBodies;
		int Collisions = 0;
		int CollisionsBP = 0;
	private:
		ImpulseSolver* m_ImpulseSolver;
		SmoothPositionSolver* m_SmoothPositionSolver;
	
		std::vector<Solver*> m_Solvers;

		std::set<CollisionPair> m_BroadphaseCollisions;
		std::set<CollisionPairTest> m_BroadphaseCollisionsTest;
		std::vector<CollisionPair> m_BroadphaseCollisionsVector;

		void BroadPhase();
		void NarrowPhase(std::vector<Collision>& collisions);
		
		void ApplyGravity();
		void ResolveCollisions(const float& dt);
		void MoveBodies(const float& dt) const;

		//ObjectManager m_ObjectManager;

		Vector2 m_Gravity = Vector2(0, 98.f);


	};
}
