#pragma once
#include "Entity.h"
#include "PhysicsWorld.h"
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

	std::vector<std::shared_ptr<Physics2D::CollisionBody>>* GetBodies();

private:
	std::vector<Entity> m_Entities;
	std::vector<std::shared_ptr<Physics2D::CollisionBody>> m_Bodies;
	int m_WIDTH = 1920;
	int m_HEIGHT = 1080;
	Physics2D::PhysicsWorld* m_World;
};

