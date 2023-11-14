#include "CircleCollider.h"
#include "BoxCollider.h"
#include "../ManifoldGeneration.h"
namespace Physics2D
{
	CircleCollider::CircleCollider(float radius)
		: m_Radius(radius)
	{
		m_Center = Vector2(radius, radius);
	}
	Manifold CircleCollider::TestCollision(const Transform& transform, const Collider* collider, const Transform& colliderTransform) const
	{
		return collider->TestCollision(colliderTransform, this, transform);
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

	float CircleCollider::CalculateArea(const Transform& t) const
	{
		return 3.14159265358979 * m_Radius * m_Radius;
	}

}
