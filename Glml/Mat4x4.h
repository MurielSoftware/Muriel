#pragma once

#include "stdafx.h"

namespace Glml
{
	class GLML_API Mat4x4
	{
	private:
		float data[16];
	public:
		Mat4x4();

		float& operator[] (int i);
		const float& operator[] (int i) const;

		Mat4x4 operator*(const Mat4x4 m) const;

		void Identity();
		const float* Pointer() const;
	};
}