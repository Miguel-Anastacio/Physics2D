#include "ObjectManager.h"
namespace Physics2D
{
	ObjectManager::ObjectManager()
	{
	}
	std::vector<Object> ObjectManager::GetAllObjects()
	{
		return m_AllObjects;
	}
	/*void ObjectManager::UpdateObjects(float dt)
	{
	}*/
	void ObjectManager::AddObject(const Object& object)
	{
		m_AllObjects.push_back(object);
	}

	void ObjectManager::RemoveObject(const Object& object)
	{
		/*auto it = std::find(m_AllObjects.begin(), m_AllObjects.end(), object);
		if (it == m_AllObjects.end())
			return;
		m_AllObjects.erase(it);*/
	}

	void ObjectManager::CleanupObjects()
	{
		for (auto it = m_AllObjects.begin(); it != m_AllObjects.end(); it++)
		{
			if (it->GetPosition().Y > HEIGHT || it->GetPosition().X > WIDTH)
			{
				m_AllObjects.erase(it);
			}
		}
	}
}