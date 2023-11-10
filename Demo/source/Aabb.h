#pragma once
#include "Entity.h"
#include "Collision/Colliders/AabbCollider.h"

class Aabb : public Entity
{
public:
	Aabb(const sf::Vector2f& pos, const Physics2D::Vector2& HalfSize);
	Aabb(const sf::Vector2f& pos, const Physics2D::Vector2& vel, const Physics2D::Vector2& HalfSize);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	sf::RectangleShape m_RectShape;
	std::shared_ptr<Physics2D::AabbCollider> m_Collider = nullptr;
};

