#include "stdafx.h"
#include "Mat4x3.h"
#include "Vec3.h"
#include "Quat.h"

namespace Glml
{
	Mat4x3::Mat4x3()
	{
		Identity();
	}

	float& Mat4x3::operator[] (int i)
	{
		return data[i];
	}

	const float& Mat4x3::operator[] (int i) const
	{
		return data[i];
	}

	Vec3 Mat4x3::GetAxisVector(int i) const
	{
		return Vec3(data[i], data[i + 4], data[i + 8]);
	}

	Mat4x3 Mat4x3::operator*(const Mat4x3 &m) const
	{
		Mat4x3 result;
		result[0] = (m[0] * data[0]) + (m[4] * data[1]) + (m[8] * data[2]);
		result[4] = (m[0] * data[4]) + (m[4] * data[5]) + (m[8] * data[6]);
		result[8] = (m[0] * data[8]) + (m[4] * data[9]) + (m[8] * data[10]);

		result[1] = (m[1] * data[0]) + (m[5] * data[1]) + (m[9] * data[2]);
		result[5] = (m[1] * data[4]) + (m[5] * data[5]) + (m[9] * data[6]);
		result[9] = (m[1] * data[8]) + (m[5] * data[9]) + (m[9] * data[10]);

		result[2] = (m[2] * data[0]) + (m[6] * data[1]) + (m[10] * data[2]);
		result[6] = (m[2] * data[4]) + (m[6] * data[5]) + (m[10] * data[6]);
		result[10] = (m[2] * data[8]) + (m[6] * data[9]) + (m[10] * data[10]);

		result[3] = (m[3] * data[0]) + (m[7] * data[1]) + (m[11] * data[2]) + data[3];
		result[7] = (m[3] * data[4]) + (m[7] * data[5]) + (m[11] * data[6]) + data[7];
		result[11] = (m[3] * data[8]) + (m[7] * data[9]) + (m[11] * data[10]) + data[11];

		return result;
	}

	Vec3 Mat4x3::operator*(const Vec3& v) const
	{
		return Vec3(
			v.x * data[0] + v.y * data[1] + v.z * data[2] + data[3],
			v.x * data[4] + v.y * data[5] + v.z * data[6] + data[7],
			v.x * data[8] + v.y * data[9] + v.z * data[10] + data[11]
		);
	}

	void Mat4x3::Identity()
	{
		data[0] = 1.0f;
		data[1] = 0.0f;
		data[2] = 0.0f;
		data[3] = 0.0f;

		data[4] = 0.0f;
		data[5] = 1.0f;
		data[6] = 0.0f;
		data[7] = 0.0f;

		data[8] = 0.0f;
		data[9] = 0.0f;
		data[10] = 1.0f;
		data[11] = 0.0f;
	}

	float Mat4x3::Determinant()
	{
		return -data[8] * data[5] * data[2] +
			data[4] * data[9] * data[2] +
			data[8] * data[1] * data[6] -
			data[0] * data[9] * data[6] -
			data[4] * data[1] * data[10] +
			data[0] * data[5] * data[10];
	}

	void Mat4x3::Inverse()
	{
		float det = Determinant();
		if (det == 0) return;
		det = 1.0f / det;

		Mat4x3 m;
		m[0] = (-data[9] * data[6] + data[5] * data[10]) * det;
		m[4] = (data[8] * data[6] - data[4] * data[10]) * det;
		m[8] = (-data[8] * data[5] + data[4] * data[9]) * det;

		m[1] = (data[9] * data[2] - data[1] * data[10]) * det;
		m[5] = (-data[8] * data[2] + data[0] * data[10]) * det;
		m[9] = (data[8] * data[1] - data[0] * data[9]) * det;

		m[2] = (-data[5] * data[2] + data[1] * data[6]) * det;
		m[6] = (+data[4] * data[2] - data[0] * data[6]) * det;
		m[10] = (-data[4] * data[1] + data[0] * data[5]) * det;

		m[3] = (data[9] * data[6] * data[3]
			- data[5] * data[10] * data[3]
			- data[9] * data[2] * data[7]
			+ data[1] * data[10] * data[7]
			+ data[5] * data[2] * data[11]
			- data[1] * data[6] * data[11]) * det;

		m[7] = (-data[8] * data[6] * data[3]
			+ data[4] * data[10] * data[3]
			+ data[8] * data[2] * data[7]
			- data[0] * data[10] * data[7]
			- data[4] * data[2] * data[11]
			+ data[0] * data[6] * data[11]) * det;

		m[11] = (data[8] * data[5] * data[3]
			- data[4] * data[9] * data[3]
			- data[8] * data[1] * data[7]
			+ data[0] * data[9] * data[7]
			+ data[4] * data[1] * data[11]
			- data[0] * data[5] * data[11]) * det;

		(*this) = m;
	}

	Vec3 Mat4x3::Transform(const Vec3& v) const
	{
		return (*this) * v;
	}

	Vec3 Mat4x3::TransformDirection(const Vec3& v) const
	{
		return Vec3(
			v.x * data[0] + v.y * data[1] + v.z * data[2],
			v.x * data[4] + v.y * data[5] + v.z * data[6],
			v.x * data[8] + v.y * data[9] + v.z * data[10]
		);
	}

	Vec3 Mat4x3::TransformInverseDirection(const Vec3& v) const
	{
		return Vec3(
			v.x * data[0] + v.y * data[4] + v.z * data[8],
			v.x * data[1] + v.y * data[5] + v.z * data[9],
			v.x * data[2] + v.y * data[6] + v.z * data[10]
		);
	}

	Vec3 Mat4x3::TransformInverse(const Vec3& v) const
	{
		Vec3 tmp = v;
		tmp.x -= data[3];
		tmp.y -= data[7];
		tmp.z -= data[11];
		return Vec3(
			tmp.x * data[0] + tmp.y * data[4] + tmp.z * data[8],
			tmp.x * data[1] + tmp.y * data[5] + tmp.z * data[9],
			tmp.x * data[2] + tmp.y * data[6] + tmp.z * data[10]
		);
	}

	Mat4x3 Mat4x3::CALCULATE_TRANSFORM_MATRIX(const Vec3& position, const Quat& orientation)
	{
		Mat4x3 transformMatrix;
		transformMatrix.data[0] = 1 - 2 * orientation.y*orientation.y -
			2 * orientation.z*orientation.z;
		transformMatrix.data[1] = 2 * orientation.x*orientation.y -
			2 * orientation.w*orientation.z;
		transformMatrix.data[2] = 2 * orientation.x*orientation.z +
			2 * orientation.w*orientation.y;
		transformMatrix.data[3] = position.x;

		transformMatrix.data[4] = 2 * orientation.x*orientation.y +
			2 * orientation.w*orientation.z;
		transformMatrix.data[5] = 1 - 2 * orientation.x*orientation.x -
			2 * orientation.z*orientation.z;
		transformMatrix.data[6] = 2 * orientation.y*orientation.z -
			2 * orientation.w*orientation.x;
		transformMatrix.data[7] = position.y;

		transformMatrix.data[8] = 2 * orientation.x*orientation.z -
			2 * orientation.w*orientation.y;
		transformMatrix.data[9] = 2 * orientation.y*orientation.z +
			2 * orientation.w*orientation.x;
		transformMatrix.data[10] = 1 - 2 * orientation.x*orientation.x -
			2 * orientation.y*orientation.y;
		transformMatrix.data[11] = position.z;

		return transformMatrix;
	}
}