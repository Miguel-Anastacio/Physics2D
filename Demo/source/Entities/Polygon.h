#pragma once
#include "Entity.h"
class Polygon : public Entity
{
public:
	Polygon(sf::Vector2f pos, const Physics2D::RigidBodyInit& init, sf::Color color, int VertexCount);

private:
	sf::ConvexShape m_PolygonShape;
	std::shared_ptr<Physics2D::PolygonCollider> m_Collider = nullptr;
};

