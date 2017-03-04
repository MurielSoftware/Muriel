#pragma once

#include "MuBaseLight.h"

namespace Muriel
{
	class DirectionalLight : public BaseLight
	{
	public:
		DirectionalLight(const string& name, const Shader& shader, const Color& color, float intensity);
		virtual ~DirectionalLight();

		inline const Vec3& GetDirection() { return GetTransform().GetRight(); }
	};
}
