#include "Circle.h"

Circle::Circle(const sf::Vector2f& pos, const float& radius)
	: Entity(pos)
{
	m_CircleShape.setRadius(radius);
	//m_CircleShape.setOrigin(radius, radius);
	m_Shape = std::make_shared<sf::CircleShape>(m_CircleShape);


	m_Collider = std::make_shared<Physics2D::CircleCollider>(radius);
	m_Rigidbody->SetColliderShared(m_Collider);


}

Circle::Circle(const sf::Vector2f& pos, const Physics2D::Vector2& vel, const float& radius)
	: Entity(pos, vel)
{
	m_Shape = std::make_shared<sf::CircleShape>(radius);

	m_Collider = std::make_shared<Physics2D::CircleCollider>(radius);
	m_Rigidbody->SetColliderShared(m_Collider);
}

Circle::~Circle()
{

}

void Circle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//states.transform *= getTransform();
	//target.draw(m_CircleShape, states);
}
