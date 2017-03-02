#pragma once

#include "MuPointLight.h"

namespace Muriel
{
	class SpotLight : public PointLight
	{
	private:
		float _cutoff;
	public:
		SpotLight(const string& name, const Color& color, float intensity, Attenuation attenuation, float cutoff);
		virtual ~SpotLight();

		inline const Vec3& GetDirection() { return GetTransform().GetForward(); }
		inline float GetCutoff() { return _cutoff; }
	};
}
