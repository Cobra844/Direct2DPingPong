#pragma once
class Graphics
{
public: // Variables

	ID2D1Factory* factory;
	ID2D1HwndRenderTarget* renderTarget;
	ID2D1SolidColorBrush* brush;

public: // Functions

	Graphics();
	~Graphics();

	bool Init(HWND);
	
	void BeginDraw();
	void EndDraw();

	void ClearScreen(float, float, float);

	void DrawCircle(float, float, float, float, float, float, float, float);
	void DrawRoundedRectangle();
};