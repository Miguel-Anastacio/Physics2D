#pragma once
#include "../Vector2.h"
namespace Physics2D
{
	struct Aabb
	{
		Vector2 Centre;
		Vector2 HalfSize;
		Aabb() {};
		Aabb(const Vector2& centre, const Vector2& halfSize)
		{
			Centre = centre;
			HalfSize = halfSize;
		}
	};

	static bool TestAABB(const Vector2& posA, const Vector2& sizeA, const Vector2& posB, const Vector2& sizeB)
	{

		Vector2 halfSizeA = sizeA;
		Vector2 halfSizeB = sizeB;

		Vector2 BtoA = posA - posB;
		Vector2 AtoB = BtoA * -1;

		// test overlap on x axis
		const float xOverlap = halfSizeA.X + halfSizeB.X - fabs(AtoB.X);
		const float yOverlap = halfSizeA.Y + halfSizeB.Y - fabs(AtoB.Y);

		if (xOverlap <= 0.0f || yOverlap <= 0)
		{
			return false;
		}

		return true;
		

	}
}