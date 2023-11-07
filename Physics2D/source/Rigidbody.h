#pragma once
#include "Utilities.h"
namespace Physics2D
{
	class Rigidbody
	{
		Transform m_Transform;

		Vector2 m_LinearVelocity;
		float m_AngularVelocity;

		Vector2 m_Force;
		float m_Torque;
	};
}

