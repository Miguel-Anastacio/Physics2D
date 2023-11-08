#include "Entity.h"
#include "Collision/Colliders/CircleCollider.h"


Entity::Entity(const sf::Vector2f& pos)
{
	m_Rigidbody = std::make_shared<Physics2D::Rigidbody>();
	m_Rigidbody->SetPosition(Physics2D::Vector2(pos.x, pos.y));
	m_Rigidbody->SetVelocity(Physics2D::Vector2(0, 50));
	m_Rigidbody->SetMass(1.0f);
	
	m_Shape.setRadius(50.0f);

	m_Collider = std::make_shared<Physics2D::CircleCollider>(50.0f);
	m_Rigidbody->SetCollider(m_Collider.get());
}
Entity::Entity(const sf::Vector2f& pos, const Physics2D::Vector2 vel)
{
	m_Rigidbody = std::make_shared<Physics2D::Rigidbody>();
	m_Rigidbody->SetPosition(Physics2D::Vector2(pos.x, pos.y));
	m_Rigidbody->SetVelocity(vel);
	m_Rigidbody->SetMass(1.0f);

	m_Shape.setRadius(50.0f);

	m_Collider = std::make_shared<Physics2D::CircleCollider>(50.0f);
	m_Rigidbody->SetCollider(m_Collider.get());

}
Entity::~Entity()
{
	//if(collider != nullptr)

}

void Entity::Update(float dt)
{
	setPosition(m_Rigidbody->GetPosition().X, m_Rigidbody->GetPosition().Y);
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(m_Shape, states);
}
