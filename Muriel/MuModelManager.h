#pragma once

#include "MuAbstractResourceManager.h"
#include "MuModel.h"
#include "MuSingleton.h"

namespace Muriel
{
	class ModelManager : public AbstractResourceManager<Model>, public Singleton<ModelManager>
	{
	protected:
		virtual Model* DoLoad(const string& name, const string& path);
		virtual bool DoSave(Model* resource, const string& path);
	public:
	};
}