#pragma once
#include "Entity.h"
class EntityManager
{
public:
	EntityManager();
	EntityManager(int width, int height);
	~EntityManager();
	//void UpdateObjects(float dt);
	std::vector<Entity> GetEntities();
	void AddEntity(const Entity& entity);
	void RemoveEntity(const Entity& entity);
	void CleanupEntities();
	void UpdateEntities(float dt);
	void RenderEntities();

	std::vector<Physics2D::Object*>* GetColliders();

private:
	std::vector<Entity> m_Entities;
	std::vector<Physics2D::Object*> m_Colliders;
	int m_WIDTH = 1920;
	int m_HEIGHT = 1080;
};

