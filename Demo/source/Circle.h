#pragma once
#include "Entity.h"
#include "Collision/Colliders/CircleCollider.h"

struct Physics2D::RigidBodyInit;
class Circle : public Entity
{
public:
	Circle(sf::Vector2f pos, float radius);
	Circle(sf::Vector2f pos, Physics2D::Vector2 vel, float radius);
	Circle(sf::Vector2f pos, float radius, const Physics2D::RigidBodyInit& init);
	Circle(sf::Vector2f pos, float radius, const Physics2D::RigidBodyInit& init, sf::Color color);

	~Circle();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	sf::CircleShape m_CircleShape;
	std::shared_ptr<Physics2D::CircleCollider> m_Collider = nullptr;

};

