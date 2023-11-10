#include "CollisionBody.h"
namespace Physics2D
{
	CollisionBody::CollisionBody()
	{
		m_Transform.Scale = Vector2(1, 1);
		m_Transform.Position = Vector2(0, 0);
		m_Transform.Rotation = 0;
	}

	CollisionBody::CollisionBody(int id)
	{
		m_Transform.Scale = Vector2(1, 1);
		m_Transform.Position = Vector2(0, 0);
		m_Transform.Rotation = 0;
		ID = id;
	}
	
	std::shared_ptr<Collider> CollisionBody::GetColliderShared() const
	{
		return m_ColliderShared;
	}
	
	void CollisionBody::SetColliderShared(std::shared_ptr<Collider> collider)
	{
		m_ColliderShared = collider;
	}
	Transform CollisionBody::GetTransform() const
	{
		return m_Transform;
	}
	void CollisionBody::SetTransform(const Transform& trans)
	{
		m_Transform = trans;
	}
	void CollisionBody::SetPosition(const Vector2& pos)
	{
		m_Transform.Position = pos;
	}
	Vector2 CollisionBody::GetPosition() const
	{
		return m_Transform.Position;
	}
	void CollisionBody::SetID(int id)
	{
		ID = id;
	}
	uint64_t CollisionBody::GetID()
	{
		return ID;
	}
}