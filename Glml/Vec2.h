#pragma once

#include "stdafx.h"

namespace Glml
{
	class GLML_API Vec2
	{
	public:
		union {
			struct {
				float x;
				float y;
			};
			float data[2];
		};

		Vec2();
		Vec2(float x, float y);
	};
}