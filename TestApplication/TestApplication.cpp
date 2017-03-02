#include "stdafx.h"
#include "MuEngine.h"

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	Muriel::Engine engine;
	engine.Start();
    return 0;
}