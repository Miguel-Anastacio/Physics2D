#include "Aabb.h"
#include "Utils.hpp"

Aabb::Aabb(const sf::Vector2f& pos, const Physics2D::Vector2& HalfSize)
	: Entity(pos)
{
	sf::Vector2f size = ToSfVector(HalfSize * 2);
	sf::RectangleShape RectShape(size);
	//RectShape.setOrigin(ToSfVector(HalfSize));
	m_Shape = std::make_shared<sf::RectangleShape>(RectShape);
	m_Collider = std::make_shared<Physics2D::AabbCollider>(HalfSize.X, HalfSize.Y);
	m_Rigidbody->SetColliderShared(m_Collider);
	
}

Aabb::Aabb(const sf::Vector2f& pos, const Physics2D::Vector2& vel, const Physics2D::Vector2& HalfSize)
	: Entity(pos, vel)
{

}

void Aabb::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//states.transform *= getTransform();
	//target.draw(m_RectShape, states);
}
