#pragma once
#include "Moveable_Object.h"


class Paddle : public Moveable_Object
{
public:
	double limitx,limity;
	Paddle();
	Paddle(double, double, double, double, char, int,int);
	virtual void Move()=0;
};