#include "stdafx.h"

#include "Pad.h"

void Ball::Draw()
{
	graphics->DrawCircle(properties.xPos, properties.yPos, properties.radius, properties.colR, properties.colG, properties.colB, properties.alpha, properties.thickness, properties.fillToggle);
}

void Ball::Move(float xSpeed, float ySpeed, bool touchingLeftPad, bool touchingRightPad, int leftPadDirection, int rightPadDirection)
{
	
	if (touchingLeftPad)
	{
		if (leftPadDirection == -1)
		{
			ball.properties.direction = abs(ySpeed);
		}
		else if (leftPadDirection == 0) {
			ball.properties.direction = 0;
		}
		else if (leftPadDirection == 1)
		{
			ball.properties.direction = -(abs(ySpeed));
		}
	}
	else if (touchingRightPad)
	{
		if (rightPadDirection == -1)
		{
			ball.properties.direction = abs(ySpeed);
		}
		else if (rightPadDirection == 0) {
			ball.properties.direction = 0;
		}
		else if (rightPadDirection == 1)
		{
			ball.properties.direction = -(abs(ySpeed));
		}
	}

	properties.xPos += xSpeed;
	properties.yPos += ball.properties.direction;
	
}