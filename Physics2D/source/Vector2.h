#pragma once
#include <cmath>
#include <iostream>
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
		bool operator==(const Vector2& other) const
		{
			if (X == other.X && Y == other.Y)
				return true;
			
			return false;
		}
		void operator+=(const Vector2& other) 
		{
			X += other.X;
			Y += other.Y;
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
			if (mag == 0)
				mag = 1.0f;
			return *this / mag;
		}
		void Normalize() 
		{
			float mag = Magnitude();
			if (mag == 0)
				mag = 1.0f;
			*this = *this / mag;
		}

		static Vector2 Normalized(Vector2 vector) 
		{
			float mag = vector.Magnitude();
			if (mag == 0)
				mag = 1.0f;
			return vector / mag;
		}
		float Dot(const Vector2& other) const
		{
			return X * other.X + Y * other.Y;
		}

		void Print() const
		{
			std::cout << "(" << X << "," << Y << ")";
		}

		Vector2 Scale(const Vector2& scale) const
		{
			return Vector2( X * scale.X, Y * scale.Y);
		}

		float Cross(Vector2 other) const
		{
			return (X * other.Y) - (Y * other.X);
		}

		static Vector2 TripleProduct(Vector2 a, Vector2 b, Vector2 c)
		{
			return Vector2(a.Y * (b.Cross(c)), a.X * (c.Cross(b)));
		}
	};

	struct Matrix2x2
	{
		union 
		{
			struct
			{
				float m00, m01;
				float m10, m11;
			};
			struct 
			{
				Vector2 xCol;
				Vector2 yCol;
			};
		};
	};

	/*Vector2 operator*(const float& scalar, const Vector2& vector)
	{
		return Vector2(vector.X / scalar, vector.Y / scalar);
	}*/
	
}