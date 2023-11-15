#pragma once
#include "Vector2.h"
namespace Physics2D
{
	struct Transform
	{
		Vector2 Position;
		Vector2 Scale;
		float Rotation = 0;
	};

}