#include "stdafx.h"
#include "MuBaseMaterial.h"
#include "MuShader.h"

namespace Muriel
{
	BaseMaterial::BaseMaterial(Shader* shader)
	{
		_shader = shader;
	}

	BaseMaterial::~BaseMaterial()
	{
	}

	void BaseMaterial::Start()
	{
		_shader->Activate();
	}

	void BaseMaterial::End()
	{
		_shader->Deactivate();
	}
}