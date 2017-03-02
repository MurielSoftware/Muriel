#pragma once

#include "MuMaterial.h"

namespace Muriel
{
	class DiffuseMaterial : public Material
	{
	private:
		Texture* _texture;
	public:
		DiffuseMaterial(Shader* shader, Texture* texture);
		virtual ~DiffuseMaterial();

		void SetUniforms(AbstractCamera* camera);
		void SetUniforms(GameObject* gameObject);
	};
}