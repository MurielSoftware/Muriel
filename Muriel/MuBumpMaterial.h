#pragma once

#include "MuDiffuseMaterial.h"

namespace Muriel
{
	class BumpMaterial : public DiffuseMaterial
	{
	protected:
		unsigned _modelViewMatrixId;
		unsigned _normalMatrixId;
		unsigned _lightPositionId;
		unsigned _ambientColorId;
		unsigned _diffuseColorId;
		unsigned _specularColorId;
		unsigned _normalTextureId;

		Texture* _normalTexture;
	public:
		BumpMaterial(Shader* shader, Texture* diffuseTexture, Texture* bumpTexture);
		virtual ~BumpMaterial();

		virtual void SetUniforms(AbstractCamera* camera);
		virtual void SetUniforms(GameObject* gameObject);
	};
}