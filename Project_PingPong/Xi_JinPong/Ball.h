#pragma once
#include "Moveable_Object.h"

class Ball : public Moveable_Object
{
public:
	Ball();
	Ball(int, int, double, double, char);
	void Move();


};