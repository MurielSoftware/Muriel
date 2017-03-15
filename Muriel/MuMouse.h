#include "stdafx.h"
#include "MuSingleton.h"

namespace Muriel
{
	class Mouse : public Singleton<Mouse> {
	private:
		int _wheelDelta;
		int _prevWheelDelta;
		float _mouseWheel;
		float _xDistFromWindowCenter;
		float _yDistFromWindowCenter;
		bool _moveToWindowCenterPending;
		bool _enableFiltering;
		bool _cursorVisible;
		bool _buttonStates[2][3];
		bool *_pCurrButtonStates;
		bool *_pPrevButtonStates;
		POINT _ptWindowCenterPos;
		POINT _ptCurrentPos;
	protected:
	public:
		virtual ~Mouse();

		enum MouseButton
		{
			BUTTON_LEFT = 0,
			BUTTON_RIGHT = 1,
			BUTTON_MIDDLE = 2
		};

		bool ButtonDown(MouseButton button) const { return _pCurrButtonStates[button]; }
		bool ButtonPressed(MouseButton button) const { return _pCurrButtonStates[button] && !_pPrevButtonStates[button]; }
		bool ButtonUp(MouseButton button) const { return !_pCurrButtonStates[button]; }
		bool CursorIsVisible() const { return _cursorVisible; }
		bool IsMouseSmoothing() const { return _enableFiltering; }
		float GetXDistanceFromWindowCenter() const { return _xDistFromWindowCenter; }
		float GetYDistanceFromWindowCenter() const { return _yDistFromWindowCenter; }
		int GetX() const { return _ptCurrentPos.x; }
		int GetY() const { return _ptCurrentPos.y; }
		float WheelPos() const { return _mouseWheel; }
		//inline Vector3 GetMousePositionInScene() const { return _mousePositionInScene; }

		BOOL Initialize(bool mouseToCenter);
		void Detach();
		void HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
		void HideCursor(bool hide);
		void MoveTo(UINT x, UINT y);
		void MoveToWindowCenter();
		void Update();
		//void CalculateMousePositionInScene();
	};
}