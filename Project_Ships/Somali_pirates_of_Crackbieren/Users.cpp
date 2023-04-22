#include "Users.h"


Users::Users()
{
	x = 0;
	y = 0;
}

Users::Users(int a, int b)
{
	x = a;
	y = b;
}

void Users::move(string,char**)
{

}

void Users::save(string coor, char val)
{
	std::map<string, char>::iterator it;
	it = ships.find(coor);
	if (it == ships.end())
		ships.insert(make_pair(coor, val));
	else
		it->second = val;
}
