// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "../glew-2.0.0/lib/Release/Win32/glew32.lib")
#pragma comment(lib, "../soil-1.16.0/lib/soil32.lib")

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

#ifdef MURIEL_EXPORTS
#define MURIEL_API __declspec(dllexport)
#else
#define MURIEL_API __declspec(dllimport)
#endif

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

extern HDC g_hDC;
extern HWND g_hWnd;
extern HGLRC g_hRC;
extern HINSTANCE g_hInstance;

// TODO: reference additional headers your program requires here
#include "../glew-2.0.0/include/GL/glew.h"
#include "../soil-1.16.0/src/SOIL.h"

#include <string>

#include "MuPrerequisities.h"
#include "MuConstants.h"

using namespace std;