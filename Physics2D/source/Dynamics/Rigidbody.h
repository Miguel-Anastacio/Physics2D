#pragma once
#include "../Collision/CollisionBody.h"
namespace Physics2D
{
	class Rigidbody : public CollisionBody
	{
	public:
		Rigidbody();
		void SetForce(const Vector2& force);
		Vector2 GetForce();
		void SetVelocity(const Vector2& velocity);
		Vector2 GetVelocity();
		void SetMass(const float& mass);
		float GetMass();

		void ApplyForce();
		//void SetVelocity(const Vector2& velocity);

	private:
		Vector2 m_LinearVelocity;
		float m_AngularVelocity;
		Vector2 m_Force;
		// t = F x r , 
		//where r is a vector from the centre of the rb to a point of the rb
		// in 2D torque is described as a float since it only has a "z" component
		float m_Torque;

		float m_Mass;
	};
}

