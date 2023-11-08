#include "AabbCollider.h"
#include "../ManifoldGeneration.h"
namespace Physics2D
{
	AabbCollider::AabbCollider(float halfWidth, float halfHeight)
		: m_HalfWidth(halfWidth), m_HalfHeight(halfHeight)
	{

	}

	Manifold AabbCollider::TestCollision(const Transform& transform, const Collider* collider, const Transform& colliderTransform) const
	{
		return TestCollision(transform, collider, colliderTransform);
	}
	Manifold AabbCollider::TestCollision(const Transform& transform, const CircleCollider* collider, const Transform& colliderTransform) const
	{
		return detection::FindCircleAabbManifold(transform, collider, colliderTransform, this);
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