#pragma once

#include "MuGameObject.h"
#include "Color.h"

using namespace Glml;

namespace Muriel
{
	class BaseLight : public GameObject
	{
	private:
		Color _color;
		float _intensity;
	public:
		BaseLight(const string& name, const Color& color, float intensity);
		virtual ~BaseLight();

		inline Color& GetColor() { return _color; }
		inline const float GetIntensity() const { return _intensity; }
	};
}