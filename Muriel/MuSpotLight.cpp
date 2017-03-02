#include "stdafx.h"
#include "MuSpotLight.h"

namespace Muriel
{
	SpotLight::SpotLight(Color color, float intensity, Attenuation attenuation, float cutoff)
		: PointLight(color, intensity, attenuation)
	{
		_cutoff = cutoff;
	}

	SpotLight::~SpotLight()
	{

	}
}