#pragma once

#include "MuBaseLight.h"

namespace Muriel
{
	class DirectionalLight : public BaseLight
	{
	public:
		DirectionalLight(Color color, float intensity);
		virtual ~DirectionalLight();

		//inline Vec3 GetDirection() {}
	};
}
