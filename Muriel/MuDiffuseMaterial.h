#pragma once

#include "MuBaseMaterial.h"

namespace Muriel
{
	class DiffuseMaterial : public BaseMaterial
	{
	private:
		Texture* _texture;
	protected:
		unsigned _diffuseTextureId;
	public:
		DiffuseMaterial(Shader* shader, Texture* texture);
		virtual ~DiffuseMaterial();

		virtual void SetUniforms(AbstractCamera* camera);
		virtual void SetUniforms(GameObject* gameObject);
	};
}