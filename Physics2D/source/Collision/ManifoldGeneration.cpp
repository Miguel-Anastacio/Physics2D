#include "ManifoldGeneration.h"
#include "Colliders/PolygonCollider.h"
#include "Colliders/CircleCollider.h"
#include "Colliders/AabbCollider.h"
#include <algorithm>
namespace Physics2D
{
	namespace detection
	{
		Manifold FindCircleCircleManifold(const Transform& transformA, const CircleCollider* circleA, const Transform& transformB, const CircleCollider* circleB)
		{
			Vector2 centreA = transformA.Position;
			Vector2 centreB = transformB.Position;

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
			if (collisionPointsDistance.Magnitude() == 0)
				int a = 0;
			Vector2 norm = collisionPointsDistance.Normalized() * -1;
			float depth = collisionPointsDistance.Magnitude();
			return Manifold(aPos, bPos, norm, collisionPointsDistance.Magnitude());

		}
		Manifold FindCirclePolygonManifold(const Transform& circleTransform, const CircleCollider* circle, const Transform& boxTransform, const PolygonCollider* box)
		{
			// to do
			return Manifold();
		}
		Manifold FindCircleAabbManifold(const Transform& circeTransform, const CircleCollider* circle, const Transform& boxTransform, const AabbCollider* box)
		{
			return FindAabbCircleManifold(boxTransform, box, circeTransform, circle).Swaped();
		}
		Manifold FindAabbAabbManifold(const Transform& transformA, const AabbCollider* boxA, const Transform& transformB, const AabbCollider* boxB)
		{
			Vector2 centreA = transformA.Position;
			Vector2 centreB = transformB.Position;

			Vector2 halfSizeA = Vector2(boxA->m_HalfWidth * transformA.Scale.X, boxA->m_HalfHeight * transformA.Scale.Y);
			Vector2 halfSizeB = Vector2(boxB->m_HalfWidth * transformB.Scale.X, boxB->m_HalfHeight * transformB.Scale.Y);
			
			Vector2 BtoA = centreA - centreB;
			Vector2 AtoB = BtoA * -1;

			// test overlap on x axis
			const float xOverlap = halfSizeA.X + halfSizeB.X - fabs(AtoB.X);

			if (xOverlap <= 0.0f)
				return Manifold();

			const float yOverlap = halfSizeA.Y + halfSizeB.Y - fabs(AtoB.Y);
			if (yOverlap <= 0.0f)
				return Manifold();

			Vector2 normal;
			Vector2 aFurthestPoint;
			Vector2 bFurthestPoint;
			if (xOverlap > yOverlap)
			{
				if (AtoB.Y > 0)
				{
					normal = Vector2(0.0f, 1.0f);
					aFurthestPoint.Y = centreA.Y + halfSizeA.Y;
					bFurthestPoint.Y = centreB.Y - halfSizeB.Y;
				}
				else
				{
					normal = Vector2(0, -1.0f);
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
					bFurthestPoint.Y = centreB.Y + halfSizeB.Y - yOverlap / 2.0f;

				}

				if (AtoB.X > 0)
				{
					normal = Vector2(1.0f, 0.0f);
					aFurthestPoint.X = centreA.X + halfSizeA.X;
					bFurthestPoint.X = centreB.X - halfSizeB.X;
				
				}
				else
				{
					normal = Vector2(-1.0f, 0.0f);
					aFurthestPoint.X = centreA.X - halfSizeA.X;
					bFurthestPoint.X = centreB.X + halfSizeB.X;
		
				}
				Vector2 furthestPointDirection = bFurthestPoint - aFurthestPoint;  
				furthestPointDirection.Y = 0;
				//normal = furthestPointDirection.Normalized();

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
		Manifold FindAabbPolygonManifold(const Transform& aabbTransform, const AabbCollider* aabb, const Transform& boxTransform, const PolygonCollider* box)
		{
			// to to
			return Manifold();
		}
		Manifold FindAabbCircleManifold(const Transform& aabbTransform, const AabbCollider* aabb, const Transform& circleTransform, const CircleCollider* circle)
		{
			Vector2 centreCircle = circleTransform.Position;
			float radius = circleTransform.Scale.X * circle->m_Radius;
			Vector2 centreBox = aabbTransform.Position;
			Vector2 halfSizeBox = Vector2(aabb->m_HalfWidth * aabbTransform.Scale.X, aabb->m_HalfHeight * aabbTransform.Scale.Y);

			Vector2 boxToCircle = centreCircle - centreBox;

			// get circle's closest point on the aabb
			Vector2 ClosestPointOnBox;
			ClosestPointOnBox.X = std::clamp(boxToCircle.X, -halfSizeBox.X, halfSizeBox.X);
			ClosestPointOnBox.Y = std::clamp(boxToCircle.Y, -halfSizeBox.Y, halfSizeBox.Y);

			bool inside = false;
			// Circle is inside the AABB, so we need to clamp the circle's center 
			// to the closest edge 
			if (boxToCircle == ClosestPointOnBox)
			{
				inside = true;
				// Find closest axis 
				if (abs(boxToCircle.X) > abs(boxToCircle.Y))
				{
					// Clamp to closest extent 
					if (ClosestPointOnBox.X > 0)
						ClosestPointOnBox.X = halfSizeBox.X;
					else
						ClosestPointOnBox.X = -halfSizeBox.X;
				}
				// y axis is shorter 
				else
				{
					// Clamp to closest extent 
					if (ClosestPointOnBox.Y > 0)
						ClosestPointOnBox.Y = halfSizeBox.Y;
					else
						ClosestPointOnBox.Y = -halfSizeBox.Y;
				}
			}




			/// determine how far is the circle from the point
			// if the distance is less than the radius then this point is inside the circle and the objects are colliding
			Vector2 localPoint = boxToCircle - ClosestPointOnBox;
			// use squared magnitude and radius to be more efficient
			if (localPoint.MagnitudeSqr() > radius*radius && !inside)
			{
				return Manifold();
			}
			Vector2 normal = localPoint.Normalized();
			Vector2 a = ClosestPointOnBox + centreBox;
			Vector2 b = centreCircle + normal * -1 * radius;
			float depth = radius - localPoint.Magnitude();

			if (inside)
			{
				normal = normal * -1;
			}


			return Manifold(a, b, normal, depth);
			

			
		}
		Manifold FindPolygonPolygonManifold(const Transform& transformA, const PolygonCollider* boxA, const Transform& transformB, const PolygonCollider* boxB)
		{
			// to do
			//	GJK(boxA, boxB, transformA, transformB);
			return Manifold();
		}
		Vector2 GetSupport(const Collider& colliderA, const Collider& colliderB, const Transform& tA, const Transform& tB, Vector2 direction)
		{
			//return colliderA.FindFurthestPoint(direction, tA) - colliderB.FindFurthestPoint(direction, tB);
		}
		/*int Support(const PolygonCollider& collider, Vector2 dir)
		{
			int index = 0;
			std::vector<Vector2> vertices = collider.GetTransformedVertices();
			float maxValue = dir.Dot(vertices[index]);
			for (int i = 1; i < vertices.size(); i++)
			{
				float value = dir.Dot(vertices[i]);

				if (value > maxValue)
				{
					index = i;
					maxValue = value;
				}
			}
			return index;

		}*/
		bool GJK(const Collider& colliderA, const Collider& colliderB, const Transform& tA, const Transform& tB)
		{
			// get initial support point in any direction
			Vector2 support = GetSupport(colliderA, colliderB, tA, tB, Vector2(1, 0));

			// add initial support to a simplex
			Simplex points;
			points.PushFront(support);
			// set the search direction towards the origin
			Vector2 direction = support * -1;

			while (true)
			{
				support = GetSupport(colliderA, colliderB, tA, tB, direction);

				if (support.Dot(direction) <= 0)
				{
					// no collision
					return false;
				}

				if (NextSimplex(points, direction))
					return true;
			}
			return false;
		}
		bool NextSimplex(Simplex& points, Vector2& direction)
		{
			switch (points.Size)
			{
			case 2: 
				return Line(points, direction);
			case 3: 
				return Triangle(points, direction);
			default:
				return false;
			
			}
		}
		bool Line(Simplex& points, Vector2& direction)
		{
			Vector2 a = points.Points[0];
			Vector2 b = points.Points[1];

			Vector2 ab = Vector2::Normalized(b - a);
			Vector2 atoOrigin = Vector2::Normalized(Vector2(0, 0) - a);

			if (SameDirection(ab, atoOrigin))
			{
				/*Vector2 cross = ab
				direction = */
				direction = Vector2::TripleProduct(ab, atoOrigin, ab);
			}
			else
			{
				points = { a };
				direction = atoOrigin;
			}

			return false;
		}
		bool Triangle(Simplex& points, Vector2& direction)
		{
			/*		B
				   / \ 		Q
				  /   \
				 /     \
				A ----- C
			*/
			// A B C 
			const Vector2 a = points[0];
			const Vector2 b = points[1];
			const Vector2 c = points[2];
			// compute 
			Vector2 ab = Vector2::Normalized(b - a);
			Vector2 ac = Vector2::Normalized(c - a);
			Vector2 aO = Vector2::Normalized(a*-1);

			Vector2 abf = Vector2::TripleProduct(ac, ab, ab);
			Vector2 acf = Vector2::TripleProduct(ab, ac, ac);


			if (SameDirection(abf, aO))
			{
				direction = abf;
				return false;
			}
			if (SameDirection(acf, aO))
			{
				direction = acf;
				return false;
			}

			return true;
		}
		float FindAxisLeastPenetration(int& index, const PolygonCollider& polygonA, const PolygonCollider& polygonB)
		{
			float bestDistance = -FLT_MAX;
			int bestIndex = 0;

			for (int i =0; i < polygonA.GetTransformedVertices().size(); i++)
			{
				// retrieve a face normal from A
				Vector2 normal = polygonA.GetEdges()[i].normal;
				// retrieve Support point from B along -normal
				Vector2 support = polygonB.FindFurthestPoint(normal * -1);
				//retrieve vertex on face from A, transform into B's model space
				Vector2 v = polygonA.GetTransformedVertices()[i];

				float penetrationDistance = normal.Dot(support - v);
				if (penetrationDistance > bestDistance)
				{
					bestDistance = penetrationDistance;
					bestIndex = i;
				}

			}
			index = bestIndex;
			return bestDistance;
		}
	}

}