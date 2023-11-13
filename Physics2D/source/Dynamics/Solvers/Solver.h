#pragma once
#include "../../Collision/CollisionStruct.hpp"
#include <vector>
#include "../Rigidbody.h"
namespace Physics2D
{
	class Rigidbody;
	class Solver
	{
	public:
		virtual void Solve(std::vector<Collision>& collisions, const float& dt) = 0;
	protected:
		bool TestNan(Rigidbody* rb, Rigidbody* rb2, const Collision& collision);
	};

}
