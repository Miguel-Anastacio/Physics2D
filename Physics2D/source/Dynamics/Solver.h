#pragma once
#include "../Collision/CollisionStruct.hpp"
#include <vector>
namespace Physics2D
{
	class Solver
	{
	public:
		virtual void Solve(std::vector<Collision>& collisions, const float& dt) = 0;
	};
}
