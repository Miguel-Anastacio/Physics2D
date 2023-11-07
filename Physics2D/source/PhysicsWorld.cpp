#include "PhysicsWorld.h"

Physics2D::PhysicsWorld::PhysicsWorld()
{

}

void Physics2D::PhysicsWorld::Step(float dt)
{
	for (auto& obj : *m_AllObjects)
	{
		obj->SetForce(obj->GetForce() + m_Gravity * obj->GetMass());

		obj->SetVelocity(obj->GetVelocity() + obj->GetForce() / obj->GetMass() * dt);
		obj->SetPosition(obj->GetPosition() + obj->GetVelocity() * dt);

		obj->SetForce(Vector2(0, 0));

	}
}

void Physics2D::PhysicsWorld::SetObjectsReference(std::vector<Object*>* objects)
{
	m_AllObjects = objects;
}

void Physics2D::PhysicsWorld::ApplyGravity(Object* object, const float& dt)
{
	object->SetForce(object->GetForce() + m_Gravity * object->GetMass());

	object->SetVelocity(object->GetVelocity() + object->GetForce() / object->GetMass() * dt);
	object->SetPosition(object->GetPosition() + object->GetVelocity() * dt);

	object->SetForce(Vector2(0, 0));
}
