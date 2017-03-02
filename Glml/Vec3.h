#pragma once

#include "stdafx.h"

namespace Glml
{
	class GLML_API Vec3
	{
	public:
		union {
			struct {
				float x;
				float y;
				float z;
			};
			float data[3];
		};

		Vec3();
		Vec3(float x, float y, float z);

		float operator[](unsigned i) const;
		float& operator[](unsigned i);
		void operator+=(const Vec3& rhs);
		void operator-=(const Vec3& rhs);
		void operator*=(float k);
		void operator/=(float k);
		Vec3 operator+(const Vec3& rhs) const;
		Vec3 operator-(const Vec3& rhs) const;
		Vec3 operator*(float k) const;
		Vec3 operator/(float k) const;

		void AddScaledVector(const Vec3& v, float scale);
		void Set(float x, float y, float z);
		float Magnitude();
		float MagintudeSq();
		void Normalize();
		void Inverse();
		void Clear();

		static Vec3 CROSS(const Vec3& v1, const Vec3& v2);
		static float DOT(const Vec3& v1, const Vec3& v2);
		static Vec3 COMPONENT_PRODUCT(const Vec3& v1, const Vec3& v2);
		static Vec3 LERP(const Vec3& v1, const Vec3& v2, float interpolation);
		static Vec3 INVERT(const Vec3& v);
		static float DISTANCE(const Vec3& v1, const Vec3& v2);
	};
}