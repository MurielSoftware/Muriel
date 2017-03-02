#include "stdafx.h"
#include "MuPointLight.h"

namespace Muriel
{
	PointLight::PointLight(Color color, float intensity, Attenuation attenuation)
		: BaseLight(color, intensity)
	{
		_attenuation = attenuation;
		float a = attenuation.GetExponent();
		float b = attenuation.GetLinear();
		float c = attenuation.GetConstant() - COLOR_DEPTH * GetIntensity() * GetColor().Max();
		_range = (-b + sqrtf(b * b - 4.0f * a * c)) / (2.0f * a);
	}

	PointLight::~PointLight()
	{

	}
}