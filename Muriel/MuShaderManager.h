#pragma once

#include "stdafx.h"
#include "MuAbstractResourceManager.h"
#include "MuSingleton.h"

namespace Muriel
{
	class MURIEL_API ShaderManager : public AbstractResourceManager<Shader>, public Singleton<ShaderManager>
	{
	private:
		GLuint CompileShader(const string& name, GLenum shaderType, const string& shaderContent);
	protected:
		virtual Shader* DoLoad(const string& name, const string& path);
		virtual bool DoSave(Shader* resource, const string& path);
	public:
	};
}