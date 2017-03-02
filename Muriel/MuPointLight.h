#pragma once

#include "MuBaseLight.h"
#include "MuAttenuation.h"

namespace Muriel
{
	class PointLight : public BaseLight
	{
	private:
		Attenuation _attenuation;
		float _range;

		const short COLOR_DEPTH = 256;
	public:
		PointLight(const string& name, const Color& color, float intensity, Attenuation attenuation);
		virtual ~PointLight();

		inline const Attenuation& GetAttenuation() const { return _attenuation; }
		inline float GetRange() { return _range; }
	};
}
