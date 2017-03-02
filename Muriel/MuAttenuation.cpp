#include "stdafx.h"
#include "MuAttenuation.h"

namespace Muriel
{
	Attenuation::Attenuation()
	{

	}

	Attenuation::Attenuation(float constant, float linear, float exponent)
	{
		_constant = constant;
		_linear = linear;
		_exponent = exponent;
	}

	Attenuation::~Attenuation()
	{

	}
}