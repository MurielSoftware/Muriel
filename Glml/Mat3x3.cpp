#include "stdafx.h"
#include "Mat3x3.h"
#include "Vec3.h"
#include "Mat4x3.h"

namespace Glml
{
	Mat3x3::Mat3x3()
	{

	}

	float& Mat3x3::operator[] (int i)
	{
		return data[i];
	}

	const float& Mat3x3::operator[] (int i) const
	{
		return data[i];
	}

	Mat3x3 Mat3x3::operator*(const Mat3x3& m) const
	{
		Mat3x3 resultMatrix;
		resultMatrix[0] = data[0] * m[0] + data[1] * m[3] + data[2] * m[6];
		resultMatrix[1] = data[0] * m[1] + data[1] * m[4] + data[2] * m[7];
		resultMatrix[2] = data[0] * m[2] + data[1] * m[5] + data[2] * m[8];

		resultMatrix[3] = data[3] * m[0] + data[4] * m[3] + data[5] * m[6];
		resultMatrix[4] = data[3] * m[1] + data[4] * m[4] + data[5] * m[7];
		resultMatrix[5] = data[3] * m[2] + data[4] * m[5] + data[5] * m[8];

		resultMatrix[6] = data[6] * m[0] + data[7] * m[3] + data[8] * m[6];
		resultMatrix[7] = data[6] * m[1] + data[7] * m[4] + data[8] * m[7];
		resultMatrix[8] = data[6] * m[2] + data[7] * m[5] + data[8] * m[8];
		return resultMatrix;
	}

	void Mat3x3::operator*=(const Mat3x3& m)
	{
		float t1;
		float t2;
		float t3;

		t1 = data[0] * m[0] + data[1] * m[3] + data[2] * m[6];
		t2 = data[0] * m[1] + data[1] * m[4] + data[2] * m[7];
		t3 = data[0] * m[2] + data[1] * m[5] + data[2] * m[8];
		data[0] = t1;
		data[1] = t2;
		data[2] = t3;

		t1 = data[3] * m[0] + data[4] * m[3] + data[5] * m[6];
		t2 = data[3] * m[1] + data[4] * m[4] + data[5] * m[7];
		t3 = data[3] * m[2] + data[4] * m[5] + data[5] * m[8];
		data[3] = t1;
		data[4] = t2;
		data[5] = t3;

		t1 = data[6] * m[0] + data[7] * m[3] + data[8] * m[6];
		t2 = data[6] * m[1] + data[7] * m[4] + data[8] * m[7];
		t3 = data[6] * m[2] + data[7] * m[5] + data[8] * m[8];
		data[6] = t1;
		data[7] = t2;
		data[8] = t3;
	}

	Vec3 Mat3x3::operator*(const Vec3& v) const
	{
		return Vec3(
			v.x * data[0] + v.y * data[1] + v.z * data[2],
			v.x * data[3] + v.y * data[4] + v.z * data[5],
			v.x * data[6] + v.y * data[7] + v.z * data[8]
		);
	}

	void Mat3x3::operator*=(const float k)
	{
		data[0] *= k; data[1] *= k; data[2] *= k;
		data[3] *= k; data[4] *= k; data[5] *= k;
		data[6] *= k; data[7] *= k; data[8] *= k;
	}

	void Mat3x3::operator+=(const Mat3x3 &m)
	{
		data[0] += m[0]; data[1] += m[1]; data[2] += m[2];
		data[3] += m[3]; data[4] += m[4]; data[5] += m[5];
		data[6] += m[6]; data[7] += m[7]; data[8] += m[8];
	}

	void Mat3x3::SetComponents(const Vec3& v1, const Vec3& v2, const Vec3& v3)
	{
		data[0] = v1.x;
		data[1] = v1.y;
		data[2] = v1.z;
		data[3] = v2.x;
		data[4] = v2.y;
		data[5] = v2.z;
		data[6] = v3.x;
		data[7] = v3.y;
		data[8] = v3.z;
	}

	void Mat3x3::SetInertiaTensorCoeffs(float ix, float iy, float iz, float ixy, float ixz, float iyz)
	{
		data[0] = ix;
		data[1] = data[3] = -ixy;
		data[2] = data[6] = -ixz;
		data[4] = iy;
		data[5] = data[7] = -iyz;
		data[8] = iz;
	}

	void Mat3x3::SetBlockInertiaTensor(const Vec3 &halfSizes, float mass)
	{
		Vec3 squares = Vec3::COMPONENT_PRODUCT(halfSizes, halfSizes);
		SetInertiaTensorCoeffs(0.3f*mass*(squares.y + squares.z),
			0.3f*mass*(squares.x + squares.z),
			0.3f*mass*(squares.x + squares.y));
	}

	void Mat3x3::SetSkewSymmetric(const Vec3& vector)
	{
		data[0] = data[4] = data[8] = 0;
		data[1] = -vector.z;
		data[2] = vector.y;
		data[3] = vector.z;
		data[5] = -vector.x;
		data[6] = -vector.y;
		data[7] = vector.x;
	}

	void Mat3x3::Identity()
	{
		data[0] = 1.0f;
		data[1] = 0.0f;
		data[2] = 0.0f;

		data[3] = 0.0f;
		data[4] = 1.0f;
		data[5] = 0.0f;

		data[6] = 0.0f;
		data[7] = 0.0f;
		data[8] = 1.0f;
	}

	void Mat3x3::Inverse()
	{
		float t4 = data[0] * data[4];
		float t6 = data[0] * data[5];
		float t8 = data[1] * data[3];
		float t10 = data[2] * data[3];
		float t12 = data[1] * data[6];
		float t14 = data[2] * data[6];
		float t16 = (t4*data[8] - t6*data[7] - t8*data[8] + t10*data[7] + t12*data[5] - t14*data[4]);
		if (t16 == 0.0f)
		{
			return;
		}
		float t17 = 1.0f / t16;

		Mat3x3 m = *this;
		data[0] = (m[4] * m[8] - m[5] * m[7])*t17;
		data[1] = -(m[1] * m[8] - m[2] * m[7])*t17;
		data[2] = (m[1] * m[5] - m[2] * m[4])*t17;
		data[3] = -(m[3] * m[8] - m[5] * m[6])*t17;
		data[4] = (m[0] * m[8] - t14)*t17;
		data[5] = -(t6 - t10)*t17;
		data[6] = (m[3] * m[7] - m[4] * m[6])*t17;
		data[7] = -(m[0] * m[7] - t12)*t17;
		data[8] = (t4 - t8)*t17;
	}

	Vec3 Mat3x3::Transform(const Vec3& v)
	{
		return (*this) * v;
	}

	Vec3 Mat3x3::TransformTranspose(const Vec3& v)
	{
		return Vec3(
			v.x * data[0] + v.y * data[3] + v.z * data[6],
			v.x * data[1] + v.y * data[4] + v.z * data[7],
			v.x * data[2] + v.y * data[5] + v.z * data[8]
		);
	}

	void Mat3x3::SetTranspose(const Mat3x3& m)
	{
		data[0] = m[0];
		data[1] = m[3];
		data[2] = m[6];
		data[3] = m[1];
		data[4] = m[4];
		data[5] = m[7];
		data[6] = m[2];
		data[7] = m[5];
		data[8] = m[8];
	}

	Mat3x3 Mat3x3::Transpose()
	{
		Mat3x3 result;
		result.SetTranspose(*this);
		return result;
	}

	Mat3x3 Mat3x3::INVERT(Mat3x3 m)
	{
		Mat3x3 result = m;
		result.Inverse();
		return result;
	}

	Mat3x3 Mat3x3::TRANSFORM_INERTIA_TENSOR(const Quat& q, const Mat3x3& iitBody, const Mat4x3& rotMatrix)
	{
		float t4 = rotMatrix[0] * iitBody[0] +
			rotMatrix[1] * iitBody[3] +
			rotMatrix[2] * iitBody[6];
		float t9 = rotMatrix[0] * iitBody[1] +
			rotMatrix[1] * iitBody[4] +
			rotMatrix[2] * iitBody[7];
		float t14 = rotMatrix[0] * iitBody[2] +
			rotMatrix[1] * iitBody[5] +
			rotMatrix[2] * iitBody[8];
		float t28 = rotMatrix[4] * iitBody[0] +
			rotMatrix[5] * iitBody[3] +
			rotMatrix[6] * iitBody[6];
		float t33 = rotMatrix[4] * iitBody[1] +
			rotMatrix[5] * iitBody[4] +
			rotMatrix[6] * iitBody[7];
		float t38 = rotMatrix[4] * iitBody[2] +
			rotMatrix[5] * iitBody[5] +
			rotMatrix[6] * iitBody[8];
		float t52 = rotMatrix[8] * iitBody[0] +
			rotMatrix[9] * iitBody[3] +
			rotMatrix[10] * iitBody[6];
		float t57 = rotMatrix[8] * iitBody[1] +
			rotMatrix[9] * iitBody[4] +
			rotMatrix[10] * iitBody[7];
		float t62 = rotMatrix[8] * iitBody[2] +
			rotMatrix[9] * iitBody[5] +
			rotMatrix[10] * iitBody[8];

		Mat3x3 iitWorld;
		iitWorld.data[0] = t4*rotMatrix[0] +
			t9*rotMatrix[1] +
			t14*rotMatrix[2];
		iitWorld.data[1] = t4*rotMatrix[4] +
			t9*rotMatrix[5] +
			t14*rotMatrix[6];
		iitWorld.data[2] = t4*rotMatrix[8] +
			t9*rotMatrix[9] +
			t14*rotMatrix[10];
		iitWorld.data[3] = t28*rotMatrix[0] +
			t33*rotMatrix[1] +
			t38*rotMatrix[2];
		iitWorld.data[4] = t28*rotMatrix[4] +
			t33*rotMatrix[5] +
			t38*rotMatrix[6];
		iitWorld.data[5] = t28*rotMatrix[8] +
			t33*rotMatrix[9] +
			t38*rotMatrix[10];
		iitWorld.data[6] = t52*rotMatrix[0] +
			t57*rotMatrix[1] +
			t62*rotMatrix[2];
		iitWorld.data[7] = t52*rotMatrix[4] +
			t57*rotMatrix[5] +
			t62*rotMatrix[6];
		iitWorld.data[8] = t52*rotMatrix[8] +
			t57*rotMatrix[9] +
			t62*rotMatrix[10];
		return iitWorld;
	}
}