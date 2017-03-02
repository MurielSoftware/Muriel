#pragma once 

#include "stdafx.h"

namespace Muriel
{
	class ShaderType
	{
	private:
		explicit ShaderType(GLenum shaderType) :_shaderType(shaderType) {};
		GLenum _shaderType;
	public:
		static ShaderType VertexShader() { return ShaderType(GL_VERTEX_SHADER); };
		static ShaderType FragmentShader() { return ShaderType(GL_FRAGMENT_SHADER); };
		static ShaderType GeometryShader() { return ShaderType(GL_GEOMETRY_SHADER); };
		static ShaderType TesselationControlShader() { return ShaderType(GL_TESS_CONTROL_SHADER); };
		static ShaderType TesselationEvaluationShader() { return ShaderType(GL_TESS_EVALUATION_SHADER); };

		GLenum GetShaderType() const { return this->_shaderType; }
	};
}