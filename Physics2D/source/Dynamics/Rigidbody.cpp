#include "Rigidbody.h"

namespace Physics2D
{
	Rigidbody::Rigidbody()
	{
	}

	void Rigidbody::SetForce(const Vector2& force)
	{
		m_Force = force;
	}

	Vector2 Rigidbody::GetForce()
	{
		return m_Force;
	}

	void Rigidbody::SetVelocity(const Vector2& velocity)
	{
		m_LinearVelocity = velocity;
	}

	Vector2 Rigidbody::GetVelocity()
	{
		return m_LinearVelocity;
	}

	void Rigidbody::SetInvMass(const float& mass)
	{
		m_InvMass = mass;
	}

	float Rigidbody::GetMass()
	{
		return m_InvMass;
	}

	void Rigidbody::ApplyForce()
	{
		//SetVelocity(GetVelocity() + )
	}
	
}