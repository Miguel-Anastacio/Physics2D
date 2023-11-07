#pragma once

namespace Physics2D {

	struct Vector3
	{
		float X, Y, Z;
		Vector3(float x, float y, float z) : X(x), Y(y), Z(z) {};

		Vector3 operator+(const Vector3& other) const
		{
			return Vector3(this->X + other.X, this->Y + other.Y, this->Z + other.Z);
		}
	};
}