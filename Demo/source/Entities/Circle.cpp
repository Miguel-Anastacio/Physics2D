#include "Circle.h"

Circle::Circle(sf::Vector2f pos, float radius)
	: Entity(pos)
{
	m_CircleShape.setRadius(radius);
	m_CircleShape.setOrigin(radius, radius);
	m_Shape = std::make_shared<sf::CircleShape>(m_CircleShape);
	//*m_Shape = m_CircleShape;


	m_Collider = std::make_shared<Physics2D::CircleCollider>(radius);
	m_Rigidbody->SetColliderShared(m_Collider);


}

Circle::Circle(sf::Vector2f pos, Physics2D::Vector2 vel, float radius)
	: Entity(pos, vel)
{
	//m_Shape = std::make_shared<sf::CircleShape>(radius);

	m_Collider = std::make_shared<Physics2D::CircleCollider>(radius);
	m_Rigidbody->SetColliderShared(m_Collider);
}

Circle::Circle(sf::Vector2f pos, float radius, const Physics2D::RigidBodyInit& init)
	: Entity(pos)
{
	m_CircleShape.setRadius(radius * init.trans.Scale.X);
	m_CircleShape.setOrigin(radius * init.trans.Scale.X, radius * init.trans.Scale.X);
	m_Shape = std::make_shared<sf::CircleShape>(m_CircleShape);
	//*m_Shape = m_CircleShape;


	m_Collider = std::make_shared<Physics2D::CircleCollider>(radius);
	m_Rigidbody->SetColliderShared(m_Collider);
	m_Rigidbody->Init(init);
}

Circle::Circle(sf::Vector2f pos, float radius, const Physics2D::RigidBodyInit& init, sf::Color color)
	: Entity(pos)
{
	m_CircleShape.setRadius(radius * init.trans.Scale.X);
	m_CircleShape.setOrigin(radius * init.trans.Scale.X, radius * init.trans.Scale.X);

	m_CircleShape.setFillColor(color);
	m_Shape = std::make_shared<sf::CircleShape>(m_CircleShape);
	//*m_Shape = m_CircleShape;


	m_Collider = std::make_shared<Physics2D::CircleCollider>(radius);
	m_Rigidbody->SetColliderShared(m_Collider);
	m_Rigidbody->Init(init);
}

Circle::~Circle()
{

}

void Circle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(m_CircleShape, states);
}
