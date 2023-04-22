#include "Paddle.h"
#pragma once
#include <iostream>


Paddle::Paddle()
{
	x = 0;
	y = 0;
	vx = 0;
	vy = 0;
	sprite = ' ';
	limitx = 0;
	limity = 0;
}

Paddle::Paddle(double x1, double x2, double x3, double x4, char x5, int x6,int x7) : Moveable_Object(x1,x2,x3,x4,x5)
{
	limitx = x6;
	limity = x7;
}

void Paddle::Move()
{
}
