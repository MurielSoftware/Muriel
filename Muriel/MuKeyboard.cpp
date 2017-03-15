#include "stdafx.h"
#include "MuKeyboard.h"

namespace Muriel
{
	Keyboard::~Keyboard()
	{
	}

	void Keyboard::Initialize()
	{
		_lastChar = 0;
		_pCurrKeyStates = _keyStates[0];
		_pPrevKeyStates = _keyStates[1];

		memset(_pCurrKeyStates, 0, 256);
		memset(_pPrevKeyStates, 0, 256);
	}

	void Keyboard::HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		switch (msg)
		{
		case WM_CHAR:
			_lastChar = static_cast<int>(wParam);
			break;
		default:
			break;
		}
	}

	void Keyboard::Update()
	{
		BYTE *pTempKeyStates = _pPrevKeyStates;

		_pPrevKeyStates = _pCurrKeyStates;
		_pCurrKeyStates = pTempKeyStates;

		GetKeyboardState(reinterpret_cast<BYTE*>(_pCurrKeyStates));
	}
}