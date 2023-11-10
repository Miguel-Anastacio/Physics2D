#include "Entity.h"

Entity::Entity(const sf::Vector2f& pos)
{
	m_Rigidbody = std::make_shared<Physics2D::Rigidbody>();
	m_Rigidbody->SetPosition(Physics2D::Vector2(pos.x, pos.y));
	m_Rigidbody->SetVelocity(Physics2D::Vector2(0, 50));
	m_Rigidbody->SetInvMass(1.0f);
}
Entity::Entity(const sf::Vector2f& pos, const Physics2D::Vector2 vel)
{
	m_Rigidbody = std::make_shared<Physics2D::Rigidbody>();
	m_Rigidbody->SetPosition(Physics2D::Vector2(pos.x, pos.y));
	m_Rigidbody->SetVelocity(vel);
	m_Rigidbody->SetInvMass(1.0f);

}
Entity::~Entity()
{
	//if(collider != nullptr)

}

std::shared_ptr<Physics2D::Rigidbody> Entity::GetRigidbody()
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
	target.draw(*m_Shape, states);
}

