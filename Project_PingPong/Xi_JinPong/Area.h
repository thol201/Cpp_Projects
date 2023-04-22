#pragma once
#include <iostream>
#include "Player.h"
#include "AI.h"
#include "Ball.h"

using namespace std;

class Area
{
public:
	char player, ai;
	int x, y;
	char** tab;
	Area();
	Area(int, int);
	void print();
	void prep();
	void win();
	void lust();
	void add_elements(Player);
	void add_elements(AI);
	void add_elements(Ball);
};	