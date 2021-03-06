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

		_projectionModelViewMatrixId = shader->GetUniformLocation(SHADER_UNIFORM_PROJECTION_VIEW_MATRIX);
		_diffuseTextureId = shader->GetUniformLocation(SHADER_UNIFORM_DIFFUSE_TEXTURE);
		_worldMatrixId = shader->GetUniformLocation(SHADER_UNIFORM_WORLD_MATRIX);
	}

	DiffuseMaterial::~DiffuseMaterial()
	{

	}

	void DiffuseMaterial::SetUniforms(AbstractCamera* camera)
	{
		_shader->UniformMat4x4(SHADER_UNIFORM_PROJECTION_VIEW_MATRIX, _projectionModelViewMatrixId, false, camera->GetProjectionViewMatrix());
		GL::SetActiveTexture(0);
		GL::BindTexture(TextureType::Texture2D(), _texture->GetTextureId());
		_shader->Uniform1i(SHADER_UNIFORM_DIFFUSE_TEXTURE, _diffuseTextureId, 0);
	}

	void DiffuseMaterial::SetUniforms(GameObject* gameObject)
	{
		_shader->UniformMat4x4(SHADER_UNIFORM_WORLD_MATRIX, _worldMatrixId, false, gameObject->GetTransform().GetWorldMatrix());
	}
}