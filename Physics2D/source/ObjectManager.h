#pragma once
#include "Object.h"
#include <vector>
namespace Physics2D {

	class ObjectManager
	{
	public:
		ObjectManager();
		//void UpdateObjects(float dt);
		std::vector<Object> GetAllObjects();
		void AddObject(const Object& object);
		void RemoveObject(const Object& object);
		void CleanupObjects();
	private:
		std::vector<Object> m_AllObjects;

	};
}

