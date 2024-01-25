#pragma once
#include "Collider.h"
namespace Physics2D
{
	class AabbCollider : public Collider
	{
	public:
		AabbCollider(float halfWidth, float halfHeight);
		Manifold TestCollision(const Transform& transform, const Collider* collider, const Transform& colliderTransform) const override;
		Manifold TestCollision(const Transform& transform, const CircleCollider* collider, const Transform& colliderTransform)const override;
		Manifold TestCollision(const Transform& transform, const PolygonCollider* collider, const Transform& colliderTransform) const override;
		Manifold TestCollision(const Transform& transform, const AabbCollider* collider, const Transform& colliderTransform) const override;

		float CalculateArea(const Transform& t) const override;
		Vector2 FindFurthestPoint(Vector2 direction) const override;
		float m_HalfWidth;
		float m_HalfHeight;
	};
}

