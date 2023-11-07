#include "Entity.h"

Entity::Entity(sf::Vector2f pos)
{
	collider = new Physics2D::Object(1.f);
	collider->SetPosition(pos.x, pos.y);
	collider->SetVelocity(Physics2D::Vector2(300, 50));
	m_Shape.setRadius(50.0f);
}
Entity::~Entity()
{
	//if(collider != nullptr)
		
}

void Entity::Update(float dt)
{
	setPosition(collider->GetPosition().X, collider->GetPosition().Y);
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(m_Shape, states);
}
