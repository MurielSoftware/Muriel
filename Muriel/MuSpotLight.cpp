#include "stdafx.h"
#include "MuSpotLight.h"

namespace Muriel
{
	SpotLight::SpotLight(const string& name, const Shader& shader, const Color& color, float intensity, Attenuation attenuation, float cutoff)
		: PointLight(name, shader, color, intensity, attenuation)
	{
		_cutoff = cutoff;
	}

	SpotLight::~SpotLight()
	{

	}
}