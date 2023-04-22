#pragma once
#include <iostream>
#include "Ball.h"
#include "Area.h"
#include "Player.h"
#include "AI.h"


class Game_Menager
{
public:
	Moveable_Object** objects;
	Area area;
	Player player;
	AI ai;
	char player_sprite, ai_sprite;
	Ball ball;
	double diff,diff2;
	int game_time;
	int status;
	Game_Menager();
	Game_Menager(int,int);
	void Start();
	void Beggin();
	void Instantate();
	void Calc();
	void Stop(bool);
	void Collisions();
	void Trim();
};