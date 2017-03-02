#pragma once

#include "stdafx.h"
#include "MuException.h"
#include <map>
//using namespace Logger;

namespace Muriel
{
	template <typename T> class AbstractResourceManager
	{
	private:
		map<string, T*> _resources;
	protected:
		virtual T* DoLoad(const string& name, const string& path) = 0;
		virtual bool DoSave(T* resource, const string& path) = 0;

		AbstractResourceManager()
		{
		}
	public:

		virtual ~AbstractResourceManager()
		{
			Clear();
		}

		virtual void Add(const string& name, T* resource)
		{
			_resources.insert(pair<string, T*>(name, resource));
		}

		virtual T* Get(const string& name)
		{
			if (_resources.count(name) == 0)
			{
				throw Exception("Resource %s was not found", name);
			}
			return _resources.at(name);
		}

		virtual T* Load(const string& name, const string& path)
		{
			try
			{
				T* resource = DoLoad(name, path);
				if (resource == NULL)
				{
					throw Exception("Resource %s was not loaded", name);
				}
				Add(name, resource);
				return resource;
			}
			catch (Exception ex)
			{
				//				LOG::PrintErrorMessage(ex.What());
			}
			return NULL;
		}

		virtual void Save(const string& name, const string& path)
		{
			T* resource = Get(name);
			if (resource != NULL)
			{
				DoSave(resource, path);
			}
		}

		virtual void Replace(const string& oldName, const string& newName, T* resource)
		{
			_resources.erase(oldName);
			Add(newName, resource);
		}

		virtual void Remove(const string& name)
		{
			T* resource = Get(name);
			delete resource;
			_resources.erase(name);
		}

		virtual void Clear()
		{
			for (const auto& resource : _resources)
			{
				delete resource.second;
			}
			_resources.clear();
		}
	};
}