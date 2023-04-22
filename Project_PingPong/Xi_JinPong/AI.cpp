#pragma once
#include "AI.h"

using namespace std;

AI::AI()
{
	x = 0;
	y = 0;
	vx = 0;
	vy = 0;
	sprite = ' ';
	bally = 0;
}

AI::AI(int x1, int x2, double x3, double x4, char x5, int x6,int x7) :Paddle(x1, x2, x3, x4, x5, x6,x7)
{
	bally = 0;
}

void AI::Move()
{
	if (y-vy > bally)
	{
		y = y - vy;
	}
	else if (y+vy < bally)
	{
		y = y + vy;
	}
}
