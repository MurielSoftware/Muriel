#include "stdafx.h"
#include "MuBaseLight.h"

namespace Muriel
{
	BaseLight::BaseLight(const string& name, const Color& color, float intensity)
		: GameObject(name)
	{
		_color = color;
		_intensity = intensity;
	}

	BaseLight::~BaseLight()
	{

	}
}