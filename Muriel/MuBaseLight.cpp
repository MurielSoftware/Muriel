#include "stdafx.h"
#include "MuBaseLight.h"

namespace Muriel
{
	BaseLight::BaseLight(const string& name, const Shader& shader, const Color& color, float intensity)
		: GameObject(name)
	{
		_shader = shader;
		_color = color;
		_intensity = intensity;
	}

	BaseLight::~BaseLight()
	{

	}
}