#include "Player.h"
#include "windows.h" 

#pragma once

using namespace std;

Player::Player()
{
	x = 0;
	y = 0;
	vx = 0;
	vy = 0;
	sprite = ' ';
	limitx = 0;
	limity = 0;
}

Player::Player(double x1, double x2, double x3, double x4, char x5, int x6,int x7):Paddle(x1,x2,x3,x4,x5,x6,x7)
{

}

void Player::Move()
{
	if((GetKeyState('W') & 0x8000))
	{
		if(y-1>1)
		y = y - 1;
	}
	else if ((GetKeyState('S') & 0x8000))
	{
		if (y + 1 < limity-2)
		y = y + 1;
	}
}
