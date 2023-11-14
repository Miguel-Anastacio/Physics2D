#pragma once
#include "Colliders/Collider.h"
#include"../Transform.hpp"
#include "SimpleCollisionDetection.h"
#include <memory>
namespace Physics2D
{
	class CollisionBody
	{
	public:
		CollisionBody();
		CollisionBody(int id);

		std::shared_ptr<Collider> GetColliderShared() const;
		void SetColliderShared(std::shared_ptr<Collider> collider);
		Transform GetTransform() const;

		void SetTransform(const Transform& trans);
		void SetPosition(const Vector2& pos);
		Vector2 GetPosition() const;

		void SetID(int id);
		uint64_t GetID();

		bool IsKinematic() const;
		inline void SetIsKinematic(bool kin) {	m_IsKinematic = kin;}
		bool IsTrigger() const;

		bool GetAabb(Aabb& aabb) const;
		void UpdateAabb();

		virtual void Dummy() {};

		bool operator!=(const CollisionBody& other) const;
		
	protected:
		uint64_t ID;
		std::shared_ptr<Collider> m_ColliderShared;
		Transform m_Transform;
		Aabb m_BroadPhaseAabb;
		bool m_IsKinematic = true;
		bool m_IsTrigger = false;

	};

}

