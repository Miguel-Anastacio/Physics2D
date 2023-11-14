#pragma once
#include "../Collision/CollisionBody.h"
namespace Physics2D
{

	struct MassData
	{
		float Mass;
		float InvMass;

		// for rotations
		float Inertia;
		float InvInertia;
	};

	struct Material
	{
		float Density = 100.0f;
		float Restitution = 0.5f;
	};
	struct RigidBodyInit
	{
		Material Material;
		Vector2 Velocity;
		Vector2 InitialForce;
		bool Kinematic = true;
		float StaticFriction = 0.3;
		float DynamicFriction = 0.1;
		float GravityScale = 1.0f;

		float InitialTorque = 0.0f;
		float AngularVelocity = 0.0f;
	};

	class Rigidbody : public CollisionBody
	{

	public:
		Rigidbody();
		Rigidbody(const Material& physMat, const float& gravScale);

		void Init(const RigidBodyInit& init);

		void SetForce(const Vector2& force);
		Vector2 GetForce() const;
		void AddForce(const Vector2& force);

		void SetVelocity(const Vector2& velocity);
		Vector2 GetVelocity() const;

		// angular velocity and torque setters and getters

		void SetMass(const float& mass);
		float GetMass() const;
		float GetInvMass() const;
		MassData GetMassData() const;

		float GetRestitution() const;
		void SetRestitution(const float& e);

		//void SetVelocity(const Vector2& velocity);
		void SetGravityScale(const float& grav);
		float GetGravityScale() const;

		void SetMaterial(const Material& mat);
		Material GetMaterial()const ;

		void SetDynamicFriction(const float& dynFriction);
		float GetDynamicFriction() const;

		void SetStaticFriction(const float& staFriction);
		float GetStaticFriction() const;
	private:
		Vector2 m_LinearVelocity;
		float m_AngularVelocity = 0;
		Vector2 m_Force;
		// t = F x r , 
		//where r is a vector from the centre of the rb to a point of the rb
		// in 2D torque is described as a float since it only has a "z" component
		float m_Torque;

		MassData m_MassData;
		Material m_Material;

		// friction when an object is in motion
		float m_DynamicFriction;
		// friction when an object is at rest
		float m_StaticFriction;
		float gravityScale = 1.0f;
	};
}

