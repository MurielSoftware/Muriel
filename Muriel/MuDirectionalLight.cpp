#include "stdafx.h"
#include "MuDirectionalLight.h"

namespace Muriel
{
	DirectionalLight::DirectionalLight(const string& name, const Shader& shader, const Color& color, float intensity)
		: BaseLight(name, shader, color, intensity)
	{

	}

	DirectionalLight::~DirectionalLight()
	{

	}
}