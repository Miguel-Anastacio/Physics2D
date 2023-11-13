#pragma once
#include "../Vector2.h"
namespace Physics2D
{
	struct Manifold
	{
		Vector2 A;
		Vector2 B;
		Vector2 Normal;
		float Depth;
		bool HasCollision;

		Manifold(const Vector2& a, const Vector2& b, const Vector2& normal, const float& depth)
			: A(a), B(b), Normal(normal), Depth(depth)	
		{
			HasCollision = true;
		}

		Manifold(const Vector2& normal, const float& depth)
			: Normal(normal), Depth(depth) {}

		Manifold()
			: Manifold(Vector2(), 0.0f)
		{
			HasCollision = false;
		}

		Manifold Swaped() const
		{
			Manifold copy = *this;
			copy.A = B;
			copy.B = A;
			copy.Normal = Normal*-1;
			return copy;
		}

	};
}
