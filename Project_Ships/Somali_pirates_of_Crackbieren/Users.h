#pragma once
#include "Game_Object.h"
#include <string>
#include <map>

class Users : public Game_Object
{
public:
	map<string,char> ships;
	Users();
	Users(int, int);
	virtual void move(string,char**)=0;
	void save(string,char);
};

