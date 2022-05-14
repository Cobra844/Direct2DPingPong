#include "stdafx.h"

#include "Ball.h"

int WINAPI wWinMain(HINSTANCE, HINSTANCE, PWSTR, int)
{
	graphics = new Graphics();
	
	if (!graphics->Init(baseWindow.windowHandle))
	{
		delete graphics;
		exit(-3);
	}

	ball.properties.xPos = abs((originalWindowSize.right - originalWindowSize.left) / 2);
	ball.properties.yPos = abs((originalWindowSize.bottom - originalWindowSize.top) / 2);
	ball.properties.radius = 10.0F;
	ball.properties.colR = 1.0F;
	ball.properties.colG = 1.0F;
	ball.properties.colB = 1.0F;
	ball.properties.alpha = 1.0F;
	ball.properties.thickness = 1.0F;
	ball.properties.fillToggle = true;
	ball.properties.direction = 0;
	
	Pad pad;
	
	pad.leftPadProperties.colR = 1.0F;
	pad.leftPadProperties.colG = 1.0F;
	pad.leftPadProperties.colB = 1.0F;
	pad.leftPadProperties.point0 = D2D1::Point2F(25.0F, pad.leftPadProperties.yTop);
	pad.leftPadProperties.point1 = D2D1::Point2F(25.0F, pad.leftPadProperties.yBottom);
	pad.leftPadProperties.alpha = 1.0F;
	pad.leftPadProperties.thickness = 3.0F;

	pad.rightPadProperties.colR = 1.0F;
	pad.rightPadProperties.colG = 1.0F;
	pad.rightPadProperties.colB = 1.0F;
	pad.rightPadProperties.point0 = D2D1::Point2F(1255.0F, pad.rightPadProperties.yTop);
	pad.rightPadProperties.point1 = D2D1::Point2F(1255.0F, pad.rightPadProperties.yBottom);
	pad.rightPadProperties.alpha = 1.0F;
	pad.rightPadProperties.thickness = 3.0F;

	float xSpeedMultiplier = 4.5F;

	srand((unsigned)time(0) * 10000);

	float ySpeedMultiplier = rand() % 3 - 1;
	if (ySpeedMultiplier == 0) ySpeedMultiplier = 1;

	bool equalXValueLeftPad, equalXValueRightPad, equalYValueLeftPad, equalYValueRightPad;
	
	bool touchingLeftPad = false;
	bool touchingRightPad = false;

	while (true)
	{
		Sleep(1000/60);

		xSpeedMultiplier *= 1.001F;

		equalXValueLeftPad = false;
		equalYValueLeftPad = false;

		equalXValueRightPad = false;
		equalYValueRightPad = false;

		touchingLeftPad = false;
		touchingRightPad = false;

		for (float i = pad.leftPadProperties.yTop - ball.properties.radius; i < pad.leftPadProperties.yBottom + ball.properties.radius; i++)
		{
			if (i <= ball.properties.yPos + 1 && i >= ball.properties.yPos - 1) equalYValueLeftPad = true;
		}
		for (float i = pad.rightPadProperties.yTop; i < pad.rightPadProperties.yBottom; i++)
		{
			if (i <= ball.properties.yPos + 1 && i >= ball.properties.yPos - 1) equalYValueRightPad = true;
		}

		if (ball.properties.xPos <= (ball.properties.radius * 2) + 25.0F) equalXValueLeftPad = true;
		if (ball.properties.xPos >= originalWindowSize.right - originalWindowSize.left - (ball.properties.radius * 2) - 25.0F) equalXValueRightPad = true;

		if (equalXValueLeftPad && equalYValueLeftPad)
		{
			touchingRightPad = false;
			touchingLeftPad = true;
			xSpeedMultiplier *= -1.1F;
			equalXValueLeftPad = false;
			equalYValueLeftPad = false;

		}
		if (equalXValueRightPad && equalYValueRightPad)
		{
			touchingLeftPad = false;
			touchingRightPad = true;
			xSpeedMultiplier *= -1.1F;
			equalXValueRightPad = false;
			equalYValueRightPad = false;
		}
		if (ball.properties.xPos >= originalWindowSize.right - originalWindowSize.left - (ball.properties.radius * 2)) // Ball hit right wall, game over!
		{
			exit(0);
		}
		if (ball.properties.xPos <= ball.properties.radius * 2) // Ball hit left wall, game over!
		{
			exit(1);
		}
		if (ball.properties.yPos <= 0 + ball.properties.radius) // Ball hit top wall, rebound!
		{
			ball.properties.direction = -ball.properties.direction;
		}
		if (ball.properties.yPos >= originalWindowSize.bottom - ball.properties.radius)
		{
			ball.properties.direction = -ball.properties.direction;
		}

		graphics->BeginDraw();

		graphics->FillScreen(0.0F, 0.0F, 0.2F);

		ball.Draw();
		ball.Move(xSpeedMultiplier, ySpeedMultiplier, touchingLeftPad, touchingRightPad, pad.leftPadProperties.direction, pad.rightPadProperties.direction);

		pad.Draw();
		pad.MoveLeftPad(ball);
		pad.MoveRightPad(ball);

		graphics->EndDraw();

		if (PeekMessage(&baseWindow.windowMessage, baseWindow.windowHandle, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&baseWindow.windowMessage);
			DispatchMessage(&baseWindow.windowMessage);
		}
	}

	return 0;
}