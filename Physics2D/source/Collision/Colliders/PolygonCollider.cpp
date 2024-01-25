#include "PolygonCollider.h"
#include "../ManifoldGeneration.h"
namespace Physics2D
{
	PolygonCollider::PolygonCollider()
	{

	}

	PolygonCollider::~PolygonCollider()
	{
		
	}

	Manifold PolygonCollider::TestCollision(const Transform& transform, const Collider* collider, const Transform& colliderTransform) const
	{
		return collider->TestCollision(colliderTransform, this, transform);
	}

	Manifold PolygonCollider::TestCollision(const Transform& transform, const CircleCollider* collider, const Transform& colliderTransform) const
	{
		return detection::FindCirclePolygonManifold(colliderTransform, collider, transform, this);
	}

	Manifold PolygonCollider::TestCollision(const Transform& transform, const PolygonCollider* collider, const Transform& colliderTransform) const
	{
		return detection::FindPolygonPolygonManifold(transform, this, colliderTransform, collider);
	}

	Manifold PolygonCollider::TestCollision(const Transform& transform, const AabbCollider* collider, const Transform& colliderTransform) const
	{
		return detection::FindAabbPolygonManifold(colliderTransform, collider, transform, this);
	}

	float PolygonCollider::CalculateArea(const Transform& t) const
	{
		return 0.0f;
	}

	Vector2 PolygonCollider::FindFurthestPoint(Vector2 direction) const
	{
		Vector2  maxPoint;
		float maxDistance = -FLT_MAX;
		for (auto& vertex : m_TransformedVertices)
		{

			float distance = vertex.Dot(direction);
			if (distance > maxDistance) 
			{
				maxDistance = distance;
				maxPoint = vertex;
			}
		}
		return maxPoint;
	}

	void PolygonCollider::SetVertices(const std::vector<Vector2>& vertices, const Transform& t)
	{
		m_Vertices = vertices;
		for (auto& vert : m_Vertices)
		{
			m_TransformedVertices.push_back(vert.Scale(t.Scale));
		}
	}

	void PolygonCollider::CalculateTransformedVertices(const Transform& t)
	{
		for (auto& vert : m_Vertices)
		{
			m_TransformedVertices.push_back(vert.Scale(t.Scale));

		}

		for (int i = 0; i < m_TransformedVertices.size(); i++)
		{
			if (i + 1 > m_TransformedVertices.size())
			{
				m_Edges.emplace_back(m_TransformedVertices[i], m_TransformedVertices[0]);
			}
			else
			{
				m_Edges.emplace_back(m_TransformedVertices[i], m_TransformedVertices[i+1]);
			}
		}
	}

	Vector2 PolygonCollider::FindCenter()
	{
		Vector2 center;
		float sumX = 0;
		float sumY = 0;
		for (const auto& vert : m_TransformedVertices)
		{
			sumX += vert.X;
			sumY += vert.Y;
		}

		return Vector2(sumX / m_TransformedVertices.size(), sumY / m_TransformedVertices.size());
	}


	/*CollisionPoints BoxCollider::TestCollisionCircle(const Transform* transform, const CircleShape* cirle, const Transform* cirlceTransform)
	{

		return CollisionPoints();
	}*/
}