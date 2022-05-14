#pragma once
class Graphics
{
public: // Variables

	ID2D1Factory* factory;
	ID2D1HwndRenderTarget* renderTarget;
	ID2D1SolidColorBrush* brush;
	IDWriteTextFormat* textFormat;

public: // Functions

	Graphics();
	~Graphics();

	bool Init(HWND);
	
	void BeginDraw();
	void EndDraw();

	void FillScreen(float r, float g, float b);

	void DrawCircle(float x, float y, float radius, float r, float g, float b, float a, float t, bool f);
	void DrawRoundedRectangle(float r, float g, float b, float a, D2D1_RECT_F rect, float radiusX, float radiusY, float t);
	void DrawLine(float r, float g, float b, float a, D2D1_POINT_2F point0, D2D1_POINT_2F point1, float t);
	void ShowText();
};