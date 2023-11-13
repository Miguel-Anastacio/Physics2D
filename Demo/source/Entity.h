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

	std::shared_ptr<Physics2D::Rigidbody> GetRigidbody() const;
	virtual void Update(float dt);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	inline std::shared_ptr<sf::Shape> GetShape() { return m_Shape; };
protected:
	
	std::shared_ptr<Physics2D::Rigidbody> m_Rigidbody = nullptr;
	std::shared_ptr<sf::Shape> m_Shape;
};

