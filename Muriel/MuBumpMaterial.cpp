#include "stdafx.h"
#include "MuBumpMaterial.h"
#include "MuAbstractCamera.h"
#include "MuShader.h"
#include "MuGameObject.h"
#include "MuTexture.h"

namespace Muriel
{
	BumpMaterial::BumpMaterial(Shader* shader, Texture* texture, Texture* normalTexture)
		: BaseMaterial(shader)
	{
		_texture = texture;
		_normalTexture = normalTexture;
	}

	BumpMaterial::~BumpMaterial()
	{

	}

	void BumpMaterial::SetUniforms(AbstractCamera* camera)
	{
		_shader->UniformMat4x4(SHADER_UNIFORM_PROJECTION_VIEW_MATRIX, false, camera->GetProjectionViewMatrix());
		_shader->UniformMat4x4(SHADER_UNIFORM_MODEL_VIEW_MATRIX, false, camera->GetViewMatrix());
		_shader->UniformMat3x3(SHADER_UNIFORM_NORMAL_MATRIX, false, camera->GetNormalMatrix());
		_shader->Uniform3f(SHADER_UNIFORM_LIGHT_POSITION, Vec3(-100, 100, 100));
		_shader->Uniform4f(SHADER_UNIFORM_AMBIENT_COLOR, Color(0.2f, 0.2f, 0.2f));
		_shader->Uniform4f(SHADER_UNIFORM_DIFFUSE_COLOR, Color(0.5f, 0.5f, 0.5f));
		_shader->Uniform4f(SHADER_UNIFORM_SPECULAR_COLOR, Color(0.9f, 0.9f, 0.9f));
		GL::SetActiveTexture(0);
		GL::BindTexture(TextureType::Texture2D(), _texture->GetTextureId());
		GL::SetActiveTexture(1);
		GL::BindTexture(TextureType::Texture2D(), _normalTexture->GetTextureId());
		_shader->Uniform1i(SHADER_UNIFORM_DIFFUSE_TEXTURE, 0);
		_shader->Uniform1i(SHADER_UNIFORM_NORMAL_TEXTURE, 1);
	}

	void BumpMaterial::SetUniforms(GameObject* gameObject)
	{
		_shader->UniformMat4x4(SHADER_UNIFORM_WORLD_MATRIX, false, gameObject->GetTransform().GetWorldMatrix());
	}
}