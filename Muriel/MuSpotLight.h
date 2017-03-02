#pragma once

#include "MuPointLight.h"

namespace Muriel
{
	class SpotLight : public PointLight
	{
	private:
		float _cutoff;
	public:
		SpotLight(Color color, float intensity, Attenuation attenuation, float cutoff);
		virtual ~SpotLight();

		//inline Vec3 GetDirection() { return Vec3(); }
		inline float GetCutoff() { return _cutoff; }
	};
}
