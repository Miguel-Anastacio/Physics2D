#include "AabbCollider.h"
#include "PolygonCollider.h"
#include "../ManifoldGeneration.h"
namespace Physics2D
{
	AabbCollider::AabbCollider(float halfWidth, float halfHeight)
		: m_HalfWidth(halfWidth), m_HalfHeight(halfHeight)
	{
		m_Center = Vector2(halfWidth, halfHeight);
	}

	Manifold AabbCollider::TestCollision(const Transform& transform, const Collider* collider, const Transform& colliderTransform) const
	{
		return collider->TestCollision(colliderTransform, this, transform);
	}
	Manifold AabbCollider::TestCollision(const Transform& transform, const CircleCollider* collider, const Transform& colliderTransform) const
	{
		return detection::FindAabbCircleManifold(transform, this, colliderTransform, collider);
	}
	Manifold AabbCollider::TestCollision(const Transform& transform, const PolygonCollider* collider, const Transform& colliderTransform) const
	{
		return detection::FindAabbPolygonManifold(transform, this, colliderTransform, collider);
	}
	Manifold AabbCollider::TestCollision(const Transform& transform, const AabbCollider* collider, const Transform& colliderTransform) const
	{
		return detection::FindAabbAabbManifold(transform, this, colliderTransform, collider);
	}
	float AabbCollider::CalculateArea(const Transform& t) const
	{
		float a = m_HalfHeight * 2 * t.Scale.Y * m_HalfWidth * 2 * t.Scale.X;
		return a;
	}
	Vector2 AabbCollider::FindFurthestPoint(Vector2 direction) const
	{
		return Vector2();
	}
}