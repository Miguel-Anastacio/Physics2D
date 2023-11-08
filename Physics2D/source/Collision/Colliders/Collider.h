#pragma once
#include "../Manifold.h"
#include "../../Transform.hpp"
namespace Physics2D
{
	/*enum class TypeOfCollider
	{
		Trigger,
		
	};*/

	class BoxCollider;
	class CircleCollider;
	class AabbCollider;

	class Collider
	{
	public:

		Collider();
		virtual Manifold TestCollision(const Transform& transform, const Collider* collider, const Transform& colliderTransform) const = 0;
		virtual Manifold TestCollision(const Transform& transform, const CircleCollider* collider, const Transform& colliderTransform) const = 0;
		virtual Manifold TestCollision(const Transform& transform, const BoxCollider* collider, const Transform& colliderTransform) const = 0;
		virtual Manifold TestCollision(const Transform& transform, const AabbCollider* collider, const Transform& colliderTransform) const = 0;


		Vector2 m_Center;

	protected:
	};
}

