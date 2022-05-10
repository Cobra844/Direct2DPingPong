#include "stdafx.h"

#include "Graphics.h"

Graphics::Graphics()
{
	factory = NULL;
	renderTarget = NULL;
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

void Graphics::ClearScreen(float r, float g, float b) { renderTarget->Clear(D2D1::ColorF(r, g, b)); }

void Graphics::DrawCircle(float x, float y, float radius, float r, float g, float b, float a, float t)
{
	renderTarget->CreateSolidColorBrush(D2D1::ColorF(r, g, b, a), &brush);
	renderTarget->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(x, y), radius, radius), brush, t); // "t" is thickness I think
}

void Graphics::DrawRoundedRectangle()
{
	exit(-69);
}