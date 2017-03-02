#include "stdafx.h"
#include "Vec3.h"

namespace Glml
{
	Vec3::Vec3()
		: x(0.0f), y(0.0f), z(0.0f)
	{
	}

	Vec3::Vec3(float x, float y, float z)
		: x(x), y(y), z(z)
	{
	}

	float Vec3::operator[](unsigned i) const
	{
		if (i == 0) return x;
		if (i == 1) return y;
		return z;
	}

	float& Vec3::operator[](unsigned i)
	{
		if (i == 0) return x;
		if (i == 1) return y;
		return z;
	}

	void Vec3::operator+= (const Vec3& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
	}

	void Vec3::operator-= (const Vec3& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
	}

	void Vec3::operator*= (float k)
	{
		x *= k;
		y *= k;
		z *= k;
	}

	void Vec3::operator/= (float k)
	{
		x /= k;
		y /= k;
		z /= k;
	}

	Vec3 Vec3::operator+ (const Vec3& rhs) const
	{
		return Vec3(x + rhs.x, y + rhs.y, z + rhs.z);
	}

	Vec3 Vec3::operator- (const Vec3& rhs) const
	{
		return Vec3(x - rhs.x, y - rhs.y, z - rhs.z);
	}

	Vec3 Vec3::operator* (float k) const
	{
		return Vec3(x * k, y * k, z * k);
	}

	Vec3 Vec3::operator/ (float k) const
	{
		return Vec3(x / k, y / k, z / k);
	}

	void Vec3::AddScaledVector(const Vec3& v, float scale)
	{
		x += v.x * scale;
		y += v.y * scale;
		z += v.z * scale;
	}

	void Vec3::Set(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	void Vec3::Clear()
	{
		Set(0.0f, 0.0f, 0.0f);
	}

	float Vec3::Magnitude()
	{
		return sqrtf((x * x) + (y * y) + (z * z));
	}

	float Vec3::MagintudeSq()
	{
		return (x * x) + (y * y) + (z * z);
	}

	void Vec3::Normalize()
	{
		float invMagnitude = 1.0f / Magnitude();
		x *= invMagnitude;
		y *= invMagnitude;
		z *= invMagnitude;
	}

	void Vec3::Inverse()
	{
		x = -x;
		y = -y;
		z = -z;
	}

	Vec3 Vec3::CROSS(const Vec3& v1, const Vec3& v2)
	{
		return Vec3(
			(v1.y * v2.z) - (v1.z * v2.y),
			(v1.z * v2.x) - (v1.x * v2.z),
			(v1.x * v2.y) - (v1.y * v2.x)
		);
	}

	float Vec3::DOT(const Vec3& v1, const Vec3& v2)
	{
		return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
	}

	Vec3 Vec3::COMPONENT_PRODUCT(const Vec3& v1, const Vec3& v2)
	{
		return Vec3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
	}

	Vec3 Vec3::LERP(const Vec3& v1, const Vec3& v2, float interpolation)
	{
		return v1 + (v2 - v1) * interpolation;
	}

	Vec3 Vec3::INVERT(const Vec3& v)
	{
		return Vec3(-v.x, -v.y, -v.z);
	}

	float Vec3::DISTANCE(const Vec3& v1, const Vec3& v2)
	{
		return sqrtf(
			(v1.x - v2.x) * (v1.x - v2.x) +
			(v1.y - v2.y) * (v1.y - v2.y) +
			(v1.z - v2.z) * (v1.z - v2.z)
		);
	}
}