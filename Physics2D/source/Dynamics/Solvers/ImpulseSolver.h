#pragma once
#include "Solver.h"
namespace Physics2D
{
	class ImpulseSolver : public Solver
	{
	public:
		void ApplyImpulse(Rigidbody* rb, const Vector2& normal);
		void ApplyImpulse(Rigidbody* rb, Rigidbody* rb2, const Vector2& normal);

		void Solve(std::vector<Collision>& collisions, const float& dt) override;
	};

}