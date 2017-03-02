#pragma once

#include "stdafx.h"

namespace Muriel
{
	class TextureParameterValue
	{
	private:
		explicit TextureParameterValue(int textureParameterValue) :_textureParameterValue(textureParameterValue) {};
		int _textureParameterValue;
	public:
		static TextureParameterValue ClampToEdge() { return TextureParameterValue(GL_CLAMP_TO_EDGE); };
		static TextureParameterValue Linear() { return TextureParameterValue(GL_LINEAR); };

		inline int GetValue() const { return _textureParameterValue; }
	};
}
