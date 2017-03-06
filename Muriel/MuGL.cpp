#include "stdafx.h"
#include "MuGL.h"
#include "MuTexture.h"

namespace Muriel
{
	void GL::SetFrontFace(bool counterClockWise)
	{
		GLenum face = counterClockWise ? GL_CCW : GL_CW;
		glFrontFace(face);
	}

	void GL::EnableGraphicsMode(GraphicsMode graphicsMode)
	{
		glEnable(graphicsMode.GetMode());
	}

	void GL::DisableGraphicsMode(GraphicsMode graphicsMode)
	{
		glDisable(graphicsMode.GetMode());
	}

	void GL::SetPolygonMode(PolygonMode mode)
	{
		glPolygonMode(GL_FRONT_AND_BACK, mode.GetMode());
	}

	void GL::SetCullMode(CullMode mode)
	{
		glCullFace(mode.GetMode());
	}

	unsigned int GL::CreateProgram()
	{
		return glCreateProgram();
	}

	void GL::DeleteProgram(const unsigned int programIndex)
	{
		glDeleteProgram(programIndex);
	}

	void GL::AttachShaderToProgram(const unsigned int program, const unsigned int shader)
	{
		glAttachShader(program, shader);
	}

	void GL::DetachShaderFromProgram(const unsigned int program, const unsigned int shader)
	{
		glDetachShader(program, shader);
	}

	void GL::LinkProgram(const unsigned int programIndex)
	{
		glLinkProgram(programIndex);
	}

	void GL::UseShader(const unsigned int shaderIndex)
	{
		glUseProgram(shaderIndex);
	}

	unsigned int GL::CreateShader(ShaderType type)
	{
		return glCreateShader(type.GetShaderType());
	}

	void GL::CompileShader(const unsigned int shaderIndex)
	{
		glCompileShader(shaderIndex);
	}

	bool GL::CheckShaderCompileStatus(unsigned int shader, ShaderType shaderType)
	{
		bool success = true;
		GLint status;

		glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

		if (status == GL_FALSE)
		{
			success = false;

			GLint infoLogLength;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);

			GLchar *strInfoLog = new GLchar[infoLogLength + 1];
			glGetShaderInfoLog(shader, infoLogLength, NULL, strInfoLog);

			const char *strShaderType = NULL;
			switch (shaderType.GetShaderType())
			{
			case GL_VERTEX_SHADER: strShaderType = "vertex"; break;
			case GL_GEOMETRY_SHADER: strShaderType = "geometry"; break;
			case GL_FRAGMENT_SHADER: strShaderType = "fragment"; break;
			case GL_TESS_CONTROL_SHADER: strShaderType = "tesselation control"; break;
			case GL_TESS_EVALUATION_SHADER: strShaderType = "tesselation evaluation"; break;
			}
			fprintf(stderr, "Compile failure in %s shader:\n%s\n", strShaderType, strInfoLog);
			delete[] strInfoLog;
		}
		return success;
	}

	bool GL::CheckProgramLinkerStatus(const unsigned int programIndex)
	{
		bool success = true;
		GLint status;
		glGetProgramiv(programIndex, GL_LINK_STATUS, &status);

		if (status == GL_FALSE)
		{
			success = false;
			GLint infoLogLength;
			glGetProgramiv(programIndex, GL_INFO_LOG_LENGTH, &infoLogLength);

			//GLchar *strInfoLog = new GLchar[infoLogLength + 1];
			//glGetProgramInfoLog(programIndex, infoLogLength, NULL, strInfoLog);
			//fprintf(stderr, "Linker failure: %s\n", strInfoLog);
			//delete[] strInfoLog;
		}
		return success;
	}

	void GL::DeleteShader(const unsigned int shaderIndex)
	{
		glDeleteShader(shaderIndex);
	}

	void GL::SetShaderDataSource(const unsigned int shaderIndex, int numberOfElements, const char* shaderData, int* length)
	{
		glShaderSource(shaderIndex, numberOfElements, &shaderData, length);
	}

	const unsigned int GL::GetUniformLocation(const unsigned int shaderIndex, const char* uniformName)
	{
		return glGetUniformLocation(shaderIndex, uniformName);
	}


	void GL::SetUniform(const int uniformLocation, const int uniformValue)
	{
		glUniform1i(uniformLocation, uniformValue);
	}

	void GL::SetUniform(const int uniformLocation, const float uniformValue)
	{
		glUniform1f(uniformLocation, uniformValue);
	}

	void GL::SetUniform(const int uniformLocation, const int count, const float* uniformValue)
	{
		glUniform1fv(uniformLocation, count, uniformValue);
	}

	void GL::SetUniform(const int uniformLocation, const Vec2& uniformValue)
	{
		glUniform2fv(uniformLocation, 1, uniformValue.data);
	}

	void GL::SetUniform(const int uniformLocation, const Vec3& uniformValue)
	{
		glUniform3fv(uniformLocation, 1, uniformValue.data);
	}

	void GL::SetUniform(const int uniformLocation, bool transpose, const Mat3x3& uniformValue)
	{
		glUniformMatrix3fv(uniformLocation, 1, transpose, uniformValue.Pointer());
	}

	void GL::SetUniform(const int uniformLocation, bool transpose, const Mat4x4& uniformValue)
	{
		glUniformMatrix4fv(uniformLocation, 1, transpose, uniformValue.Pointer());
	}

	void GL::GenerateTextures(int count, unsigned int* textures)
	{
		glGenTextures(count, textures);
	}

	void GL::DeleteTextures(int count, unsigned int* textures)
	{
		glDeleteTextures(count, textures);
	}

	void GL::SetActiveTexture(int activeTexture)
	{
		GLenum textureEnum = GL_TEXTURE0 + activeTexture;
		glActiveTexture(textureEnum);
	}

	void GL::BindTexture(TextureType type, const int textureId)
	{
		glBindTexture(type.GetType(), textureId);
	}

	void GL::SetTextureParameter(TextureType type, TextureParameterType parameterType, TextureParameterValue parameterValue)
	{
		glTexParameteri(type.GetType(), parameterType.GetType(), parameterValue.GetValue());
	}

	void GL::SetPixelStorageType(PixelStorageType mode, int value)
	{
		glPixelStorei(mode.GetType(), value);
	}

	void GL::SetTextureData(TextureType type, int level, ColorFormat internalFormat, int width, int height, int border, ColorFormat format, GraphicsDataType dataType, const void* dataPointer)
	{
		glTexImage2D(type.GetType(), level, internalFormat.GetFormat(), width, height, border, format.GetFormat(), dataType.GetIndexDataType(), (GLvoid*)dataPointer);
	}

	void GL::EnableVertexAttribute(const unsigned int attributeIndex)
	{
		glEnableVertexAttribArray(attributeIndex);
	}

	void GL::SetVertexAttribute(const unsigned int attributeIndex, const int size, GraphicsDataType type, bool normalized, int stride, const void* attributePointer)
	{
		glVertexAttribPointer(attributeIndex, size, type.GetIndexDataType(), normalized, stride, attributePointer);
	}

	void GL::DisableVertexAttribute(const unsigned int attributeIndex)
	{
		glDisableVertexAttribArray(attributeIndex);
	}

	void GL::GenerateVertexArrays(int count, unsigned int* arrays)
	{
		glGenVertexArrays(count, arrays);
	}

	void GL::DeleteVertexArrays(int count, unsigned int* arrays)
	{
		glDeleteVertexArrays(count, arrays);
	}

	void GL::BindVertexArray(const unsigned int vertexArrayIndex)
	{
		glBindVertexArray(vertexArrayIndex);
	}

	void GL::GenerateBuffers(int count, unsigned int* buffers)
	{
		glGenBuffers(count, buffers);
	}

	void GL::DeleteBuffers(int count, unsigned int* buffers)
	{
		glDeleteBuffers(count, buffers);
	}

	void GL::BindBuffer(BufferType type, unsigned int bufferIndex)
	{
		glBindBuffer(type.GetBufferType(), bufferIndex);
	}
	
	void GL::SetBufferData(BufferType type, int sizeInBytes, const void* dataPointer, BufferUsage usage)
	{
		glBufferData(type.GetBufferType(), sizeInBytes, dataPointer, usage.GetBufferUsage());
	}

	void GL::DrawElements(GraphicsPrimitiveType primitiveType, int elements, GraphicsDataType indexType, const void* indicesLocation)
	{
		glDrawElements(primitiveType.GetType(), elements, indexType.GetIndexDataType(), (GLvoid*)indicesLocation);
	}

	void GL::DrawArrays(GraphicsPrimitiveType primitiveType, int firstIndex, int count)
	{
		glDrawArrays(primitiveType.GetType(), firstIndex, count);
	}
}