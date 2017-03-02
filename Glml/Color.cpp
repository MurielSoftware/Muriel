#include "stdafx.h"
#include "Color.h"

namespace Glml
{
	Color::Color()
	{
		r = g = b = 0.0f;
		a = 1.0f;
	}

	Color::Color(float r, float g, float b, float a)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}

	float Color::Max()
	{
		return max(r, max(g, b));
	}
}