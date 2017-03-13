#pragma once

#include "MuBaseMaterial.h"

namespace Muriel
{
	class BumpMaterial : public BaseMaterial
	{
	private:
		Texture* _texture;
		Texture* _normalTexture;
	public:
		BumpMaterial(Shader* shader, Texture* texture, Texture* bumpTexture);
		virtual ~BumpMaterial();

		void SetUniforms(AbstractCamera* camera);
		void SetUniforms(GameObject* gameObject);
	};
}