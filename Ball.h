#pragma once

#include "Pad.h"

#include "Ball.h"

class Ball
{
public:

	void Draw();

	void Move(float xSpeed, float ySpeed, bool touchingLeftPad, bool touchingRightPad, int leftPadDirection, int RightPadDirection);

	struct Properties
	{
		float xPos;
		float yPos;
		float radius;
		float colR;
		float colG;
		float colB;
		float alpha;
		float thickness;
		bool fillToggle;
		int direction; // 0 means ball is stationary, -1 means its moving down, 1 means its moving up - data used to determine ball direction.
	} properties;

};