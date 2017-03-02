#pragma once

#include "stdafx.h"

namespace Glml
{
	class GLML_API Mat4x3
	{
	private:
		float data[12];
	public:
		Mat4x3();

		float& operator[] (int i);
		const float& operator[] (int i) const;

		Vec3 GetAxisVector(int i) const;

		Mat4x3 operator*(const Mat4x3& m) const;
		Vec3 operator*(const Vec3& v) const;

		void Identity();
		float Determinant();
		void Inverse();
		Vec3 Transform(const Vec3& v) const;
		Vec3 TransformDirection(const Vec3& v) const;
		Vec3 TransformInverseDirection(const Vec3& v) const;
		Vec3 TransformInverse(const Vec3& v) const;

		static Mat4x3 CALCULATE_TRANSFORM_MATRIX(const Vec3& position, const Quat& orientation);
	};
}