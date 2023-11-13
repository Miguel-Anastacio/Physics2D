#include "EntityManager.h"
#include "Circle.h"
EntityManager::EntityManager()
{

}

EntityManager::EntityManager(int width, int height)
	: m_WIDTH(width), m_HEIGHT(height)
{

}

EntityManager::~EntityManager()
{
	/*for (auto& ent : m_Entities)
	{
		if (ent.m_Rigidbody != nullptr)
			delete ent.m_Rigidbody;
	}*/
}

std::vector<Entity> EntityManager::GetEntities()
{
	return m_Entities;
}

void EntityManager::AddEntity(const Entity& entity)
{
	entity.GetRigidbody()->SetID(count);
	m_Entities.push_back(entity);
	count++;
	//m_Bodies.emplace_back(entity.m_Rigidbody);
}

void EntityManager::RemoveEntity(const Entity& entity)
{
	/*auto it = std::find(m_Entities.begin(), m_Entities.end(), entity);
	if (it == m_Entities.end())
		return;
	m_Entities.erase(it);
}*/
}
std::vector<uint64_t> EntityManager::CleanupEntities()
{
	std::vector<uint64_t> ids;
	for (std::vector<Entity>::iterator it = m_Entities.begin(); it != m_Entities.end();)
	{
		if (it->GetRigidbody()->GetPosition().Y > m_HEIGHT || it->GetRigidbody()->GetPosition().X > m_WIDTH)
		{
			ids.push_back(it->GetRigidbody()->GetID());
			it = m_Entities.erase(it);
		}
		else
		{
			it++;
		}
	}
	return ids;

}

void EntityManager::UpdateEntities(float dt)
{
	for (auto& ent : m_Entities)
	{
		ent.Update(dt);
	}
	//CleanupEntities();
}

void EntityManager::RenderEntities()
{
	
}

void EntityManager::AddCircle(const sf::Vector2f& pos, float radius)
{
	//Circle circle = Circle(pos, radius);
	//m_Entities.emplace_back(circle);
	//m_Bodies.emplace_back(circle.GetRigidbody());
}

std::vector<std::shared_ptr<Physics2D::CollisionBody>>* EntityManager::GetBodies()
{
	return &m_Bodies;
}
