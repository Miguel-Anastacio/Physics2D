#pragma once

namespace Physics2D {

	const int WIDTH = 1500;
	const int HEIGHT = 1100;
	struct Vector3
	{
		float X, Y, Z;
		Vector3(float x, float y, float z) : X(x), Y(y), Z(z) {};
		Vector3() 
		{
			X = 0;
			Y = 0;
			Z = 0;
		};

		Vector3 operator+(const Vector3& other) const
		{
			return Vector3(this->X + other.X, this->Y + other.Y, this->Z + other.Z);
		}
	};
	struct Vector2
	{
		float X, Y;
		Vector2(float x, float y) : X(x), Y(y) {};
		Vector2()
		{
			X = 0;
			Y = 0;
		};

		Vector2 operator+(const Vector2& other) const
		{
			return Vector2(this->X + other.X, this->Y + other.Y);
		}

		Vector2 operator*(const float& scalar) const
		{
			return Vector2(this->X * scalar, this->Y * scalar);
		}
		Vector2 operator/(const float& scalar) const
		{
			return Vector2(this->X / scalar, this->Y / scalar);
		}
	};

	struct CollisionPoints
	{
		Vector2 A;
		Vector2 B;
		Vector2 Normal;
		float Depth;
		bool HasCollision;
	};

	struct Transform
	{
		Vector2 Position;
		Vector2 Scale;
		
	};
}