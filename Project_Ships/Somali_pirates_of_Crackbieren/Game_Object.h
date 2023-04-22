#pragma once
#include <string>
#include <iostream>

using namespace std;

class Game_Object
{
public:
	Game_Object();
	Game_Object(int,int);
	string Name;
	int x,y;
};