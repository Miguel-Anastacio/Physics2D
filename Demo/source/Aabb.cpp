#include "Aabb.h"
#include "Utils.hpp"

Aabb::Aabb(sf::Vector2f pos, Physics2D::Vector2 HalfSize)
	: Entity(pos)
{
	sf::Vector2f size = ToSfVector(HalfSize * 2);
	sf::RectangleShape RectShape(size);
	//RectShape.setOrigin(ToSfVector(HalfSize));
	m_Shape = std::make_shared<sf::RectangleShape>(RectShape);
	m_Collider = std::make_shared<Physics2D::AabbCollider>(HalfSize.X, HalfSize.Y);
	m_Rigidbody->SetColliderShared(m_Collider);
	m_Rigidbody->SetMass(0);
}

//Aabb::Aabb(const sf::Vector2f& pos, Physics2D::Vector2& vel, const Physics2D::Vector2& HalfSize)
//	: Entity(pos, vel)
//{
//
//}

Aabb::Aabb(sf::Vector2f pos, Physics2D::Vector2 HalfSize, const Physics2D::RigidBodyInit& init)
	: Entity(pos)
{
	sf::Vector2f size = ToSfVector(HalfSize * 2);
	sf::RectangleShape RectShape(size);
	//RectShape.setOrigin(ToSfVector(HalfSize));
	m_Shape = std::make_shared<sf::RectangleShape>(RectShape);
	m_Collider = std::make_shared<Physics2D::AabbCollider>(HalfSize.X, HalfSize.Y);
	m_Rigidbody->SetColliderShared(m_Collider);
	//m_Rigidbody->SetIsKinematic(false);
	m_Rigidbody->Init(init);
}

Aabb::Aabb(sf::Vector2f pos, Physics2D::Vector2 HalfSize, const Physics2D::RigidBodyInit& init, sf::Color color)
	: Entity(pos)
{
	sf::Vector2f size = ToSfVector(HalfSize * 2);
	sf::RectangleShape RectShape(size);
	RectShape.setFillColor(color);
	//RectShape.setOrigin(ToSfVector(HalfSize));
	m_Shape = std::make_shared<sf::RectangleShape>(RectShape);
	m_Collider = std::make_shared<Physics2D::AabbCollider>(HalfSize.X, HalfSize.Y);
	m_Rigidbody->SetColliderShared(m_Collider);
	//m_Rigidbody->SetIsKinematic(false);
	m_Rigidbody->Init(init);
}

void Aabb::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(m_RectShape, states);
}
