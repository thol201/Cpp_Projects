#include "Moveable_Object.h"

#include <iostream>


Moveable_Object::Moveable_Object()
{
	x = 0;
	y = 0;
	vx = 0;
	vy = 0;
	sprite = ' ';
}

Moveable_Object::Moveable_Object(double x1, double x2, double x3, double x4, char x5)
{
	x = x1;
	y = x2;
	vx = x3;
	vy = x4;
	sprite = x5;
}


void Moveable_Object::Move()
{

}
