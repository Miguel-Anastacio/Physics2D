#pragma once
#include "Object.h"
#include "SFML/Graphics.hpp"
class Entity : public sf::Drawable, public sf::Transformable
{
public: 
	Entity(sf::Vector2f pos);
	~Entity();

	virtual void Update(float dt);
	Physics2D::Object* collider = nullptr;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	sf::CircleShape m_Shape;
};

