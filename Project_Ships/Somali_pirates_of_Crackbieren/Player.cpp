#include "Player.h"
#include <windows.h>
#include <iostream>
#include<fstream> 
#include <mciapi.h>

#pragma comment(lib, "winmm.lib")

using namespace std;



Player::Player()
{
	x = 0;
	y = 0;
}

Player::Player(int a1, int a2) :Users(a1, a2)
{

}

void Player::move(string coor, char** tab)
{
	if (tab[(int)coor[0] - 48][(int)coor[1] - 48] == 'S' || tab[(int)coor[0] - 48][(int)coor[1] - 48] == 'T')
		throw exception("You already shot there");
	if (tab[(int)coor[0] - 48][(int)coor[1] - 48] == (char)254)
	{
		tab[(int)coor[0] - 48][(int)coor[1] - 48] = 'T';
		mciSendString(L"play hit.mp3", NULL, 0, NULL);
	}
	else
	{
		tab[(int)coor[0] - 48][(int)coor[1] - 48] = 'S';
		mciSendString(L"play miss.mp3", NULL, 0, NULL);
	}
}

