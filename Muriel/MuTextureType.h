#pragma once

#include "stdafx.h"

namespace Muriel
{
	class TextureType
	{
	private:
		explicit TextureType(int textureType) :_textureType(textureType) {};
		int _textureType;
	public:
		static TextureType Texture1D() { return TextureType(GL_TEXTURE_1D); };
		static TextureType Texture2D() { return TextureType(GL_TEXTURE_2D); };
		static TextureType Texture3D() { return TextureType(GL_TEXTURE_3D); };
		static TextureType Texture1DArray() { return TextureType(GL_TEXTURE_1D_ARRAY); };
		static TextureType Texture2DArray() { return TextureType(GL_TEXTURE_2D_ARRAY); };
		static TextureType TextureRectangle() { return TextureType(GL_TEXTURE_RECTANGLE); };
		static TextureType TextureCubeMap() { return TextureType(GL_TEXTURE_CUBE_MAP); };
		static TextureType TextureCubeMapArray() { return TextureType(GL_TEXTURE_CUBE_MAP_ARRAY); };
		static TextureType TextureBuffer() { return TextureType(GL_TEXTURE_BUFFER); };
		static TextureType Texture2DMultisample() { return TextureType(GL_TEXTURE_2D_MULTISAMPLE); };
		static TextureType Texture2DMultisampleArray() { return TextureType(GL_TEXTURE_2D_MULTISAMPLE_ARRAY); };

		inline int GetType() { return _textureType; }
	};
}