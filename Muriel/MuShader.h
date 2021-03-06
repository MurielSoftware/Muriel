#pragma once

#include "stdafx.h"
#include "Vec3.h"
#include "Quat.h"
#include "Mat4x4.h"
#include "Color.h"
#include "MuObject.h"
#include "MuGL.h"

using namespace Glml;

namespace Muriel
{
	class MURIEL_API Shader : public Object
	{
	private:
		GLuint _programId;
		GLuint _vertexShaderId;
		GLuint _fragmentShaderId;

		unsigned CompileShader(ShaderType shaderType, const string& path);
	public:
		Shader();
		Shader(const string& name, const string& path);
		~Shader();

		inline GLuint GetProgramId() const { return _programId; }

		void Activate();
		void Deactivate();
		unsigned GetUniformLocation(const string& name);
		void Uniform1i(const string& name, unsigned location, const int i);
		void Uniform1f(const string& name, unsigned location, const float f);
		void Uniform2f(const string& name, unsigned location, const Glml::Vec2& v);
		void Uniform3f(const string& name, unsigned location, const Glml::Vec3& v);
		void Uniform4f(const string& name, unsigned location, const Glml::Color& c);
		void UniformArray(const string& name, unsigned location, float* values, int size);
		void UniformMat3x3(const string& name, unsigned location, bool transpose, const Glml::Mat3x3& m);
		void UniformMat4x4(const string& name, unsigned location, bool transpose, const Glml::Mat4x4& m);
	};
}