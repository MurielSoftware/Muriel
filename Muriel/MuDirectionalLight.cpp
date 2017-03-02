#include "stdafx.h"
#include "MuDirectionalLight.h"

namespace Muriel
{
	DirectionalLight::DirectionalLight(const string& name, const Color& color, float intensity)
		: BaseLight(name, color, intensity)
	{

	}

	DirectionalLight::~DirectionalLight()
	{

	}
}