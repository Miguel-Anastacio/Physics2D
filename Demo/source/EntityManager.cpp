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
	m_Entities.emplace_back(entity);	
	m_Bodies.push_back(entity.m_Rigidbody);
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
	/*for (std::vector<Entity>::iterator it = m_Entities.begin(); it != m_Entities.end();)
	{
		if (it->m_Rigidbody->GetPosition().Y > m_HEIGHT || it->m_Rigidbody->GetPosition().X > m_WIDTH)
		{
			it = m_Entities.erase(it);
		}
		else
		{
			it++;
		}
	}
	for (std::vector<std::shared_ptr<Physics2D::CollisionBody>>::iterator it = m_Bodies.begin(); it != m_Bodies.end();)
	{

		if (it->m_Rigidbody->GetPosition().Y > m_HEIGHT || it->GetPosition().X > m_WIDTH)
		{
			it = m_Entities.erase(it);
		}
		else
		{
			it++;
		}
	}*/
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

std::vector<std::shared_ptr<Physics2D::CollisionBody>>* EntityManager::GetBodies()
{
	return &m_Bodies;
}
