#include "stdafx.h"

#include "Ball.h"

#include "Pad.h"

void Pad::Draw()
{
	graphics->DrawLine(leftPadProperties.colR, leftPadProperties.colG, leftPadProperties.colB, leftPadProperties.alpha, leftPadProperties.point0, leftPadProperties.point1, leftPadProperties.thickness);
	graphics->DrawLine(rightPadProperties.colR, rightPadProperties.colG, rightPadProperties.colB, rightPadProperties.alpha, rightPadProperties.point0, rightPadProperties.point1, rightPadProperties.thickness);
}

bool Pad::MoveLeftPad(Ball ball)
{
	if (GetAsyncKeyState(0x57))
	{
		if (leftPadProperties.yTop >= originalWindowSize.top)
		{
			leftPadProperties.yTop -= 8;
			leftPadProperties.yBottom -= 8;

			leftPadProperties.point0 = D2D1::Point2F(originalWindowSize.left + 25.0F, leftPadProperties.yTop);
			leftPadProperties.point1 = D2D1::Point2F(originalWindowSize.left + 25.0F, leftPadProperties.yBottom);
		}
		leftPadProperties.direction = 1;
		return true;
	}
	else if (GetAsyncKeyState(0x53))
	{
		if (leftPadProperties.yBottom <= originalWindowSize.bottom)
		{
			leftPadProperties.yTop += 8;
			leftPadProperties.yBottom += 8;

			leftPadProperties.point0 = D2D1::Point2F(originalWindowSize.left + 25.0F, leftPadProperties.yTop);
			leftPadProperties.point1 = D2D1::Point2F(originalWindowSize.left + 25.0F, leftPadProperties.yBottom);
		}
		leftPadProperties.direction = -1;
		return true;
	}
	else
	{
		leftPadProperties.direction = 0;
		return false;
	}
}
bool Pad::MoveRightPad(Ball ball)
{
	if (GetAsyncKeyState(VK_UP))
	{
		if (rightPadProperties.yTop >= originalWindowSize.top)
		{
			rightPadProperties.yTop -= 8;
			rightPadProperties.yBottom -= 8;

			rightPadProperties.point0 = D2D1::Point2F(originalWindowSize.right - 25.0F, rightPadProperties.yTop);
			rightPadProperties.point1 = D2D1::Point2F(originalWindowSize.right - 25.0F, rightPadProperties.yBottom);
		}
		rightPadProperties.direction = 1;
		return true;
	}
	else if (GetAsyncKeyState(VK_DOWN))
	{
		if (rightPadProperties.yBottom <= originalWindowSize.bottom)
		{
			rightPadProperties.yTop += 8;
			rightPadProperties.yBottom += 8;

			rightPadProperties.point0 = D2D1::Point2F(originalWindowSize.right - 25.0F, rightPadProperties.yTop);
			rightPadProperties.point1 = D2D1::Point2F(originalWindowSize.right - 25.0F, rightPadProperties.yBottom);
		}
		rightPadProperties.direction = -1;
		return true;
	}
	else
	{
		rightPadProperties.direction = 0;
		return false;
	}
}