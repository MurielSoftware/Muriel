#pragma once

#include "stdafx.h"

namespace Glml
{
	class GLML_API Color
	{
	public:
		union {
			struct {
				float r;
				float g;
				float b;
				float a;
			};
			float data[4];
		};
		Color();
		Color(float r, float g, float b, float a = 1.0f);

		float Max();
	};
}