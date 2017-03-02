#pragma once

#include "stdafx.h"

namespace Muriel
{
	class TextureParameterType
	{
	private:
		explicit TextureParameterType(int textureParameterType) :_textureParameterType(textureParameterType) {};
		int _textureParameterType;
	public:
		static TextureParameterType DepthStencilTextureMode() { return TextureParameterType(GL_DEPTH_STENCIL_TEXTURE_MODE); };
		static TextureParameterType TextureBaseLevel() { return TextureParameterType(GL_TEXTURE_BASE_LEVEL); };
		static TextureParameterType TextureBorderColor() { return TextureParameterType(GL_TEXTURE_BORDER_COLOR); };
		static TextureParameterType TextureCompareFunction() { return TextureParameterType(GL_TEXTURE_COMPARE_FUNC); };
		static TextureParameterType TextureCompareMode() { return TextureParameterType(GL_TEXTURE_COMPARE_MODE); };
		static TextureParameterType TextureLODBias() { return TextureParameterType(GL_TEXTURE_LOD_BIAS); };
		static TextureParameterType TextureMinFilter() { return TextureParameterType(GL_TEXTURE_MIN_FILTER); };
		static TextureParameterType TextureMagFilter() { return TextureParameterType(GL_TEXTURE_MAG_FILTER); };
		static TextureParameterType TextureMinLOD() { return TextureParameterType(GL_TEXTURE_MIN_LOD); };
		static TextureParameterType TextureMaxLOD() { return TextureParameterType(GL_TEXTURE_MAX_LOD); };
		static TextureParameterType TextureMaxLevel() { return TextureParameterType(GL_TEXTURE_MAX_LEVEL); };
		static TextureParameterType TextureSwizzleR() { return TextureParameterType(GL_TEXTURE_SWIZZLE_R); };
		static TextureParameterType TextureSwizzleG() { return TextureParameterType(GL_TEXTURE_SWIZZLE_G); };
		static TextureParameterType TextureSwizzleB() { return TextureParameterType(GL_TEXTURE_SWIZZLE_B); };
		static TextureParameterType TextureSwizzleA() { return TextureParameterType(GL_TEXTURE_SWIZZLE_A); };
		static TextureParameterType TextureSwizzleRGBA() { return TextureParameterType(GL_TEXTURE_SWIZZLE_RGBA); };
		static TextureParameterType TextureWrapS() { return TextureParameterType(GL_TEXTURE_WRAP_S); };
		static TextureParameterType TextureWrapT() { return TextureParameterType(GL_TEXTURE_WRAP_T); };
		static TextureParameterType TextureWrapR() { return TextureParameterType(GL_TEXTURE_WRAP_R); };

		inline int GetType() const { return _textureParameterType; }
	};
}