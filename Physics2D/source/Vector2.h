#pragma once
#include <cmath>
namespace Physics2D 
{
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
		Vector2 operator-(const Vector2& other) const
		{
			return Vector2(this->X - other.X, this->Y - other.Y);
		}
		Vector2 operator*(const float& scalar) const
		{
			return Vector2(this->X * scalar, this->Y * scalar);
		}
		Vector2 operator/(const float& scalar) const
		{
			return Vector2(this->X / scalar, this->Y / scalar);
		}

		float Magnitude() const
		{
			return sqrtf(X*X + Y*Y);
		}
		float MagnitudeSqr() const
		{
			return (X * X) + (Y*Y);
		}

		Vector2 Normalized() const
		{
			float mag = Magnitude();
			return *this / mag;
		}

		float Dot(const Vector2& other)
		{
			return X * other.X + Y * other.Y;
		}

	};
	
}