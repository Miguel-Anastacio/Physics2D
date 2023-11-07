#pragma once
#include "../Utilities.h"
namespace Physics2D
{
	class Collider
	{
	public:
		Collider();
		virtual CollisionPoints TestCollision();
	};
}

