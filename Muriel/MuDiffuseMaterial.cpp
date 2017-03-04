#include "stdafx.h"
#include "MuDiffuseMaterial.h"
#include "MuAbstractCamera.h"
#include "MuShader.h"
#include "MuGameObject.h"
#include "MuTexture.h"

namespace Muriel
{
	DiffuseMaterial::DiffuseMaterial(Shader* shader, Texture* texture)
		: BaseMaterial(shader)
	{
		_texture = texture;
	}

	DiffuseMaterial::~DiffuseMaterial()
	{

	}

	void DiffuseMaterial::SetUniforms(AbstractCamera* camera)
	{
		_shader->UniformMat4x4(SHADER_UNIFORM_PROJECTION_VIEW_MATRIX, false, camera->GetProjectionViewMatrix());
		GL::SetActiveTexture(0);
		GL::BindTexture(TextureType::Texture2D(), _texture->GetTextureId());
		_shader->Uniform1i(SHADER_UNIFORM_DIFFUSE_TEXTURE, 0);
	}

	void DiffuseMaterial::SetUniforms(GameObject* gameObject)
	{
		_shader->UniformMat4x4(SHADER_UNIFORM_WORLD_MATRIX, false, gameObject->GetTransform().GetWorldMatrix());
	}
}