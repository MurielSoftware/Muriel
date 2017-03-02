#pragma once

#include "MuSingleton.h"
#include "MuAbstractResourceManager.h"

namespace Muriel
{
	class MURIEL_API TextureManager : public AbstractResourceManager<Texture>, public Singleton<TextureManager>
	{
	private:
		static TextureManager* _instance;
	protected:
		virtual bool DoSave(Texture* resource, const string& path);
		virtual Texture* DoLoad(const string& name, const string& path);
	public:
	};
}