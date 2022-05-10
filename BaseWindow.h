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

protected:

	static LRESULT __stdcall WindowProcedure(HWND, UINT, WPARAM, LPARAM);
};