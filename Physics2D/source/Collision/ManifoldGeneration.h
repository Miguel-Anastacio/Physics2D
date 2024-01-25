#pragma once
#include "Manifold.h"
#include "../Transform.hpp"
#include <array>
namespace Physics2D
{
	class Collider;
	class PolygonCollider;
	class CircleCollider;
	class AabbCollider;

	struct Simplex
	{
		std::array<Vector2, 3> Points;
		int Size;

		Simplex() { Size = 0; }

		Simplex& operator=(std::initializer_list<Vector2> list)
		{
			for (Vector2 point : list)
			{
				Points[Size++] = point;
			}
			return *this;
		}

		void PushFront(Vector2 point)
		{
			Points = { point, Points[0], Points[1] };
			Size = std::min(Size + 1, 3);
		}

		Vector2 operator[](int i)
		{
			return Points[i];
		}
	};
	/*struct SimplexVertex
	{
		Vector2 point;
		int index;
		float u;
	};

	struct Simplex
	{
		SimplexVertex VertexA;
		SimplexVertex VertexB;
		SimplexVertex VertexC;
		int count;
	};*/

	namespace detection
	{

		Manifold FindCircleCircleManifold(
			const Transform& transformA, const CircleCollider* circleA, 
			const Transform& transformB, const CircleCollider* circleB );

		Manifold FindCirclePolygonManifold(
			const Transform& circleTransform, const CircleCollider* circle, const Transform& boxTransform, const PolygonCollider* box) ;

		Manifold FindCircleAabbManifold(
			const Transform& circleTransform, const CircleCollider* circle,
			const Transform& boxTransform, const AabbCollider* box) ;

		Manifold FindAabbAabbManifold(
			const Transform& transformA, const AabbCollider* boxA, const Transform& transformB, const AabbCollider* boxB) ;

		Manifold FindAabbPolygonManifold(
			const Transform& aabbTransform, const AabbCollider* aabb,
			const Transform& boxTransform, const PolygonCollider* box) ;

		Manifold FindAabbCircleManifold(
			const Transform& aabbTransform, const AabbCollider* aabb,
			const Transform& circleTransform, const CircleCollider* circle);

		Manifold FindPolygonPolygonManifold(
			const Transform& transformA, const PolygonCollider* boxA,
			const Transform& transformB, const PolygonCollider* boxB);

		//// GJK Algorithm
		Vector2 GetSupport(const Collider& colliderA, const Collider& colliderB, const Transform& tA, const Transform& tB, Vector2 direction);
		//// return the index of the vertex of a polygon
		//int Support(const PolygonCollider& collider, Vector2 dir);

		bool GJK(const Collider& colliderA, const Collider& colliderB, const Transform& tA, const Transform& tB);

		bool NextSimplex(Simplex& points, Vector2& direction);

		inline bool SameDirection(Vector2 dir, Vector2 ao) { return dir.Dot(ao) > 0; };

		bool Line(Simplex& points, Vector2& direction);
		bool Triangle(Simplex& points, Vector2& direction);
		float FindAxisLeastPenetration(int& index, const PolygonCollider& polygonA, const PolygonCollider& polygonB);

	};
}

