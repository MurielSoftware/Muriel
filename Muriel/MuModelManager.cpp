#include "stdafx.h"
#include "MuModelManager.h"
#include "MuMS3DImporter.h"
//#include "MuModel.h"

namespace Muriel
{
	Model* ModelManager::DoLoad(const string& name, const string& path)
	{
		//switch (FileUtils::GET_FILE_TYPE(path))
		//{
		//case MS3D:
			return MS3DImporter().Import(name, path);
			//case MLV:
			//	return MLVImporter().Import(name, path);
		//case MMF:
		//	return MMFImporter().Import(name, path);
		//}
	}

	bool ModelManager::DoSave(Model* resource, const string& path)
	{
		//switch (FileUtils::GET_FILE_TYPE(path))
		//{
		//	//case MLV:
		//	//	return MLVExporter().Export((MLVModel*)model, path);
		//case MMF:
		//	return MMFExporter().Export((MMFModel*)resource, path);
		//}
		return false;
	}
}