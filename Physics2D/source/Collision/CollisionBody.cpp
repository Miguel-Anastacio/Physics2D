#include "CollisionBody.h"
namespace Physics2D
{
	CollisionBody::CollisionBody()
	{
		m_Transform.Scale = Vector2(1, 1);
		m_Transform.Position = Vector2(0, 0);
		m_Transform.Rotation = 0;
	}
	Collider* CollisionBody::GetCollider() const
	{
		return m_Collider;
	}
	void CollisionBody::SetCollider(Collider* collider)
	{
		m_Collider = collider;
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
}