#pragma once

#include "Color.h"

using namespace Glml;

namespace Muriel
{
	class BaseLight
	{
	private:
		Color _color;
		float _intensity;
	public:
		BaseLight(Color color, float intensity);
		virtual ~BaseLight();

		inline Color& GetColor() { return _color; }
		inline const float GetIntensity() const { return _intensity; }
	};
}