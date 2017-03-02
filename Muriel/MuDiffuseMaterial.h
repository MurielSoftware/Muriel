#pragma once

#include "MuBaseMaterial.h"

namespace Muriel
{
	class DiffuseMaterial : public BaseMaterial
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