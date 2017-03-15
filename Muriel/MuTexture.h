#pragma once

#include "stdafx.h"
#include "MuObject.h"
#include "MuGL.h"

namespace Muriel
{
	class MURIEL_API Texture : public Object
	{
	private:
		unsigned int _textureId;
	public:
		Texture(const string& name, unsigned int width, unsigned int height, ColorFormat format, const void* pixels);
		virtual ~Texture();

		inline unsigned int GetTextureId() const { return _textureId; }

		void Bind();
		void Unbind();
	};
}