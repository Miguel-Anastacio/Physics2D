#pragma once
#include "Colliders/Collider.h"
#include"../Transform.hpp"
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
	protected:
		std::shared_ptr<Collider> m_ColliderShared;
		Transform m_Transform;
		
		uint64_t ID;
		bool m_bKinematic;
		bool m_bTrigger;	
	};

}

