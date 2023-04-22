#pragma once
#include <iostream>

class Moveable_Object
{
public:
	double x, y;
	double vx, vy;
	char sprite;
	Moveable_Object();
	Moveable_Object(double,double,double,double,char);
	virtual void Move()=0;
};
