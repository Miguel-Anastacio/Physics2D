#pragma once
#include "Solver.h"
namespace Physics2D
{
    class SmoothPositionSolver : public Solver
    {
    public:
        void Solve(std::vector<Collision>& collisions, const float& dt) override;
		
    };
}
