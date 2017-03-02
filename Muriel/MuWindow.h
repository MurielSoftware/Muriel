#pragma once

#include "stdafx.h"

namespace Muriel
{
	class MURIEL_API Window
	{
	private:
		string _name;

		void Create();
		void Destroy();
		void RegisterWindowClass();
		void InitInstance();
		void InitFullScreen();
		void InitPixelFormat();
		void InitRenderingContext();
		void InitOpenGL();
	public:
		Window(string name);
		virtual ~Window();

		void ResizeWindow(unsigned width, unsigned height);
		bool IsCloseRequested();
	};
}