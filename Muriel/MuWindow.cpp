#include "stdafx.h"
#include "MuWindow.h"
#include "MuException.h"

HDC g_hDC;
HWND g_hWnd;
HGLRC g_hRC;
HINSTANCE g_hInstance;

namespace Muriel
{
	Window::Window(string name)
	{
		_name = name;
		Create();
	}

	Window::~Window()
	{
		Destroy();
	}

	void Window::ResizeWindow(unsigned width, unsigned height)
	{
		glViewport(0, 0, width, height);
	}

	bool Window::IsCloseRequested()
	{
		MSG msg;
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				return true;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		return false;
	}

	void Window::Create()
	{
		try
		{
			RegisterWindowClass();
			InitFullScreen();
			InitInstance();
			InitPixelFormat();
			InitRenderingContext();
			InitOpenGL();
			ResizeWindow(640, 480);
		}
		catch (Exception ex)
		{
			//			LOG::PrintErrorMessage(ex.What());
		}
		ShowWindow(g_hWnd, SW_SHOWNORMAL);
		SetForegroundWindow(g_hWnd);
		SetFocus(g_hWnd);
	}

	void Window::RegisterWindowClass()
	{
		g_hInstance = GetModuleHandle(NULL);

		WNDCLASSEX wcex;
		wcex.cbSize = sizeof(WNDCLASSEX);
		wcex.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		wcex.lpfnWndProc = WndProc;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = g_hInstance;
		wcex.hIcon = NULL;
		wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
		wcex.hbrBackground = NULL;
		wcex.lpszMenuName = NULL;
		wcex.lpszClassName = _name.c_str();
		wcex.hIconSm = NULL;
		RegisterClassEx(&wcex);
	}

	void Window::InitInstance()
	{
		DWORD style = (false ? WS_POPUP : WS_OVERLAPPEDWINDOW) | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
		RECT windowRect;
		windowRect.left = 0;
		windowRect.right = 640;
		windowRect.top = 0;
		windowRect.bottom = 480;

		if (g_hWnd == NULL)
		{
			g_hWnd = CreateWindowEx(WS_EX_APPWINDOW, _name.c_str(), _name.c_str(), style, 0, 0, windowRect.right - windowRect.left, windowRect.bottom - windowRect.top, NULL, NULL, g_hInstance, NULL);
		}
		g_hDC = GetDC(g_hWnd);
	}

	void Window::InitFullScreen()
	{
		if (!false)
		{
			return;
		}
		DEVMODE devMode;
		memset(&devMode, 0, sizeof(DEVMODE));
		devMode.dmSize = sizeof(DEVMODE);
		devMode.dmPelsWidth = 640;
		devMode.dmPelsHeight = 480;
		devMode.dmBitsPerPel = 32;
		devMode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT | DM_BITSPERPEL;

		ChangeDisplaySettings(&devMode, CDS_FULLSCREEN);// == DISP_CHANGE_SUCCESSFUL;
	}

	void Window::InitPixelFormat()
	{
		int PixelFormat;

		PIXELFORMATDESCRIPTOR pfd;
		memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));
		pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
		pfd.nVersion = 1;
		pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
		pfd.iPixelType = PFD_TYPE_RGBA;
		pfd.cColorBits = 32;
		pfd.cDepthBits = 24;
		pfd.iLayerType = PFD_MAIN_PLANE;

		PixelFormat = ChoosePixelFormat(g_hDC, &pfd);
		SetPixelFormat(g_hDC, PixelFormat, &pfd);
	}

	void Window::InitRenderingContext()
	{
		g_hRC = wglCreateContext(g_hDC);
		wglMakeCurrent(g_hDC, g_hRC);
	}

	void Window::InitOpenGL()
	{
		if (glewInit() != GLEW_OK)
		{
			throw Exception("Extension not support");
		}
		glShadeModel(GL_SMOOTH);
		glClearDepth(1.0f);
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	}

	void Window::Destroy()
	{
		ChangeDisplaySettings(NULL, 0);
		wglMakeCurrent(NULL, NULL);
		wglDeleteContext(g_hRC);
		ReleaseDC(g_hWnd, g_hDC);
		DestroyWindow(g_hWnd);
		UnregisterClass(_name.c_str(), g_hInstance);
	}
}
