#pragma once

#include "stdafx.h"

namespace Glml
{
	class GLML_API Mat3x3
	{
	private:
		float data[9];
	public:
		Mat3x3();
		Mat3x3::Mat3x3(const Mat4x4& m);

		float& operator[] (int i);
		const float& operator[] (int i) const;

		Mat3x3 operator*(const Mat3x3& m) const;
		void operator*=(const Mat3x3& m);
		Vec3 operator*(const Vec3& v) const;
		void operator*=(const float k);
		void operator+=(const Mat3x3& m);

		void SetComponents(const Vec3& v1, const Vec3& v2, const Vec3& v3);
		void SetInertiaTensorCoeffs(float ix, float iy, float iz, float ixy = 0, float ixz = 0, float iyz = 0);
		void SetBlockInertiaTensor(const Vec3 &halfSizes, float mass);
		void SetSkewSymmetric(const Vec3& vector);
		void Identity();
		void Inverse();
		Vec3 Transform(const Vec3& v);
		Vec3 TransformTranspose(const Vec3& v);
		void SetTranspose(const Mat3x3& m);
		Mat3x3 Transpose();
		const float* Pointer() const;

		static Mat3x3 INVERT(const Mat3x3& m);
		static Mat3x3 TRANSFORM_INERTIA_TENSOR(const Quat& q, const Mat3x3& iitBody, const Mat4x3& rotMatrix);
	};
}