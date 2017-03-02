#pragma once

#include "stdafx.h"

namespace Glml
{
	class GLML_API Quat
	{
	private:
	protected:
	public:
		union {
			struct {
				float x;
				float y;
				float z;
				float w;
			};
			float data[4];
		};

		Quat();
		Quat(float w, float x, float y, float z);

		void operator+= (const Quat& rhs);
		void operator-= (const Quat& rhs);
		void operator*= (const Quat& rhs);
		void operator*= (float k);
		void operator/= (float k);
		Quat operator+ (const Quat& rhs) const;
		Quat operator- (const Quat& rhs) const;
		Quat operator* (const Quat& rhs) const;
		Vec3 operator* (const Vec3& rhs) const;
		Quat operator* (float k) const;
		Quat operator/ (float k) const;

		void Identity();
		float Magnitude() const;
		void Conjugate();
		void Normalize();
		void Inverse();
		void FromAxisAngle(const Vec3& axis, float degrees);
		void FromAxisAngle(const Vec3& axis);
		void FromMatrix(const Mat4x4& m);
		Mat4x4 ToMatrix4() const;
		Vec3 ToVector() const;
		//Mat4x4 ToMatrix4(const Vec3& v) const;
		void AddScaledVector(const Vec3& v, float scale);

		static Quat CREATE_FROM_AXIS_ANGLE(const Vec3& axis, float degrees);
		static Quat CREATE_FROM_AXIS_ANGLE(const Vec3& axis);
		static Mat4x4 TO_MATRIX4(const Quat& q, const Vec3& v);
		static Quat CONJUGATE(const Quat& q);
		static Quat INVERT(const Quat& q);
		static Quat NORMALIZE(const Quat& q);
		static Quat LERP(const Quat& q1, const Quat& q2, float interpolation);
		static Quat SLERP(const Quat& q1, const Quat& q2, float interpolation);
	};
}