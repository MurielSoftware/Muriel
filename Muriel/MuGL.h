#pragma once

#include "MuGraphicsMode.h"
#include "MuCullMode.h"
#include "MuPolygonMode.h"
#include "MuShaderType.h"
#include "MuTextureType.h"
#include "MuTextureParameterType.h"
#include "MuBufferType.h"
#include "MuBufferUsage.h"
#include "MuGraphicsPrimitiveType.h"
#include "MuGraphicsDataType.h"
#include "MuColorFormat.h"
#include "MuPixelStorageType.h"
#include "MuTextureParameterValue.h"

#include "Vec2.h"
#include "Vec3.h"
#include "Mat4x4.h"
#include "Mat3x3.h"
#include "Color.h"

using namespace Glml;

namespace Muriel
{
	class GL
	{
	public:
		static void SetFrontFace(bool counterClockWise);
		static void EnableGraphicsMode(GraphicsMode graphicsMode);
		static void DisableGraphicsMode(GraphicsMode graphicsMode);
		static void SetPolygonMode(PolygonMode mode);
		static void SetCullMode(CullMode mode);
		static void ClearBuffers(bool color, bool depth, bool stencil);
		static void ClearColor(const Color& color);

		static unsigned int CreateProgram();
		static void DeleteProgram(const unsigned int programIndex);
		static void AttachShaderToProgram(const unsigned int program, const unsigned int shader);
		static void DetachShaderFromProgram(const unsigned int program, const unsigned int shader);
		static void LinkProgram(const unsigned int programIndex);

		static void UseShader(const unsigned int shaderIndex);
		static unsigned int CreateShader(ShaderType type);
		static void CompileShader(const unsigned int shaderIndex);
		static bool CheckShaderCompileStatus(unsigned int shader, ShaderType shaderType);
		static bool CheckProgramLinkerStatus(const unsigned int programIndex);
		static void DeleteShader(const unsigned int shaderIndex);
		static void SetShaderDataSource(const unsigned int shaderIndex, int numberOfElements, const char* shaderData, int* length);
		static const unsigned int GetUniformLocation(const unsigned int shaderIndex, const char* uniformName);
		static void SetUniform(const int uniformLocation, const int uniformValue);
		static void SetUniform(const int uniformLocation, const float uniformValue);
		static void SetUniform(const int uniformLocation, const int count, const float* uniformValue);
		static void SetUniform(const int uniformLocation, const Vec2& uniformValue);
		static void SetUniform(const int uniformLocation, const Vec3& uniformValue);
		static void SetUniform(const int uniformLocation, const Color& uniformValue);
		static void SetUniform(const int uniformLocation, bool transpose, const Mat3x3& uniformValue);
		static void SetUniform(const int uniformLocation, bool transpose, const Mat4x4& uniformValue);

		static void GenerateTextures(int count, unsigned int* textures);
		static void DeleteTextures(int count, unsigned int* textures);
		static void SetActiveTexture(int activeTexture);
		static void BindTexture(TextureType type, const int textureId);
		static void SetTextureParameter(TextureType type, TextureParameterType parameterType, TextureParameterValue parameterValue);
		static void SetPixelStorageType(PixelStorageType mode, int value);
		static void SetTextureData(TextureType type, int level, ColorFormat internalFormat, int width, int height, int border, ColorFormat format, GraphicsDataType dataType, const void* dataPointer);

		static void EnableVertexAttribute(const unsigned int attributeIndex);
		static void SetVertexAttribute(const unsigned int attributeIndex, const int size, GraphicsDataType type, bool normalized, int stride, const void* attributePointer);
		static void DisableVertexAttribute(const unsigned int attributeIndex);
		static void GenerateVertexArrays(int count, unsigned int* arrays);
		static void DeleteVertexArrays(int count, unsigned int* arrays);
		static void BindVertexArray(const unsigned int vertexArrayIndex);

		static void GenerateBuffers(int count, unsigned int* buffers);
		static void DeleteBuffers(int count, unsigned int* buffers);
		static void BindBuffer(BufferType type, unsigned int bufferIndex);
		static void SetBufferData(BufferType type, int sizeInBytes, const void* dataPointer, BufferUsage usage);

		static void DrawElements(GraphicsPrimitiveType primitiveType, int elements, GraphicsDataType indexType, const void* indicesLocation);
		static void DrawArrays(GraphicsPrimitiveType primitiveType, int firstIndex, int count);
	};
}