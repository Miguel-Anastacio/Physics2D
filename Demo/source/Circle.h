#pragma once
#include "Entity.h"
#include "Collision/Colliders/CircleCollider.h"

class Circle : public Entity
{
public:
	Circle(const sf::Vector2f& pos, const float& radius);
	Circle(const sf::Vector2f& pos, const Physics2D::Vector2& vel, const float& radius);
	~Circle();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	sf::CircleShape m_CircleShape;
	std::shared_ptr<Physics2D::CircleCollider> m_Collider = nullptr;

};

