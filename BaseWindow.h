#pragma once

class BaseWindow
{
public: // Variables

	HWND windowHandle;
	RECT windowRect;
	WNDCLASSEX windowClass;
	MSG windowMessage;

public: // Functions

	BaseWindow();
	static LRESULT __stdcall WindowProcedure(HWND windowHandle, UINT uMsg, WPARAM wParam, LPARAM lParam);

};