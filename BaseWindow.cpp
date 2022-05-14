#include "stdafx.h"

BaseWindow::BaseWindow()
{
	windowClass = { 0 };
	ZeroMemory(&windowClass, sizeof(WNDCLASSEX));

	windowRect = { 0, 0, 1280, 720 };
	originalWindowSize = windowRect;
	AdjustWindowRectEx(&windowRect, WS_OVERLAPPEDWINDOW, false, WS_EX_OVERLAPPEDWINDOW);

	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.lpfnWndProc = BaseWindow::WindowProcedure;
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

	LARGE_INTEGER performanceCounter, frequency;
	if (!QueryPerformanceCounter(&performanceCounter)) exit(-4);
	if (!QueryPerformanceFrequency(&frequency)) exit(-5);

	windowMessage.message = WM_NULL;
}

LRESULT __stdcall BaseWindow::WindowProcedure(HWND windowHandle, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_QUIT:
	case WM_DESTROY:
		delete graphics;
		exit(0);
		break;
	default:
		return DefWindowProc(windowHandle, uMsg, wParam, lParam);
		break;
	}
}