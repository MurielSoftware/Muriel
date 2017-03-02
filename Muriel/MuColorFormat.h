#pragma once

#include "stdafx.h"

namespace Muriel
{
	class ColorFormat
	{
	private:
		explicit ColorFormat(GLenum format) :_format(format) {};
		GLenum _format;
	public:
		static ColorFormat RGBA() { return ColorFormat(GL_RGBA); };
		static ColorFormat _RGB() { return ColorFormat(GL_RGB); };
		static ColorFormat Red() { return ColorFormat(GL_RED); };

		inline GLenum GetFormat() const { return _format; }
	};
}
