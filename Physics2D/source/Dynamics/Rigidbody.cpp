#include "Rigidbody.h"

namespace Physics2D
{
	Rigidbody::Rigidbody()
		: CollisionBody()
	{
		m_StaticFriction = 0.2;
		m_DynamicFriction = 0.05;
		
	}

	Rigidbody::Rigidbody(const Material& physMat, const float& gravScale)
	{
		m_Material = physMat;
		gravityScale = gravScale;
	}

	void Rigidbody::Init(const RigidBodyInit& init)
	{
		
		SetForce(init.InitialForce);
		SetVelocity(init.Velocity);
		SetStaticFriction(init.StaticFriction);
		SetDynamicFriction(init.DynamicFriction);

		SetMaterial(init.Material);

		SetIsKinematic(init.Kinematic);
		if (!init.Kinematic)
		{
			SetMass(0);
		}
	}

	void Rigidbody::SetForce(const Vector2& force)
	{
		m_Force = force;
	}

	Vector2 Rigidbody::GetForce() const
	{
		return m_Force;
	}
	void Rigidbody::AddForce(const Vector2& force)
	{
		m_Force += force;
	}

	void Rigidbody::SetVelocity(const Vector2& velocity)
	{
		m_LinearVelocity = velocity;
	}

	Vector2 Rigidbody::GetVelocity() const
	{
		return m_LinearVelocity;
	}

	void Rigidbody::SetMass(const float& mass)
	{
		m_MassData.Mass = mass;
		if (mass == 0)
			m_MassData.InvMass = 0;
		else
			m_MassData.InvMass = 1 / mass;
		
	}

	float Rigidbody::GetMass() const
	{
		return m_MassData.Mass;
	}

	float Rigidbody::GetInvMass() const
	{
		return m_MassData.InvMass;
	}

	MassData Rigidbody::GetMassData() const
	{
		return m_MassData;
	}

	float Rigidbody::GetRestitution() const
	{
		return m_Material.Restitution;
	}

	void Rigidbody::SetRestitution(const float& e)
	{
		m_Material.Restitution = e;
	}

	void Rigidbody::SetGravityScale(const float& grav)
	{
		gravityScale = grav;
	}

	float Rigidbody::GetGravityScale() const
	{
		return gravityScale;
	}

	void Rigidbody::SetMaterial(const Material& mat)
	{
		m_Material = mat;
		m_MassData.Mass = m_Material.Density / m_ColliderShared.get()->CalculateArea(m_Transform);
		m_MassData.InvMass = 1 / m_MassData.Mass;
	}

	Material Rigidbody::GetMaterial() const
	{
		return m_Material;
	}

	void Rigidbody::SetDynamicFriction(const float& dynFriction)
	{
		m_DynamicFriction = dynFriction;
	}

	float Rigidbody::GetDynamicFriction() const
	{
		return m_DynamicFriction;
	}

	void Rigidbody::SetStaticFriction(const float& staFriction)
	{
		m_StaticFriction = staFriction;
	}

	float Rigidbody::GetStaticFriction() const
	{
		return m_StaticFriction;
	}

	
}