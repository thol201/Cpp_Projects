#pragma once
#include "Users.h"



class Player : public Users
{
public:
	Player();
	Player(int, int);
	void move(string,char**);

};

