#include "AabbCollider.h"
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
	Manifold AabbCollider::TestCollision(const Transform& transform, const BoxCollider* collider, const Transform& colliderTransform) const
	{
		return detection::FindAabbBoxManifold(transform, this, colliderTransform, collider);
	}
	Manifold AabbCollider::TestCollision(const Transform& transform, const AabbCollider* collider, const Transform& colliderTransform) const
	{
		return detection::FindAabbAabbManifold(transform, this, colliderTransform, collider);
	}
}