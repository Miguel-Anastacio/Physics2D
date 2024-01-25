#pragma once
#include "Collider.h"
#include <vector>
namespace Physics2D
{
	struct Edge
	{
		Vector2 edgeVector;
		Vector2 normal;

		Edge() {};
		Edge(Vector2 a, Vector2 b) 
		{
			edgeVector = b - a;

			normal = Vector2(edgeVector.Y, -edgeVector.X);
			normal.Normalize();
		};
	};

	class PolygonCollider : public Collider
	{

	public:
		PolygonCollider();
		~PolygonCollider();
		virtual Manifold TestCollision(const Transform& transform, const Collider* collider, const Transform& colliderTransform) const override;
		virtual Manifold TestCollision(const Transform& transform, const CircleCollider* collider, const Transform& colliderTransform) const override;
		virtual Manifold TestCollision(const Transform& transform, const PolygonCollider* collider, const Transform& colliderTransform) const override;
		virtual Manifold TestCollision(const Transform& transform, const AabbCollider* collider, const Transform& colliderTransform) const override;

		float CalculateArea(const Transform& t) const override;
		Vector2 FindFurthestPoint(Vector2 direction) const override;

		inline std::vector<Vector2> GetTransformedVertices() const { return m_TransformedVertices; };
		inline std::vector<Vector2> GetVertices() const { return m_Vertices; };
		void SetVertices(const std::vector<Vector2>& vertices, const Transform& t);
		inline void PushVertice(Vector2 vertex) { m_Vertices.push_back(vertex); };

		void CalculateTransformedVertices(const Transform& t);
		Vector2 FindCenter();
		inline std::vector<Edge> GetEdges() const { return m_Edges; };
	private:
		std::vector<Vector2> m_Vertices;
		std::vector<Vector2> m_TransformedVertices;
		std::vector<Edge> m_Edges;


	};
}
