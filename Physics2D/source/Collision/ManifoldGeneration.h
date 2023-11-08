#pragma once
#include "Manifold.h"
#include "../Transform.hpp"
namespace Physics2D
{
	class BoxCollider;
	class CircleCollider;
	class AabbCollider;

	namespace detection
	{

		Manifold FindCircleCircleManifold(
			const Transform& transformA, const CircleCollider* circleA, 
			const Transform& transformB, const CircleCollider* circleB );

		Manifold FindCircleBoxManifold(
			const Transform& circleTransform, const CircleCollider* circle, const Transform& boxTransform, const BoxCollider* box) ;

		Manifold FindCircleAabbManifold(
			const Transform& circeTransform, const CircleCollider* circle,
			const Transform& boxTransform, const AabbCollider* box) ;


		Manifold FindAabbAabbManifold(
			const Transform& transformA, const AabbCollider* boxA, const Transform& transformB, const AabbCollider* boxB) ;

		Manifold FindAabbBoxManifold(
			const Transform& aabbTransform, const AabbCollider* aabb,
			const Transform& boxTransform, const BoxCollider* box) ;

		Manifold FindBoxBoxManifold(
			const Transform& transformA, const BoxCollider* boxA,
			const Transform& transformB, const BoxCollider* boxB);


	};
}

