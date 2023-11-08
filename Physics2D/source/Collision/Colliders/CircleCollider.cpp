#include "CircleCollider.h"
#include "BoxCollider.h"
#include "../ManifoldGeneration.h"
namespace Physics2D
{
	CircleCollider::CircleCollider(float radius)
		: m_Radius(radius)
	{

	}
	Manifold CircleCollider::TestCollision(const Transform& transform, const Collider* collider, const Transform& colliderTransform) const
	{
		return TestCollision(transform, this, colliderTransform);
	}

	Manifold CircleCollider::TestCollision(const Transform& transform, const CircleCollider* collider, const Transform& colliderTransform) const
	{
		return detection::FindCircleCircleManifold(transform, this, colliderTransform, collider);
	}

	Manifold CircleCollider::TestCollision(const Transform& transform, const BoxCollider* collider, const Transform& colliderTransform) const
	{
		return detection::FindCircleBoxManifold(transform, this, colliderTransform, collider);
	}

	Manifold CircleCollider::TestCollision(const Transform& transform, const AabbCollider* collider, const Transform& colliderTransform) const
	{
		return detection::FindCircleAabbManifold(transform, this, colliderTransform, collider);
	}

}
