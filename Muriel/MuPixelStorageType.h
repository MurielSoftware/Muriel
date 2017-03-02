#pragma once

#include "stdafx.h"

namespace Muriel
{
	class PixelStorageType
	{
	private:
		explicit PixelStorageType(int pixelStorageType) :_pixelStorageType(pixelStorageType) {};
		int _pixelStorageType;
	public:
		static PixelStorageType PackAligment() { return PixelStorageType(GL_PACK_ALIGNMENT); };
		static PixelStorageType UnpackAligment() { return PixelStorageType(GL_UNPACK_ALIGNMENT); };

		inline int GetType() const { return _pixelStorageType; }
	};
}
