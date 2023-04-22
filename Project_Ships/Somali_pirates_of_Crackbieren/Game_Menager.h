#pragma once
#include "Game_Object.h"
#include "Player.h"
#include "Ai.h"
#include "Area.h"
#include<string>

using namespace std;


class Game_Menager : public Game_Object
{
public:
	int status;
	Game_Menager(int, int);
	Game_Menager();
	~Game_Menager();
	Area area_AI, area_Player;
	Area** maps;
	Users** playable;
	Player player;
	Ai ai;
	void start();
	void placeShips();
	void quicksave();
	void save();
	void load();
	void clearSave();
	void Round(string);
	bool testString(string);
	string encoder(string);
	string decoder(string);
};

