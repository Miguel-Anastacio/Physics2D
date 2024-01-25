#pragma once
#include "../Manifold.h"
#include "../../Transform.hpp"
namespace Physics2D
{

	/*enum class TypeOfCollider
	{
		Trigger,
		
	};*/

	class PolygonCollider;
	class CircleCollider;
	class AabbCollider;

	class Collider
	{
	public:

		Collider();
		virtual Manifold TestCollision(const Transform& transform, const Collider* collider, const Transform& colliderTransform) const = 0;
		virtual Manifold TestCollision(const Transform& transform, const CircleCollider* collider, const Transform& colliderTransform) const = 0;
		virtual Manifold TestCollision(const Transform& transform, const PolygonCollider* collider, const Transform& colliderTransform) const = 0;
		virtual Manifold TestCollision(const Transform& transform, const AabbCollider* collider, const Transform& colliderTransform) const = 0;

		virtual float CalculateArea(const Transform& t) const = 0;
		Vector2 m_Center;

		virtual Vector2 FindFurthestPoint(Vector2 direction) const = 0;

	protected:
	};
}

