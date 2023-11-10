#pragma once
#include "Entity.h"
#include "PhysicsWorld.h"
#include "Circle.h"
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
	std::vector<uint64_t> CleanupEntities();
	void UpdateEntities(float dt);
	void RenderEntities();

	void AddCircle(const sf::Vector2f& pos, float radius);

	std::vector<std::shared_ptr<Physics2D::CollisionBody>>* GetBodies();
	std::vector<Entity> m_Entities;

private:
	std::vector<std::shared_ptr<Physics2D::CollisionBody>> m_Bodies;
	int m_WIDTH = 1920;
	int m_HEIGHT = 1080;
	Physics2D::PhysicsWorld* m_World;
	int count = 0;
};

