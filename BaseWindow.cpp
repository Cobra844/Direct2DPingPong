#include "stdafx.h"

#include "BaseWindow.h"

#include "Graphics.h"

#include "DrawInstructions.h"

LRESULT __stdcall BaseWindow::WindowProcedure(HWND windowHandle, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(windowHandle, uMsg, wParam, lParam);
}

BaseWindow::BaseWindow()
{
	windowClass = { 0 };
	ZeroMemory(&windowClass, sizeof(WNDCLASSEX));

	windowRect = { 0, 0, 800, 600 };
	AdjustWindowRectEx(&windowRect, WS_OVERLAPPEDWINDOW, false, WS_EX_OVERLAPPEDWINDOW);

	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.lpfnWndProc = WindowProcedure;
	windowClass.lpszClassName = WindowClassName;
	windowClass.lpszMenuName = WindowMenuName;
	windowClass.cbClsExtra = NULL;
	windowClass.cbWndExtra = NULL;
	windowClass.hInstance = GetModuleHandle(NULL);
	windowClass.hbrBackground = CreateSolidBrush(RGB(192, 224, 255));
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	windowClass.hIconSm = NULL;
	windowClass.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&windowClass)) exit(-1);

	windowHandle = CreateWindowEx(NULL, windowClass.lpszClassName, windowClass.lpszMenuName, WS_SYSMENU | WS_VISIBLE, 100, 100, windowRect.right - windowRect.left, windowRect.bottom - windowRect.top, NULL, NULL, HInstance, NULL);

	if (!windowHandle) exit(-2);

	Graphics* graphics;
	graphics = new Graphics();

	if (!graphics->Init(windowHandle))
	{
		delete graphics;
		exit(-3);
	}

	windowMessage.message = WM_NULL;

	while ((windowMessage.message != WM_QUIT) and (windowMessage.message != WM_DESTROY))
	{
		if (PeekMessage(&windowMessage, NULL, 0, 0, PM_REMOVE))
		{
				TranslateMessage(&windowMessage);
			DispatchMessage(&windowMessage);
		}
		else
		{
			Draw(graphics);
		}
	}

	delete graphics;

	exit(0);
}