#include "stdafx.h"
#include "MuTexture.h"

namespace Muriel
{
	Texture::Texture(const string& name, unsigned int width, unsigned int height, ColorFormat format, const void* pixels)
		: Object(name)
	{
		GL::GenerateTextures(1, &_textureId);
		//glGenTextures(1, &_textureId);
		Bind();
		GL::SetTextureParameter(TextureType::Texture2D(), TextureParameterType::TextureMinFilter(), TextureParameterValue::Linear());
		GL::SetTextureParameter(TextureType::Texture2D(), TextureParameterType::TextureMagFilter(), TextureParameterValue::Linear());
		GL::SetTextureData(TextureType::Texture2D(), 0, format, width, height, 0, format, GraphicsDataType::UnsignedByte(), pixels);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		//glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, pixels);
		Unbind();
	}

	Texture::~Texture()
	{
		GL::DeleteTextures(1, &_textureId);
		//glDeleteTextures(1, &_textureId);
	}

	void Texture::Bind()
	{
		//glEnable(GL_TEXTURE_2D);
		//glActiveTexture(GL_TEXTURE0);
		GL::BindTexture(TextureType::Texture2D(), _textureId);
		//glBindTexture(GL_TEXTURE_2D, _textureId);
	}

	void Texture::Unbind()
	{
		GL::BindTexture(TextureType::Texture2D(), 0);
		//glBindTexture(GL_TEXTURE_2D, 0);
		//glDisable(GL_TEXTURE_2D);
	}
}