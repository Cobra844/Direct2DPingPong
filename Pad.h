#pragma once

#include "Ball.h"

class Pad
{
public: // Variables

	struct LeftPadProperties
	{
		float colR;
		float colG;
		float colB;
		D2D1_POINT_2F point0;
		D2D1_POINT_2F point1;
		float alpha;
		float thickness;
		float yTop = 50.0F;
		float yBottom = 150.0F;
		int direction = 0; // 0 means pad is stationary, -1 means its moving down, 1 means its moving up - data used to determine ball direction.
	} leftPadProperties;

	struct RightPadProperties
	{
		float colR;
		float colG;
		float colB;
		D2D1_POINT_2F point0;
		D2D1_POINT_2F point1;
		float alpha;
		float thickness;
		float yTop = 50.0F;
		float yBottom = 150.0F;
		int direction = 0; // 0 means pad is stationary, -1 means its moving down, 1 means its moving up - data used to determine ball direction.
	} rightPadProperties;

public: // Functions
	
	void Draw();

	bool MoveLeftPad(Ball ball);
	bool MoveRightPad(Ball ball);
};

