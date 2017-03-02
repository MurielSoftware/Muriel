#include "stdafx.h"
#include "MuShader.h"
#include "MuFileUtils.h"
#include "MuException.h"
#include "MuLog.h"

namespace Muriel
{
	Shader::Shader(const string& name, const string& path)
		: Object(name)
	{
		//_shaderId = glCreateProgram();
		//glAttachShader(_shaderId, vertexShader);
		//glAttachShader(_shaderId, pixelShader);
		//glLinkProgram(_shaderId);
		string fileName = FileUtils::GET_FILE_NAME(path);
		string vertexShaderPath = FileUtils::GET_PATH(path) + fileName + ".vert";
		string fragmentShaderPath = FileUtils::GET_PATH(path) + fileName + ".frag";
		
		_programId = GL::CreateProgram();
		_vertexShaderId = CompileShader(ShaderType::VertexShader(), vertexShaderPath);
		_fragmentShaderId = CompileShader(ShaderType::FragmentShader(), fragmentShaderPath);
		GL::AttachShaderToProgram(_programId, _vertexShaderId);
		GL::AttachShaderToProgram(_programId, _fragmentShaderId);
		GL::LinkProgram(_programId);
		if (!GL::CheckProgramLinkerStatus(_programId))
		{
			LOG_ERROR("Linking of failed.");
		}
	}

	Shader::~Shader()
	{
		GL::DeleteProgram(_programId);
	}

	void Shader::Activate()
	{
		GL::UseShader(_programId);
	}

	void Shader::Deactivate()
	{
		GL::UseShader(0);
	}

	void Shader::Uniformi(const string& name, const int i)
	{
		GLint location = GL::GetUniformLocation(_programId, name.c_str());
		GL::SetUniform(location, i);
	}

	void Shader::Uniform2f(const string& name, const Glml::Vec2& v)
	{
		GLint location = GL::GetUniformLocation(_programId, name.c_str());
		GL::SetUniform(location, v);
	}

	void Shader::Uniform3f(const string& name, const Glml::Vec3& v)
	{
		GLint location = GL::GetUniformLocation(_programId, name.c_str());
		GL::SetUniform(location, v);
	}

	void Shader::UniformArray(const string& name, float* values, int size)
	{
		GLint location = GL::GetUniformLocation(_programId, name.c_str());
		GL::SetUniform(location, size, values);
	}

	void Shader::UniformMat4x4(const string& name, bool transpose, const Glml::Mat4x4& m)
	{
		GLint location = GL::GetUniformLocation(_programId, name.c_str());
		GL::SetUniform(location, transpose, m);
	}

	unsigned Shader::CompileShader(ShaderType shaderType, const string& path)
	{
		string shaderData = FileUtils::READ_FILE(path);
		unsigned shader = GL::CreateShader(shaderType);
		GL::SetShaderDataSource(shader, 1, shaderData.c_str(), NULL);
		GL::CompileShader(shader);

		if (!GL::CheckShaderCompileStatus(shader, shaderType))
		{
			LOG_ERROR("Compile of failed.");
		}
		return shader;
	}
}