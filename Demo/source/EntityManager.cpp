#include "EntityManager.h"

EntityManager::EntityManager()
{

}

EntityManager::EntityManager(int width, int height)
	: m_WIDTH(width), m_HEIGHT(height)
{

}

EntityManager::~EntityManager()
{
	for (auto& ent : m_Entities)
	{
		if (ent.collider != nullptr)
			delete ent.collider;
	}
}

std::vector<Entity> EntityManager::GetEntities()
{
	return m_Entities;
}

void EntityManager::AddEntity(const Entity& entity)
{
	m_Entities.push_back(entity);	
	m_Colliders.push_back(entity.collider);
}

void EntityManager::RemoveEntity(const Entity& entity)
{
	/*auto it = std::find(m_Entities.begin(), m_Entities.end(), entity);
	if (it == m_Entities.end())
		return;
	m_Entities.erase(it);
}*/
}
void EntityManager::CleanupEntities()
{
	for (std::vector<Entity>::iterator it = m_Entities.begin(); it != m_Entities.end();)
	{
		if (it->collider->GetPosition().Y > m_HEIGHT || it->collider->GetPosition().X > m_WIDTH)
		{
			it = m_Entities.erase(it);
		}
		else
		{
			it++;
		}
	}
}

void EntityManager::UpdateEntities(float dt)
{
	for (auto& ent : m_Entities)
	{
		ent.Update(dt);
	}
	CleanupEntities();
}

void EntityManager::RenderEntities()
{
	
}

std::vector<Physics2D::Object*>* EntityManager::GetColliders()
{
	return &m_Colliders;
}
