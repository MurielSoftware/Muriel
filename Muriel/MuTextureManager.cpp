#include "stdafx.h"
#include "MuTextureManager.h"
#include "MuTexture.h"
#include "MuException.h"
#include "MuLog.h"
#include "MuStringUtils.h"

namespace Muriel
{
	Texture* TextureManager::DoLoad(const string& name, const string& path)
	{
		int width;
		int height;
		int channels;

		unsigned char* textureData = SOIL_load_image(path.c_str(), &width, &height, &channels, SOIL_LOAD_AUTO);
		if (textureData == NULL)
		{
			LOG_ERROR("Texture %s loading problem");
			//throw Exception("Texture '%s' loading problem", name);
		}
		ColorFormat  colorFormat = channels == 4 ? ColorFormat::RGBA() : ColorFormat::_RGB();

		Texture* texture = new Texture(name, width, height, colorFormat, textureData);
		SOIL_free_image_data(textureData);

		return texture;
	}


	bool TextureManager::DoSave(Texture* resource, const string& path)
	{
		return true;
	}
}