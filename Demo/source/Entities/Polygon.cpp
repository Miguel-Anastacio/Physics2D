#include "Polygon.h"
#include "Collision/Colliders/PolygonCollider.h"
#include "../Utils.hpp"
Polygon::Polygon(sf::Vector2f pos, const Physics2D::RigidBodyInit& init, sf::Color color, int VertexCount)
	: Entity(pos)
{
	m_PolygonShape.setPointCount(5);
	// figure out center of polygon
	//m_PolygonShape.setOrigin(radius * init.trans.Scale.X, radius * init.trans.Scale.X);
	sf::Vector2f VertexA = sf::Vector2f(0, 0);
	sf::Vector2f VertexB = sf::Vector2f(100, 0);
	sf::Vector2f VertexC = sf::Vector2f(100, 100);
	sf::Vector2f VertexD = sf::Vector2f(50, 150);
	sf::Vector2f VertexE = sf::Vector2f(0, 100);

	m_PolygonShape.setFillColor(color);
	//*m_Shape = m_CircleShape;
	m_PolygonShape.setPoint(0, VertexA);
	m_PolygonShape.setPoint(1, VertexB);
	m_PolygonShape.setPoint(2, VertexC);
	m_PolygonShape.setPoint(3, VertexD);
	m_PolygonShape.setPoint(4, VertexE);

	m_Collider = std::make_shared<Physics2D::PolygonCollider>();
	m_Collider->PushVertice(ToEngineVector(VertexA));
	m_Collider->PushVertice(ToEngineVector(VertexB));
	m_Collider->PushVertice(ToEngineVector(VertexC));
	m_Collider->PushVertice(ToEngineVector(VertexD));
	m_Collider->PushVertice(ToEngineVector(VertexE));
	m_Collider->CalculateTransformedVertices(m_Rigidbody->GetTransform());

	m_Rigidbody->SetColliderShared(m_Collider);

	m_PolygonShape.setOrigin(ToSfVector(m_Collider->FindCenter()));
	m_Shape = std::make_shared<sf::ConvexShape>(m_PolygonShape);

	m_Rigidbody->Init(init);
}
