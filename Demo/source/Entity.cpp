#include "Entity.h"

Entity::Entity(sf::Vector2f pos)
{
	m_Rigidbody = std::make_shared<Physics2D::Rigidbody>();
	m_Rigidbody->SetPosition(Physics2D::Vector2(pos.x, pos.y));
	m_Rigidbody->SetVelocity(Physics2D::Vector2(0, 0));
	m_Rigidbody->SetMass(1.0f);
}
Entity::Entity(sf::Vector2f pos, Physics2D::Vector2 vel)
{
	m_Rigidbody = std::make_shared<Physics2D::Rigidbody>();
	m_Rigidbody->SetPosition(Physics2D::Vector2(pos.x, pos.y));
	m_Rigidbody->SetVelocity(vel);
	m_Rigidbody->SetMass(1.0f);

}
Entity::~Entity()
{
	//if(collider != nullptr)

}

std::shared_ptr<Physics2D::Rigidbody> Entity::GetRigidbody() const
{
	return m_Rigidbody;
}

void Entity::Update(float dt)
{
	setPosition(m_Rigidbody->GetPosition().X, m_Rigidbody->GetPosition().Y);
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	if(m_Shape != nullptr)
		target.draw(*m_Shape, states);
}

