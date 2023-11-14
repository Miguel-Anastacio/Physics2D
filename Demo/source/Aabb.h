#pragma once
#include "Entity.h"
#include "Collision/Colliders/AabbCollider.h"

class Aabb : public Entity
{
public:
	Aabb(sf::Vector2f pos, Physics2D::Vector2 HalfSize);
	Aabb(sf::Vector2f pos, Physics2D::Vector2 HalfSize, const Physics2D::RigidBodyInit& init);
	Aabb(sf::Vector2f pos, Physics2D::Vector2 HalfSize, const Physics2D::RigidBodyInit& init, sf::Color color);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	sf::RectangleShape m_RectShape;
	std::shared_ptr<Physics2D::AabbCollider> m_Collider = nullptr;
};

