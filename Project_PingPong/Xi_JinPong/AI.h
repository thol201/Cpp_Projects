#pragma once
#include "Paddle.h"

class AI : public Paddle
{
public:
	int bally;
	AI();
	AI(int, int, double, double, char, int,int);
	void Move();

};