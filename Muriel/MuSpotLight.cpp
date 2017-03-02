#include "stdafx.h"
#include "MuSpotLight.h"

namespace Muriel
{
	SpotLight::SpotLight(const string& name, const Color& color, float intensity, Attenuation attenuation, float cutoff)
		: PointLight(name, color, intensity, attenuation)
	{
		_cutoff = cutoff;
	}

	SpotLight::~SpotLight()
	{

	}
}