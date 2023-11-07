#pragma once
#include "ObjectManager.h"
namespace Physics2D
{
	class PhysicsWorld
	{
	public:
		PhysicsWorld();
		void Step(float dt);

		void SetObjectsReference(std::vector<Object*>* objects);

	private:

		void ApplyGravity(Object* object, const float&dt);

		//ObjectManager m_ObjectManager;
		std::vector<Object*>* m_AllObjects = NULL;
		Vector2 m_Gravity = Vector2(0, 98.f);


	};
}
