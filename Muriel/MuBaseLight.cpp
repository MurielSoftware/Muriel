#include "stdafx.h"
#include "MuBaseLight.h"

namespace Muriel
{
	BaseLight::BaseLight(Color color, float intensity)
	{
		_color = color;
		_intensity = intensity;
	}

	BaseLight::~BaseLight()
	{

	}
}