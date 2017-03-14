#include "stdafx.h"
#include "MuColorMaterial.h"
#include "MuAbstractCamera.h"
#include "MuShader.h"
#include "MuGameObject.h"

namespace Muriel
{
	ColorMaterial::ColorMaterial(Shader* shader, const Color& color)
		: BaseMaterial(shader)
	{
		_projectionModelViewMatrixId = shader->GetUniformLocation(SHADER_UNIFORM_PROJECTION_VIEW_MATRIX);
		_colorId = shader->GetUniformLocation(SHADER_UNIFORM_COLOR);
		_worldMatrixId = shader->GetUniformLocation(SHADER_UNIFORM_WORLD_MATRIX);
	}

	ColorMaterial::~ColorMaterial()
	{

	}

	void ColorMaterial::SetUniforms(AbstractCamera* camera)
	{
		_shader->UniformMat4x4(SHADER_UNIFORM_PROJECTION_VIEW_MATRIX, _projectionModelViewMatrixId, false, camera->GetProjectionViewMatrix());
		_shader->Uniform4f(SHADER_UNIFORM_COLOR, _colorId, _color);
	}

	void ColorMaterial::SetUniforms(GameObject* gameObject)
	{
		_shader->UniformMat4x4(SHADER_UNIFORM_WORLD_MATRIX, _worldMatrixId, false, gameObject->GetTransform().GetWorldMatrix());
	}
}