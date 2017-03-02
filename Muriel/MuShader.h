#pragma once

#include "stdafx.h"
#include "Vec3.h"
#include "Quat.h"
#include "Mat4x4.h"
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
		Shader(const string& name, const string& path);
		~Shader();

		inline GLuint GetProgramId() const { return _programId; }

		void Activate();
		void Deactivate();
		void Uniformi(const string& name, const int i);
		void Uniform2f(const string& name, const Glml::Vec2& v);
		void Uniform3f(const string& name, const Glml::Vec3& v);
		void UniformArray(const string& name, float* values, int size);
		void UniformMat4x4(const string& name, bool transpose, const Glml::Mat4x4& m);
	};
}