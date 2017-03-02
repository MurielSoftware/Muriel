#pragma once

namespace Muriel
{
	template<typename T> class Singleton
	{
	private:
		static T* INSTANCE;
	protected:
		Singleton()
		{
			INSTANCE = static_cast<T*>(this);
		}
	public:

		virtual ~Singleton()
		{
			delete INSTANCE;
			INSTANCE = NULL;
		}

		static T* GetInstance()
		{
			if (INSTANCE == NULL)
			{
				Singleton<T>::INSTANCE = new T();
			}
			return INSTANCE;
		}
	};

	template<typename T> T* Singleton<T>::INSTANCE = NULL;
}