#include "ManifoldGeneration.h"
#include "Colliders/BoxCollider.h"
#include "Colliders/CircleCollider.h"
#include "Colliders/AabbCollider.h"
namespace Physics2D
{
	namespace detection
	{
		Manifold FindCircleCircleManifold(const Transform& transformA, const CircleCollider* circleA, const Transform& transformB, const CircleCollider* circleB)
		{
			Vector2 centreA = transformA.Position + circleA->m_Center;
			Vector2 centreB = transformB.Position + circleB->m_Center;

			float radiusA = circleA->m_Radius * transformA.Scale.X;
			float radiusB = circleB->m_Radius * transformB.Scale.X;


			Vector2 BtoA = centreA - centreB;
			Vector2 AtoB = centreB - centreA;
			
			float radiusSq = (radiusA + radiusB) * (radiusA + radiusB);

			if (BtoA.MagnitudeSqr() > radiusSq)
			{
				return Manifold();
			}
			
			Vector2 aPos = centreA + AtoB.Normalized() * radiusA;
			Vector2 test = AtoB.Normalized();
			Vector2 bPos = centreB + BtoA.Normalized() * radiusB;

			Vector2 collisionPointsDistance = bPos - aPos;
			Vector2 norm = collisionPointsDistance.Normalized();
			float depth = collisionPointsDistance.Magnitude();
			return Manifold(aPos, bPos, collisionPointsDistance.Normalized(), collisionPointsDistance.Magnitude());

		}
		Manifold FindCircleBoxManifold(const Transform& circleTransform, const CircleCollider* circle, const Transform& boxTransform, const BoxCollider* box)
		{
			// to do
			return Manifold();
		}
		Manifold FindCircleAabbManifold(const Transform& circeTransform, const CircleCollider* circle, const Transform& boxTransform, const AabbCollider* box)
		{
			// to do
			return Manifold();
		}
		Manifold FindAabbAabbManifold(const Transform& transformA, const AabbCollider* boxA, const Transform& transformB, const AabbCollider* boxB)
		{
			Vector2 centreA = transformA.Position + boxA->m_Center;
			Vector2 centreB = transformB.Position + boxB->m_Center;

			Vector2 halfSizeA = Vector2(boxA->m_HalfWidth * transformA.Scale.X, boxA->m_HalfHeight * transformA.Scale.Y);
			Vector2 halfSizeB = Vector2(boxB->m_HalfWidth * transformB.Scale.X, boxB->m_HalfHeight * transformB.Scale.Y);
			
			Vector2 BtoA = centreA - centreB;
			Vector2 AtoB = BtoA * -1;

			// test overlap on x axis
			const float xOverlap = halfSizeA.X + halfSizeB.X - fabs(BtoA.X);

			if (xOverlap <= 0.0f)
				return Manifold();

			const float yOverlap = halfSizeA.Y + halfSizeB.Y - fabs(BtoA.Y);
			if (yOverlap <= 0.0f)
				return Manifold();

			Vector2 normal;
			Vector2 aFurthestPoint;
			Vector2 bFurthestPoint;
			if (xOverlap > yOverlap)
			{
				if (AtoB.Y > 0)
				{
					normal = Vector2(0.0f, -1.0f);
					aFurthestPoint.Y = centreA.Y + halfSizeA.Y;
					bFurthestPoint.Y = centreB.Y - halfSizeB.Y;
				}
				else
				{
					normal = Vector2(0, 1.0f);
					aFurthestPoint.Y = centreA.Y - halfSizeA.Y;
					bFurthestPoint.Y = centreB.Y + halfSizeB.Y;
				}

				if (AtoB.X > 0)
				{
					aFurthestPoint.X = centreA.X + halfSizeA.X - xOverlap/2.0f;
					bFurthestPoint.X = centreB.X - halfSizeB.X + xOverlap/2.0f;
				}
				else
				{
					aFurthestPoint.X = centreA.X - halfSizeA.X + xOverlap / 2.0f;
					bFurthestPoint.X = centreB.X + halfSizeB.X - xOverlap / 2.0f;
				}


				return Manifold(aFurthestPoint, bFurthestPoint, normal, yOverlap);
			}
			else
			{
				if (AtoB.Y > 0)
				{
					aFurthestPoint.Y = centreA.Y + halfSizeA.Y - yOverlap / 2.0f;
					bFurthestPoint.Y = centreB.Y - halfSizeB.Y + yOverlap / 2.0f;
				}
				else
				{
					aFurthestPoint.Y = centreA.Y - halfSizeA.Y + yOverlap / 2.0f;
					aFurthestPoint.Y = centreB.Y + halfSizeB.Y - yOverlap / 2.0f;

				}

				if (AtoB.X > 0)
				{
					normal = Vector2(-1.0f, 0.0f);
					aFurthestPoint.X = centreA.Y + halfSizeA.Y;
					bFurthestPoint.X = centreB.Y - halfSizeB.Y;
				
				}
				else
				{
					normal = Vector2(1.0f, 0.0f);
					aFurthestPoint.X = centreA.X - halfSizeA.X;
					bFurthestPoint.X = centreB.X + halfSizeB.X;
		
				}


				return Manifold(aFurthestPoint, bFurthestPoint, normal, xOverlap);
			}


			//if (xDepth > 0.0f && yDepth > 0.0f)
			//{
			//	collision.HasCollision = true;
			//	if (xDepth > yDepth)
			//	{
			//		// collision along the x vector
			//		// box A is to the left of box B
			//		if (centreVector.X < 0)
			//			collision.Normal = Vector2(-1, 0);
			//		else
			//			collision.Normal = Vector2(-1, 0);
			//	}
			//	else
			//	{
			//		// collision along the y vector
			//		// box A is above box B
			//		if (centreVector.Y < 0)
			//			collision.Normal = Vector2(0, 1);
			//		else
			//			collision.Normal = Vector2(0, -1);
			//	}
			//	// take the maximum depth
			//	collision.Depth = (xDepth > yDepth) ? xDepth : yDepth;
			//}
		}
		Manifold FindAabbBoxManifold(const Transform& aabbTransform, const AabbCollider* aabb, const Transform& boxTransform, const BoxCollider* box)
		{
			// to to
			return Manifold();
		}
		Manifold FindBoxBoxManifold(const Transform& transformA, const BoxCollider* boxA, const Transform& transformB, const BoxCollider* boxB)
		{
			// to do
			return Manifold();
		}
	}

}