#pragma once
#include "Collider.h"
namespace Physics2D
{
	class PolygonCollider;
	class CircleCollider : public Collider
	{
	public:
		CircleCollider(float radius);
		Manifold TestCollision(const Transform& transform, const Collider* collider, const Transform& colliderTransform) const override;
		Manifold TestCollision(const Transform& transform, const CircleCollider* collider, const Transform& colliderTransform)const override;
		Manifold TestCollision(const Transform& transform, const PolygonCollider* collider, const Transform& colliderTransform) const override;
		Manifold TestCollision(const Transform& transform, const AabbCollider* collider, const Transform& colliderTransform) const override;

		float CalculateArea(const Transform& t) const override;
		float m_Radius;
		Vector2 FindFurthestPoint(Vector2 direction) const override;
	private:
	};
}

