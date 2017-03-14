#include "stdafx.h"
#include "MuBumpMaterial.h"
#include "MuAbstractCamera.h"
#include "MuShader.h"
#include "MuGameObject.h"
#include "MuTexture.h"

namespace Muriel
{
	BumpMaterial::BumpMaterial(Shader* shader, Texture* diffuseTexture, Texture* normalTexture)
		: DiffuseMaterial(shader, diffuseTexture)
	{
		_normalTexture = normalTexture;

		_modelViewMatrixId = _shader->GetUniformLocation(SHADER_UNIFORM_MODEL_VIEW_MATRIX);
		_normalMatrixId = _shader->GetUniformLocation(SHADER_UNIFORM_NORMAL_MATRIX);
		_lightPositionId = _shader->GetUniformLocation(SHADER_UNIFORM_LIGHT_POSITION);
		_ambientColorId = _shader->GetUniformLocation(SHADER_UNIFORM_AMBIENT_COLOR);
		_diffuseColorId = _shader->GetUniformLocation(SHADER_UNIFORM_DIFFUSE_COLOR);
		_specularColorId = _shader->GetUniformLocation(SHADER_UNIFORM_SPECULAR_COLOR);
		_normalTextureId = _shader->GetUniformLocation(SHADER_UNIFORM_NORMAL_TEXTURE);
	}

	BumpMaterial::~BumpMaterial()
	{

	}

	void BumpMaterial::SetUniforms(AbstractCamera* camera)
	{
		DiffuseMaterial::SetUniforms(camera);

		_shader->UniformMat4x4(SHADER_UNIFORM_MODEL_VIEW_MATRIX, _modelViewMatrixId, false, camera->GetViewMatrix());
		_shader->UniformMat3x3(SHADER_UNIFORM_NORMAL_MATRIX, _normalMatrixId, false, camera->GetNormalMatrix());
		_shader->Uniform3f(SHADER_UNIFORM_LIGHT_POSITION, _lightPositionId, Vec3(-100, 100, 100));
		_shader->Uniform4f(SHADER_UNIFORM_AMBIENT_COLOR, _ambientColorId, Color(0.2f, 0.2f, 0.2f));
		_shader->Uniform4f(SHADER_UNIFORM_DIFFUSE_COLOR, _diffuseColorId, Color(0.5f, 0.5f, 0.5f));
		_shader->Uniform4f(SHADER_UNIFORM_SPECULAR_COLOR, _specularColorId, Color(0.9f, 0.9f, 0.9f));

		GL::SetActiveTexture(1);
		GL::BindTexture(TextureType::Texture2D(), _normalTexture->GetTextureId());
		_shader->Uniform1i(SHADER_UNIFORM_NORMAL_TEXTURE, _normalTextureId, 1);
	}

	void BumpMaterial::SetUniforms(GameObject* gameObject)
	{
		DiffuseMaterial::SetUniforms(gameObject);
	}
}