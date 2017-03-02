#include "stdafx.h"
#include "MuShaderManager.h"
#include "MuShader.h"
#include "MuException.h"
#include "MuFileUtils.h"
#include "MuShaderType.h"

namespace Muriel
{
	Shader* ShaderManager::DoLoad(const string& name, const string& path)
	{
		//string fileName = FileUtils::GET_FILE_NAME(path);
		//string vertexShaderPath = FileUtils::GET_PATH(path) + fileName + ".vert";
		//string pixelShaderPath = FileUtils::GET_PATH(path) + fileName + ".frag";

		//string vertexShaderContent = FileUtils::READ_FILE(vertexShaderPath);
		//string pixelShaderContent = FileUtils::READ_FILE(pixelShaderPath);

		//GLuint vertexShader = CompileShader(name, ShaderType::VertexShader().GetShaderType(), vertexShaderContent);
		//GLuint pixelShader = CompileShader(name, ShaderType::FragmentShader().GetShaderType(), pixelShaderContent);

		Shader* shader = new Shader(name, path);

		//glDeleteShader(vertexShader);
		//glDeleteShader(pixelShader);

		return shader;
	}

	bool ShaderManager::DoSave(Shader* resource, const string& path)
	{
		return true;
	}

	GLuint ShaderManager::CompileShader(const string& name, GLenum shaderType, const string& shaderContent)
	{
		try
		{
			GLuint shaderId = glCreateShader(shaderType);
			const GLchar* shaderSource = shaderContent.c_str();
			glShaderSource(shaderId, 1, &shaderSource, NULL);
			glCompileShader(shaderId);

			GLint shaderCompiled = GL_FALSE;
			glGetShaderiv(shaderId, GL_COMPILE_STATUS, &shaderCompiled);
			if (shaderCompiled != GL_TRUE)
			{
				GLint blen = 0;
				GLsizei slen = 0;

				glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &blen);

				if (blen > 1)
				{
					GLchar* compiler_log = (GLchar*)malloc(blen);
					glGetInfoLogARB(shaderId, blen, &slen, compiler_log);
					free(compiler_log);
				}
				throw Exception("Shader '%s' compile error", name);
			}
			return shaderId;
		}
		catch (Exception ex)
		{
			//LogManager::GetInstance()->Print(MessageType::ERRORS, ex.What());
		}
		return -1;
	}
}