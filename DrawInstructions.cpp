#pragma once

#include "stdafx.h"

#include "Graphics.h"

float y = 0.0f;
float yVelocity = 0.0f;

bool Draw(Graphics* graphics)
{
	yVelocity += 0.2f;
	y += yVelocity;
	if (y >= 550)
	{
		y = 550;
		yVelocity = -15.0f;
	}
	graphics->BeginDraw();
	graphics->ClearScreen(0.0f, 0.0f, 0.5f);
	graphics->DrawCircle(375.0f, y, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f, 3.0f);
	graphics->EndDraw();

	return true;
}