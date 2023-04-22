#pragma once
#include "Area.h"


using namespace std;
Area::Area()
{
	player = ' ';
	ai = ' ';
	x = 0;
	y = 0;
	char **tab = NULL;
}

Area::Area(int x1, int x2)
{
	player = ' ';
	ai = ' ';
	x = x1+2, y = x2+2;
	tab = new char *[y];
	for (int i = 0; i < y; i++)
	{
		tab[i] = new char[x];
	}



	for (int k = 0; k < x; k++)
		for (int i = 0; i < y; i++)
		{
			if (i == 0 || i == y - 1)
				tab[i][k] = 'X';
			else
				tab[i][k] = '0';
				//cout << tab[0][i];
		}
}

void Area::print()
{
	string* output = new string[y];
	string out="";
	for (int i = 0; i < y; i++)
	{
		output[i] = "";
		for (int k = 0; k < x; k++)
			output[i] += tab[i][k];
		out += output[i] + "\n";
	}
	cout << out << endl;
	delete[] output;
}

void Area::add_elements(Player obj)
{
	for (int i = 0; i < 3; i++)
		for (int k = 0; k < 5; k++)
			tab[(int)obj.y-2+k][(int)obj.x+i] = player;
}


void Area::add_elements(AI obj)
{
	for (int i = 0; i < 3; i++)
		for (int k = 0; k < 5; k++)
		tab[(int)obj.y - 2 + k][(int)obj.x - i] = ai;
}

void Area::add_elements(Ball obj)
{
	for (int i = 0; i < 3; i++)
		for (int k = 0; k < 3; k++)
			tab[(int)obj.y - 1 + k][(int)obj.x + i-1] = '+';

}

void Area::prep()
{
	for (int k = 0; k < x; k++)
		for (int i = 0; i < y; i++)
		{
			if (i == 0 || i == y - 1)
				tab[i][k] = 'X';
			else
				tab[i][k] = ' ';
		}
}

void Area::win()
{

	cout <<"__   __              _    _  _        " << endl;
	cout <<"\\ \\ / /             | |  | |(_)" << endl;
	cout <<" \\ V / ___   _   _  | |  | | _  _ __  " << endl;
	cout <<"  \\ / / _ \\ | | | | | |/\\| || || '_ \\ " << endl;
	cout <<"  | || (_) || |_| | \\  /\\  /| || | | |" << endl;
	cout <<"  |_| \\___/  \\___/   \\/  \\/ |_||_| |_|" << endl;

		
}
void Area::lust()
{

	cout <<"__   __              _                  _   " << endl;
	cout <<"\\ \\ / /             | |                | |  " << endl;
	cout <<" \\ V / ___   _   _  | |      ___   ___ | |_ " << endl;
	cout <<"  \\ / / _ \\ | | | | | |     / _ \\ / __|| __|" << endl;
	cout <<"  | || (_) || |_| | | |____| (_) |\\__ \\| |_ " << endl;
	cout <<"  \\_/ \\___/  \\__,_| \\_____/ \\___/ |___/ \\__|" << endl;

		
}

