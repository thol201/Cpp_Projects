#include "Ball.h"
# include <iostream>

using namespace std;

Ball::Ball()
{
	vx = 0;
	vy = 0;

}

Ball::Ball(int x1, int x2, double x3, double x4, char x5):Moveable_Object(x1,x2,x3,x4,x5)
{
}

void Ball::Move()
{
	x = x + vx;
	y = y + vy;


}

