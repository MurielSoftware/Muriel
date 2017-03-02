#include "stdafx.h"
#include "MuMouse.h"

namespace Muriel
{
	Mouse::~Mouse()
	{
		Detach();
	}

	BOOL Mouse::Init(bool mouseToCenter)
	{
		if (!_cursorVisible)
		{
			HideCursor(true);
		}

		_moveToWindowCenterPending = mouseToCenter;

		_pCurrButtonStates = _buttonStates[0];
		_pPrevButtonStates = _buttonStates[1];

		memset(_buttonStates, 0, sizeof(_buttonStates));

		RECT rcClient;

		GetClientRect(g_hWnd, &rcClient);
		_ptWindowCenterPos.x = (rcClient.right - rcClient.left) / 2;
		_ptWindowCenterPos.y = (rcClient.bottom - rcClient.top) / 2;

		return TRUE;
	}

	void Mouse::Detach()
	{
		if (!_cursorVisible)
		{
			HideCursor(false);
			_cursorVisible = false;
		}
	}

	void Mouse::HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		switch (msg)
		{
		case WM_MOUSEWHEEL:
			_wheelDelta += static_cast<int>(static_cast<int>(wParam) >> 16);
			break;
		default:
			break;
		}
	}

	void Mouse::HideCursor(bool hide)
	{
		if (hide)
		{
			_cursorVisible = false;
			ShowCursor(FALSE);
		}
		else
		{
			_cursorVisible = true;
			ShowCursor(TRUE);
		}
	}

	void Mouse::MoveTo(UINT x, UINT y)
	{
		POINT ptScreen = { x, y };

		ClientToScreen(g_hWnd, &ptScreen);
		SetCursorPos(ptScreen.x, ptScreen.y);

		_ptCurrentPos.x = x;
		_ptCurrentPos.y = y;
	}

	void Mouse::MoveToWindowCenter()
	{
		if (_ptWindowCenterPos.x != 0 && _ptWindowCenterPos.y != 0)
		{
			MoveTo(_ptWindowCenterPos.x, _ptWindowCenterPos.y);
		}
	}

	void Mouse::Update()
	{
		bool *pTempMouseStates = _pPrevButtonStates;

		_pPrevButtonStates = _pCurrButtonStates;
		_pCurrButtonStates = pTempMouseStates;

		_pCurrButtonStates[0] = (GetKeyState(VK_LBUTTON) & 0x8000) ? true : false;
		_pCurrButtonStates[1] = (GetKeyState(VK_RBUTTON) & 0x8000) ? true : false;
		_pCurrButtonStates[2] = (GetKeyState(VK_MBUTTON) & 0x8000) ? true : false;

		_mouseWheel = static_cast<float>(_wheelDelta - _prevWheelDelta) / static_cast<float>(WHEEL_DELTA);
		_prevWheelDelta = _wheelDelta;

		RECT rcClient;
		int width;
		int height;

		GetClientRect(g_hWnd, &rcClient);
		width = (rcClient.right - rcClient.left);
		height = (rcClient.bottom - rcClient.top);
		_ptWindowCenterPos.x = width / 2;
		_ptWindowCenterPos.y = height / 2;

		GetCursorPos(&_ptCurrentPos);
		ScreenToClient(g_hWnd, &_ptCurrentPos);

		_xDistFromWindowCenter = static_cast<float>(_ptCurrentPos.x - _ptWindowCenterPos.x);
		_yDistFromWindowCenter = static_cast<float>(_ptWindowCenterPos.y - _ptCurrentPos.y);

		if (_moveToWindowCenterPending)
		{
			MoveToWindowCenter();
		}
	}

	//void Mouse::CalculateMousePositionInScene()
	//{
	//	//double dx, dy, dz;
	//	//double modelview[16];
	//	//double projection[16];
	//	//int viewport[4];
	//	//Vector3 position2D;

	//	//glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
	//	//glGetDoublev(GL_PROJECTION_MATRIX, projection);
	//	//glGetIntegerv(GL_VIEWPORT, viewport);
	//	//position2D.x = _ptCurrentPos.x;
	//	//position2D.y = viewport[3] - _ptCurrentPos.y;
	//	//
	//	//glReadPixels(position2D.x, position2D.y, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &position2D.z);
	//	//gluUnProject(position2D.x, position2D.y, position2D.z, modelview, projection, viewport, &dx, &dy, &dz);

	//	//_mousePositionInScene = Vector3(dx, dy, dz);
	//}
}