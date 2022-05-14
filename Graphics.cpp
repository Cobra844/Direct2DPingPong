#include "stdafx.h"

Graphics::Graphics()
{
	factory = NULL;
	renderTarget = NULL;
	brush = NULL;
}
Graphics::~Graphics()
{
	if (factory) factory->Release();
	if (renderTarget) renderTarget->Release();
	if (brush) brush->Release();
}

bool Graphics::Init(HWND windowHandle)
{
	HRESULT code = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &factory);
	if (code != S_OK) return false;

	RECT windowRect;
	GetClientRect(windowHandle, &windowRect);

	code = factory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(), D2D1::HwndRenderTargetProperties(windowHandle, D2D1::SizeU(windowRect.right, windowRect.bottom)), &renderTarget);
	if (code != S_OK) return false;

	return true;
}

void Graphics::BeginDraw() { renderTarget->BeginDraw(); }
void Graphics::EndDraw() { renderTarget->EndDraw(); }

void Graphics::FillScreen(float r, float g, float b) { renderTarget->Clear(D2D1::ColorF(r, g, b)); }

void Graphics::DrawCircle(float x, float y, float radius, float r, float g, float b, float a, float t, bool f)
{
	renderTarget->CreateSolidColorBrush(D2D1::ColorF(r, g, b, a), &brush);
	D2D1_ELLIPSE ellipse = D2D1::Ellipse(D2D1::Point2F(x, y), radius, radius);
	renderTarget->DrawEllipse(ellipse, brush, t); // "t" is thickness I think
	if (f) renderTarget->FillEllipse(ellipse, brush);
}

void Graphics::DrawRoundedRectangle(float r, float g, float b, float a, D2D1_RECT_F rect, float radiusX, float radiusY, float t) // Original paddle design that confused me - unused for now
{
	renderTarget->CreateSolidColorBrush(D2D1::ColorF(r, g, b, a), &brush);
	D2D1_ROUNDED_RECT roundedRect = D2D1::RoundedRect(rect, radiusX, radiusY);
	renderTarget->DrawRoundedRectangle(roundedRect, brush, t, 0);
}

void Graphics::DrawLine(float r, float g, float b, float a, D2D1_POINT_2F point0, D2D1_POINT_2F point1, float t)
{
	renderTarget->CreateSolidColorBrush(D2D1::ColorF(r, g, b, a), &brush);
	renderTarget->DrawLine(point0, point1, brush, t, 0);
}

void Graphics::ShowText()
{
	renderTarget->DrawTextW(L"Hello", 4, 0, { 50, 50, 100, 100 }, brush, D2D1_DRAW_TEXT_OPTIONS_NONE, DWRITE_MEASURING_MODE_NATURAL); // incomplete
}