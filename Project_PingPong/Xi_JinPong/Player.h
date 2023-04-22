#pragma once
#include "Paddle.h"

class Player : public Paddle
{
public:
	//Area area;
	Player();
	Player(double, double, double, double, char, int,int);
	void Move();
};