#pragma once

#include "MuGameObject.h"
#include "Color.h"
#include "MuShader.h"

using namespace Glml;

namespace Muriel
{
	class BaseLight : public GameObject
	{
	private:
		Shader _shader;
		Color _color;
		float _intensity;
	public:
		BaseLight(const string& name, const Shader& shader, const Color& color, float intensity);
		virtual ~BaseLight();

		inline Shader& GetShader() { return _shader; }
		inline Color& GetColor() { return _color; }
		inline const float GetIntensity() const { return _intensity; }
	};
}