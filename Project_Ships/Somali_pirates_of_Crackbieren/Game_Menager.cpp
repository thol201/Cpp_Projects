#include "Game_Menager.h"
#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

Game_Menager::Game_Menager(int a, int b):Game_Object(a,b)
{
	status = 0;
	maps = NULL;
	playable = NULL;
	x = a;
	y = b;
	
}

Game_Menager::Game_Menager()
{
	status = 0;
	playable = NULL;
	maps = NULL;
}

Game_Menager::~Game_Menager()
{
	delete[] playable;
	delete[] maps;
}

void Game_Menager::start()
{
	status = 1;
	player = Player();
	ai = Ai();
	playable = new Users*[2];
	playable[0] = &player;
	playable[1] = &ai;
	area_Player = Area(10, 10);
	area_Player.prep();
	area_AI = Area(10, 10);
	area_AI.prep();
	area_Player.Name = "Player Area";
	area_AI.Name = "AI Area";
	area_Player.object = &player;
	area_AI.object = &ai;
	maps = new Area * [2];
	maps[0]=&area_Player;
	maps[1]=&area_AI;
	//area_AI.status = 1;
	//area_Player.status = 1;
	
	cout << "      ___         ___         ___      ___                   ___         ___         ___         ___      \n";
	cout << "     /\\  \\       /\\  \\       /\\  \\    /\\  \\                 /\\  \\       /\\  \\       /\\__\\       /\\  \\     \n";
	cout << "    /::\\  \\     /::\\  \\     /::\\  \\   \\:\\  \\               /::\\  \\     /::\\  \\     /::|  |     /::\\  \\    \n";
	cout << "   /:/\\:\\  \\   /:/\\:\\  \\   /:/\\:\\  \\   \\:\\  \\             /:/\\:\\  \\   /:/\\:\\  \\   /:|:|  |    /:/\\:\\  \\   \n";
	cout << "  /::\\~\\:\\__\\ /:/  \\:\\  \\ /::\\~\\:\\  \\  /::\\  \\           /:/  \\:\\  \\ /::\\~\\:\\  \\ /:/|:|__|__ /::\\~\\:\\  \\  \n";
	cout << " /:/\\:\\ \\:|__/:/__/ \\:\\__/:/\\:\\ \\:\\__\\/:/\\:\\__\\         /:/__/_\\:\\__/:/\\:\\ \\:\\__/:/ |::::\\__/:/\\:\\ \\:\\__\\ \n";
	cout << " \\:\\~\\:\\/:/  \\:\\  \\ /:/  \\/__\\:\\/:/  /:/  \\/__/         \\:\\  /\\ \\/__\\/__\\:\\/:/  \\/__/~~/:/  \\:\\~\\:\\ \\/__/ \n";
	cout << "  \\:\\ \\::/  / \\:\\  /:/  /     \\::/  /:/  /               \\:\\ \\:\\__\\      \\::/  /      /:/  / \\:\\ \\:\\__\\   \n";
	cout << "   \\:\\/:/  /   \\:\\/:/  /      /:/  /\\/__/                 \\:\\/:/  /      /:/  /      /:/  /   \\:\\ \\/__/   \n";
	cout << "    \\::/__/     \\::/  /      /:/  /                        \\::/  /      /:/  /      /:/  /     \\:\\__\\     \n";
	cout << "     ~~          \\/__/       \\/__/                          \\/__/       \\/__/       \\/__/       \\/__/     \n";

}

void Game_Menager::placeShips()
{
	string tmp, myText;
	int reset = 0;
	while (!reset)
	{
		ifstream MyReadFile("config.dat");
		while (getline(MyReadFile, myText))
		{
			if (isdigit(myText[0]))
				for (int i = 0; i < (int)myText[0] - 48; i++)
				{
					if (reset == 2)
						break;
					try
					{
						area_Player.insertShip((int)myText[2] - 48);
					}
					catch (exception n)
					{
						reset = 2;
						break;
					}
					area_AI.generateShip((int)myText[2] - 48);
					
				}
			if (reset == 2)
			{
				reset = 0;
				area_Player.prep();
				area_AI.prep();
				break;
				system("cls");
			}
			else
				reset = 1;
		}
		MyReadFile.close();
	}
}
	

void Game_Menager::quicksave()
{
	string tmp="";
	for (int i = 0; i < area_AI.x; i++)
	for (int k = 0; k < area_AI.y; k++)
	{
		tmp += to_string(i);
		tmp += to_string(k);
		area_Player.object->save(encoder(tmp), area_Player.tab[i][k]);
		area_AI.object->save(encoder(tmp), area_AI.tab[i][k]);
		tmp = "";
	}
}

void Game_Menager::save()
{
	area_AI.saveMap("ai.txt");
	area_Player.saveMap("player.txt");
}

void Game_Menager::load()
{
	string tmp = "";
	area_Player.loadMap("player.txt");
	for (auto n : player.ships)
	{
		tmp += decoder(n.first);
		area_Player.insertToArea((int)tmp[0]-48, (int)tmp[1] -48, n.second);
		tmp = "";
	}
	area_AI.loadMap("ai.txt");
	for (auto n : ai.ships)
	{
		tmp += decoder(n.first);
		area_AI.insertToArea((int)tmp[0] - 48, (int)tmp[1] - 48, n.second);
		tmp = "";
	}
}

void Game_Menager::clearSave()
{
	ofstream MyFile("ai.txt");
	ofstream MyFile2("player.txt");
	MyFile << "Empty";
	MyFile2 << "Empty";
	MyFile.close();
	MyFile2.close();
}

void Game_Menager::Round(string coor)
{
	string tmp = coor;
	if (tmp == "EXIT")
	{
		status = 0;
		return;
	}
	if (!testString(tmp))
		throw exception("Invalid data");
	area_AI.status = 0;
	area_Player.status = 0;
	int hp = 0;
	for (int i = 0; i < 2; i++)
	{ 
		playable[i]->move(decoder(tmp),maps[(i+1)%2]->tab);
		for (int f = 0; f < 10; f++)
			for (int z = 0; z < 10; z++)
			{
				if (maps[(i + 1) % 2]->tab[f][z] == (char)254)
					hp++;
			}
		if (!hp)
			status = (i+1)%2+1;
		hp = 0;
	}
	
}

bool Game_Menager::testString(string txt)
{
	if (txt.length()>2)
		return false;
	char test = txt[0];
	if(test != 'A' && test != 'B' && test != 'C' && test != 'D' && test != 'E' && test != 'F' && test != 'G' && test != 'H' && test != 'I' && test != 'J')
		return false;
	test = txt[1];
	if (test != '0' && test != '1' && test != '2' && test != '3' && test != '4' && test != '5' && test != '6' && test != '7' && test != '8' && test != '9')
		return false;
	return true;
}

string Game_Menager::encoder(string code)
{
	string coded = "";
	switch (code[0])
	{
	case '0':
		coded += 'A';
		break;
	case '1':
		coded += 'B';
		break;
	case '2':
		coded += 'C';
		break;
	case '3':
		coded += 'D';
		break;
	case '4':
		coded += 'E';
		break;
	case '5':
		coded += 'F';
		break;
	case '6':
		coded += 'G';
		break;
	case '7':
		coded += 'H';
		break;
	case '8':
		coded += 'I';
		break;
	case '9':
		coded += 'J';
		break;
	default:
		throw ("ded");
	}
	coded += code[1];
	return coded;
}

string Game_Menager::decoder(string code)
{
	string decoded = "";
	switch (code[0])
	{
	case 'A':
		decoded += '0';
		break;
	case 'B':
		decoded += '1';
		break;
	case 'C':
		decoded += '2';
		break;
	case 'D':
		decoded += '3';
		break;
	case 'E':
		decoded += '4';
		break;
	case 'F':
		decoded += '5';
		break;
	case 'G':
		decoded += '6';
		break;
	case 'H':
		decoded += '7';
		break;
	case 'I':
		decoded += '8';
		break;
	case 'J':
		decoded += '9';
		break;
	default:
		throw ("ded");
	}
	decoded += code[1];
	return decoded;
}



