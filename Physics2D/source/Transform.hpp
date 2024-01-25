#pragma once
#include "Vector2.h"
namespace Physics2D
{
	struct Transform
	{
		Vector2 Position;
		Vector2 Scale = Vector2(1, 1);
		float Rotation = 0;
	};

}