#include "CollisionBody.h"
#include "Colliders/AabbCollider.h"
#include "Colliders/CircleCollider.h"
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
		UpdateAabb();
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
	bool CollisionBody::IsKinematic() const
	{
		return m_IsKinematic;
	}
	void CollisionBody::SetIsKinematic(const bool& kin)
	{
		m_IsKinematic = false;
	}
	bool CollisionBody::IsTrigger() const
	{
		return m_IsTrigger;
	}
	void CollisionBody::UpdateAabb()
	{
		if (m_ColliderShared == nullptr)
			return ;
		AabbCollider* col = dynamic_cast<AabbCollider*>(m_ColliderShared.get());
		if (col != nullptr)
		{
			m_BroadPhaseAabb.Centre.X = m_Transform.Position.X + m_ColliderShared->m_Center.X * m_Transform.Scale.X;
			m_BroadPhaseAabb.Centre.Y = m_Transform.Position.Y + m_ColliderShared->m_Center.Y * m_Transform.Scale.Y;
			m_BroadPhaseAabb.HalfSize.X = col->m_HalfWidth * m_Transform.Scale.X;
			m_BroadPhaseAabb.HalfSize.Y = col->m_HalfHeight * m_Transform.Scale.Y;
		}

		CircleCollider* CircleCol = dynamic_cast<CircleCollider*>(m_ColliderShared.get());
		if (CircleCol != nullptr)
		{
			m_BroadPhaseAabb.Centre.X = m_Transform.Position.X + m_ColliderShared->m_Center.X * m_Transform.Scale.X;
			m_BroadPhaseAabb.Centre.Y = m_Transform.Position.Y + m_ColliderShared->m_Center.Y * m_Transform.Scale.Y;
			m_BroadPhaseAabb.HalfSize.X = CircleCol->m_Radius * m_Transform.Scale.X;
			m_BroadPhaseAabb.HalfSize.Y = CircleCol->m_Radius * m_Transform.Scale.Y;

		}
	}
	bool CollisionBody::GetAabb(Aabb& aabb) const
	{
		if (m_ColliderShared == nullptr)
			return false;
		
		aabb = m_BroadPhaseAabb;
		return true;
	}
}