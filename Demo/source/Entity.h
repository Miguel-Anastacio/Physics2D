#pragma once
//#include <Collision/CollisionBody.h>
#include <Dynamics/Rigidbody.h>
#include "SFML/Graphics.hpp"
#include <memory>
class Entity : public sf::Drawable, public sf::Transformable
{
public: 
	Entity(const sf::Vector2f& pos);
	Entity(const sf::Vector2f& pos, const Physics2D::Vector2 vel);
	~Entity();

	virtual void Update(float dt);
	std::shared_ptr<Physics2D::Rigidbody> m_Rigidbody = nullptr;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	sf::CircleShape m_Shape;
	std::shared_ptr<Physics2D::CircleCollider> m_Collider = nullptr;
};

