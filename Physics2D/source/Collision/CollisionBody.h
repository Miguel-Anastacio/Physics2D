#pragma once
#include "Colliders/Collider.h"
#include"../Transform.hpp"
namespace Physics2D
{
	class CollisionBody
	{
	public:
		CollisionBody();

		Collider* GetCollider() const;
		void SetCollider(Collider* collider);
		Transform GetTransform() const;

		void SetTransform(const Transform& trans);
		void SetPosition(const Vector2& pos);
		Vector2 GetPosition() const;

	protected:
		Collider* m_Collider;
		Transform m_Transform;
		

		bool m_bKinematic;
		bool m_bTrigger;	
	};
}

