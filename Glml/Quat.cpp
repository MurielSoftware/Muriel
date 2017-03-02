#include "stdafx.h"
#include "Quat.h"
#include "Mat4x4.h"
#include "Vec3.h"

namespace Glml
{
	Quat::Quat()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
		w = 0.0f;
	}

	Quat::Quat(float w, float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	void Quat::operator+= (const Quat& rhs)
	{
		w += rhs.w;
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
	}

	void Quat::operator-= (const Quat& rhs)
	{
		w -= rhs.w;
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
	}

	void Quat::operator*= (const Quat& rhs)
	{
		//Quat tmp(
		//	(w * rhs.w) - (x * rhs.x) - (y * rhs.y) - (z * rhs.z),
		//	(w * rhs.x) + (x * rhs.w) - (y * rhs.z) + (z * rhs.y),
		//	(w * rhs.y) + (x * rhs.z) + (y * rhs.w) - (z * rhs.x),
		//	(w * rhs.z) - (x * rhs.y) + (y * rhs.x) + (z * rhs.w));
		Quat tmp(
			(w * rhs.w) - (x * rhs.x) - (y * rhs.y) - (z * rhs.z),
			(w * rhs.x) + (x * rhs.w) + (y * rhs.z) - (z * rhs.y),
			(w * rhs.y) - (x * rhs.z) + (y * rhs.w) + (z * rhs.x),
			(w * rhs.z) + (x * rhs.y) - (y * rhs.x) + (z * rhs.w)
		);
		*this = tmp;
	}

	void Quat::operator*= (float k)
	{
		w *= k;
		x *= k;
		y *= k;
		z *= k;
	}

	void Quat::operator/= (float k)
	{
		w /= k;
		x /= k;
		y /= k;
		z /= k;
	}

	Quat Quat::operator+ (const Quat& rhs) const
	{
		Quat tmp(*this);
		tmp += rhs;
		return tmp;
	}

	Quat Quat::operator- (const Quat& rhs) const
	{
		Quat tmp(*this);
		tmp -= rhs;
		return tmp;
	}

	Quat Quat::operator* (const Quat& rhs) const
	{
		Quat tmp(*this);
		tmp *= rhs;
		return tmp;
	}

	Vec3 Quat::operator* (const Vec3& v) const
	{
		Vec3 temp(x, y, z);
		Vec3 t = Vec3::CROSS(temp, v) * 2.0f;
		return v + t * w + Vec3::CROSS(temp, t);
	}

	Quat Quat::operator* (float k) const
	{
		Quat tmp(*this);
		tmp *= k;
		return tmp;
	}

	Quat Quat::operator/ (float k) const
	{
		Quat tmp(*this);
		tmp /= k;
		return tmp;
	}

	void Quat::Identity()
	{
		w = 1.0f, x = y = z = 0.0f;
	}

	float Quat::Magnitude() const
	{
		return sqrtf((w * w) + (x * x) + (y * y) + (z * z));
	}

	void Quat::Conjugate()
	{
		x = -x;
		y = -y;
		z = -z;
	}

	void Quat::Normalize()
	{
		float invMagnitude = 1.0f / Magnitude();
		w *= invMagnitude;
		x *= invMagnitude;
		y *= invMagnitude;
		z *= invMagnitude;
	}

	void Quat::Inverse()
	{
		float invMagnitude = 1.0f / Magnitude();
		Conjugate();
		*this = *this * invMagnitude;
	}

	void Quat::FromAxisAngle(const Vec3& axis, float degrees)
	{
		float halfTheta = DEGREES_TO_RADIANS(degrees) * 0.5f;
		float s = sinf(halfTheta);
		w = cosf(halfTheta);
		x = axis.x * s;
		y = axis.y * s;
		z = axis.z * s;
	}

	void Quat::FromAxisAngle(const Vec3& axis)
	{
		float angle = axis.z * 0.5f;
		float sy = sinf(angle);
		float cy = cosf(angle);

		angle = axis.y * 0.5f;
		float sp = sinf(angle);
		float cp = cosf(angle);

		angle = axis.x * 0.5f;
		float sr = sinf(angle);
		float cr = cosf(angle);

		w = cr * cp * cy + sr * sp * sy;
		x = sr * cp * cy - cr * sp * sy;
		y = cr * sp * cy + sr * cp * sy;
		z = cr * cp * sy - sr * sp * cy;
	}

	void Quat::FromMatrix(const Mat4x4& m)
	{
		float s = 0.0f;
		float q[4] = { 0.0f };
		float trace = m[0] + m[5] + m[10];

		if (trace > 0.0f)
		{
			s = sqrtf(trace + 1.0f);
			q[3] = s * 0.5f;
			s = 0.5f / s;
			q[0] = (m[6] - m[9]) * s;
			q[1] = (m[8] - m[2]) * s;
			q[2] = (m[1] - m[4]) * s;
		}
		else
		{
			int nxt[3] = { 1, 2, 0 };
			int i = 0, j = 0, k = 0;

			if (m[5] > m[0])
				i = 1;

			if (m[10] > m[i * 4 + i])
				i = 2;

			j = nxt[i];
			k = nxt[j];
			s = sqrtf((m[i * 4 + i] - (m[j * 4 + j] + m[k * 4 + k])) + 1.0f);

			q[i] = s * 0.5f;
			s = 0.5f / s;
			q[3] = (m[j * 4 + k] - m[k * 4 + j]) * s;
			q[j] = (m[i * 4 + j] + m[j * 4 + i]) * s;
			q[k] = (m[i * 4 + k] + m[k * 4 + i]) * s;
		}

		x = q[0], y = q[1], z = q[2], w = q[3];
	}

	Mat4x4 Quat::ToMatrix4() const
	{
		float x2 = x + x;
		float y2 = y + y;
		float z2 = z + z;
		float xx = x * x2;
		float xy = x * y2;
		float xz = x * z2;
		float yy = y * y2;
		float yz = y * z2;
		float zz = z * z2;
		float wx = w * x2;
		float wy = w * y2;
		float wz = w * z2;

		Mat4x4 m;

		m[0] = 1.0f - (yy + zz);
		m[1] = xy + wz;
		m[2] = xz - wy;
		m[3] = 0.0f;

		m[4] = xy - wz;
		m[5] = 1.0f - (xx + zz);
		m[6] = yz + wx;
		m[7] = 0.0f;

		m[8] = xz + wy;
		m[9] = yz - wx;
		m[10] = 1.0f - (xx + yy);
		m[11] = 0.0f;

		m[12] = 0.0f;
		m[13] = 0.0f;
		m[14] = 0.0f;
		m[15] = 1.0f;

		return m;
	}

	Vec3 Quat::ToVector() const
	{
		float ww = w * w;
		float xx = x * x;
		float yy = y * y;
		float zz = z * z;

		return Vec3(
			atan2f(2.0f * (y * z + w * x), (ww - xx - yy + zz)),
			asinf(-2.0f * (x * z - w * y)),
			atan2f(2.0f * (x * y + w * z), (ww + xx -yy - zz))
		);
	}

	void Quat::AddScaledVector(const Vec3& v, float scale)
	{
		Quat q(0, v.x * scale, v.y * scale, v.z * scale);
		q *= *this;
		w += q.w * 0.5f;
		x += q.x * 0.5f;
		y += q.y * 0.5f;
		z += q.z * 0.5f;
	}

	Quat Quat::CREATE_FROM_AXIS_ANGLE(const Vec3& axis, float degrees)
	{
		Quat q;
		q.FromAxisAngle(axis, degrees);
		return q;
	}

	Quat Quat::CREATE_FROM_AXIS_ANGLE(const Vec3& axis)
	{
		Quat q;
		q.FromAxisAngle(axis);
		return q;
	}

	Mat4x4 Quat::TO_MATRIX4(const Quat& q, const Vec3& v)
	{
		Mat4x4 m = q.ToMatrix4();
		m[3] = v.x;
		m[7] = v.y;
		m[11] = v.z;
		return m;
	}

	Quat Quat::CONJUGATE(const Quat& q)
	{
		return Quat(q.w, -q.x, -q.y, -q.z);
	}

	Quat Quat::INVERT(const Quat& q)
	{
		float invMagnitude = 1.0f / q.Magnitude();
		return CONJUGATE(q) * invMagnitude;
	}

	Quat Quat::NORMALIZE(const Quat& q)
	{
		Quat tmp = Quat(q.w, q.x, q.y, q.z);
		tmp.Normalize();
		return tmp;
	}

	Quat Quat::LERP(const Quat& q1, const Quat& q2, float interpolation)
	{
		Quat q = ((q2 - q1) * interpolation) + q1;
		q.Normalize();
		return q;
	}

	Quat Quat::SLERP(const Quat& q1, const Quat& q2, float interpolation)
	{
		float dot = fabsf(q1.x * q2.x + q1.y * q2.y + q1.z * q2.z + q1.w * q2.w);
		if (dot > 0.999f)
		{
			return LERP(q1, q2, interpolation);
		}

		float theta = acosf(dot);
		float st = sinf(theta);
		float sut = sinf(interpolation * theta);
		float sout = sinf((1.0f - interpolation) * theta);
		float coeff1 = sout / st;
		float coeff2 = sut / st;

		Quat q(
			coeff1 * q1.w + coeff2 * q2.w,
			coeff1 * q1.x + coeff2 * q2.x,
			coeff1 * q1.y + coeff2 * q2.y,
			coeff1 * q1.z + coeff2 * q2.z
		);
		return q;
	}
}