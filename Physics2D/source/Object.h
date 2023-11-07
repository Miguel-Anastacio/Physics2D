#pragma once
#include "Utilities.h"
namespace Physics2D
{
	class Object
	{
	public:
		Object(float mass);

		float GetMass();
		Vector2 GetPosition();
		Vector2 GetForce();
		Vector2 GetVelocity();

		void SetForce(const Vector2& force);
		void SetPosition(const Vector2& position);
		void SetPosition(const float& x, const float& y);
		void SetVelocity(const Vector2& velocity);

	private:
		Vector2 m_Position;
		Vector2 m_Velocity;
		Vector2 m_Force;
		float m_Mass;
	};
}

