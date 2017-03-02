#include "stdafx.h"
#include "MuMaterial.h"
#include "MuShader.h"

namespace Muriel
{
	Material::Material(Shader* shader)
	{
		_shader = shader;
	}

	Material::~Material()
	{
	}

	void Material::Start()
	{
		_shader->Activate();
	}

	void Material::End()
	{
		_shader->Deactivate();
	}
}