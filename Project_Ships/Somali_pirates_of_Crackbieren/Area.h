#pragma once
#include "Game_Object.h"
#include "Users.h"

class Area : public Game_Object
{
public:
	Users* object;
	int status;
	Area();
	~Area();
	Area(int, int);
	char** tab;
	void print(char**,bool);
	void print_game(char**,bool);
	bool can_place(char**);
	void prep();
	void insertShip(int);
	void generateShip(int);
	void placeShip(char**);
	void scanShip(char**,int, int);
	void saveMap(string);
	void loadMap(string);
	void insertToArea(int, int, char);
};

