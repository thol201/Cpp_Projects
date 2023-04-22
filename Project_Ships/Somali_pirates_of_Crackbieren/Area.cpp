#include "Area.h"
#include<Windows.h>
#include <string>
#include <iostream>
#include <fstream>

Area::Area()
{
	x = 0;
	y = 0;
	status = 0;
	object = NULL;
	tab = NULL;
}

Area::~Area()
{
	if (status)
		return;
	for (int i = 0; i < y; i++)
		delete[] tab[i];
	delete[] tab;
}

Area::Area(int a, int b):Game_Object(a,b)
{
	status = 1;
	object = NULL;
	tab = new char* [a];
	for (int i = 0; i < b; i++)
		tab[i] = new char[b];
	
}

void Area::prep()
{
	for (int i = 0; i < x; i++)
	{
		for (int f = 0; f < y; f++)
			tab[i][f] = 'O';
	}
}



void Area::print(char** tab2,bool error)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "  ";
	for (int f = 0; f < y; f++)
	{
		if (f == 0)
		{
			for (int i = 0; i < x; i++)
				cout << i << ' ';
			cout << endl;
		}
		switch (f)
		{
		case 0:
			cout << "A ";
			break;
		case 1:
			cout << "B ";
			break;
		case 2:
			cout << "C ";
			break;
		case 3:
			cout << "D ";
			break;
		case 4:
			cout << "E ";
			break;
		case 5:
			cout << "F ";
			break;
		case 6:
			cout << "G ";
			break;
		case 7:
			cout << "H ";
			break;
		case 8:
			cout << "I ";
			break;
		case 9:
			cout << "J ";
			break;
		default:
			break;
		}
		for (int i = 0; i < x; i++)
		{
			if (tab2[f][i] == 'O')
				SetConsoleTextAttribute(hConsole, 1);
			else if (tab2[f][i] == '#')
			{
				if(can_place(tab2)&&!error)
					SetConsoleTextAttribute(hConsole, 2);
				else
					SetConsoleTextAttribute(hConsole, 4);
			}
				cout << tab2[f][i] << ' ';
			SetConsoleTextAttribute(hConsole, 7);
		}
		cout << endl;
	}
}

void Area::print_game(char** tab2,bool player)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "  ";
	for (int f = 0; f < y; f++)
	{
		if (f == 0)
		{
			for (int i = 0; i < x; i++)
				cout << i << ' ';
			cout << endl;
		}
		switch (f)
		{
		case 0:
			cout << "A ";
			break;
		case 1:
			cout << "B ";
			break;
		case 2:
			cout << "C ";
			break;
		case 3:
			cout << "D ";
			break;
		case 4:
			cout << "E ";
			break;
		case 5:
			cout << "F ";
			break;
		case 6:
			cout << "G ";
			break;
		case 7:
			cout << "H ";
			break;
		case 8:
			cout << "I ";
			break;
		case 9:
			cout << "J ";
			break;
		default:
			break;
		}
		for (int i = 0; i < x; i++)
		{
			scanShip(tab2, f, i);
			if (tab2[f][i] == 'D')
			{
				SetConsoleTextAttribute(hConsole, 4);
				cout << (char)254 << ' ';
			}
			else if (tab2[f][i] == 'O' || tab2[f][i]==(char)254 && !player)
			{
				SetConsoleTextAttribute(hConsole, 1);					
				cout << 'O' << ' ';
			}
			else if(tab2[f][i] == 'O' || tab2[f][i] == (char)254 && player)
			{
				SetConsoleTextAttribute(hConsole, 7);
				cout << (char)254 << ' ';
			}
			else if (tab2[f][i] == 'T')
			{
				SetConsoleTextAttribute(hConsole, 4);
				cout << 'X' << ' ';
			}
			else if (tab2[f][i] == 'S')
			{
				SetConsoleTextAttribute(hConsole, 7);
				cout << 'X' << ' ';
			}
			
			SetConsoleTextAttribute(hConsole, 7);
		}
		cout << endl;
	}
}

bool Area::can_place(char** tab2)
{
	for (int f = 0; f < y; f++)
		for (int i = 0; i < x; i++)
		{
			if (tab2[f][i] == '#')
			{
				if (tab[f][i] == (char)254)
					return false;
				for (int k = f - 1; k <= f + 1; k++)
					for (int z = i - 1; z <= i + 1; z++)
					{
						if (k < 0 || k > y - 1 || z < 0 || z > x - 1)
							continue;
						if (tab2[k][z] == (char)254)
							return false;
					}
			}
		}


	return true;
}

void Area::insertShip(int size)
{
	bool comp=false;
	bool placed = false;
	int rotation = 0;
	int limiter=0;
	int tmp_x=x/2, tmp_y=y/2;
	char** tab2;
	tab2 = new char* [x];
	if (size % 2 == 0)
	{
		limiter = 1;
	}
	for (int i = 0; i < y; i++)
	{
		tab2[i] = new char[y];
	}
	while (!placed)
	{
		cout << "Use \"W,S,A,D\" to move\nPress \"R\" to rotate\n\"C\" to reset ships\n";
		for (int i = 0; i < y; i++)
		memcpy(tab2[i], tab[i], sizeof(char)*y);
		for (int i = 0; i < size; i++)
			if (rotation)
			{
				if (tmp_x + i - size / 2 >= 0 && tmp_x + i - size / 2 <= x - 1 && tmp_y >= 0 && tmp_y <= y - 1)
					tab2[ tmp_x + i - size / 2][ tmp_y] = '#';
				else
					comp = true;
			}
			else
			{
				if (tmp_y + i - size / 2 >= 0 && tmp_y + i - size / 2 <= y - 1 && tmp_x>=0 && tmp_x<=x - 1)
				tab2[ tmp_x][ tmp_y + i - size / 2] = '#';
				else
					comp = true;
			}
		if(tab2[tmp_x][tmp_y]== (char)254)
			comp = true;
		print(tab2,comp);

		while(1)
			if ((GetKeyState(VK_RETURN) & 0x8000))
			{
				if (can_place(tab2)&&!comp)
				{
					placeShip(tab2);
					placed = true;
					break;
				}
				else
				{
					cout << "Invalid position of a ship" << endl;
					Sleep(1000);
					break;
				}
				

			}
			else if ((GetKeyState(0x41) & 0x8000))//A
			{
				if (tmp_y - size / 2 > 0 && !rotation || (tmp_y - 1 >= 0 && rotation))
				tmp_y--;
				break;

			}
			else if ((GetKeyState(0x44) & 0x8000))//D
			{
				if (tmp_y+size/2 - limiter < y-1 && !rotation||(tmp_y + 1 < y&&rotation))
				tmp_y++;
				break;

			}
			else if ((GetKeyState(0x53) & 0x8000))//S
			{
				if (tmp_x + size / 2 - limiter < x - 1 && rotation || (tmp_x + 1 < x && !rotation))
				tmp_x++;
				break;

			}
			else if ((GetKeyState(0x57) & 0x8000))//W
			{
				if (tmp_x - size / 2 > 0 && rotation || (tmp_x - 1 >= 0 && !rotation))
				tmp_x--;
				break;

			}
			else if ((GetKeyState(0x52) & 0x8000))//R
			{
				if (rotation)
					rotation = 0;
				else
					rotation = 1;
				break;
			}
			else if ((GetKeyState(0x43) & 0x8000))//C
			{
				system("cls");
				throw exception("Reset");
			}
		Sleep(200);
		system("cls");
		comp = false;
	}
}

void Area::generateShip(int size)
{
	srand(time(NULL));
	bool comp = false;
	bool placed = false;
	int rotation = rand()%2;
	int tmp_x = rand()%10, tmp_y = rand()%10;
	char** tab2 = new char* [x];;
	for (int i = 0; i < y; i++)
	{
		tab2[i] = new char[y];
	}
	while (!placed)
	{
		for (int i = 0; i < y; i++)
			memcpy(tab2[i], tab[i], sizeof(char) * y);
		rotation = rand() % 2;
		tmp_x = rand() % 10;
		tmp_y = rand() % 10;
		if (rotation)
		{
			if (tmp_x - size >= 0)
			{
				for (int i = 0; i < size;i++)
				{
					tab2[tmp_x-i][tmp_y] = '#';
				}
				if (can_place(tab2))
				{
					placeShip(tab2);
					placed = true;
				}
			}
		}
		else
		{
			if (tmp_y + size < y - 1)
			{
				for (int i = 0; i < size; i++)
				{
					tab2[tmp_x][tmp_y+i] = '#';
				}
				if (can_place(tab2))
				{
					placeShip(tab2);
					placed = true;
				}
				
			}
		}

	}

}

void Area::placeShip(char** tab2)
{
	for (int f = 0; f < y; f++)
		for (int i = 0; i < x; i++)
		{
			if (tab2[f][i] == '#')
				tab[f][i] = (char)254;
		}

}

void Area::scanShip(char** tab2, int x, int y)
{
	int x2=x, y2=y;
	int size = 0;
	if (tab2[x][y] != 'T')
		return;
	while (x2 < 10) 
	{
		if (tab2[x2][y] == 'T')
			size++;
		else if (tab2[x2][y] == (char)254)
			return;
		else
			break;
		x2++;
	}
	x2 = x - 1;
	while (x2 >= 0)
	{
		if (tab2[x2][y] == 'T')
			size++;
		else if (tab2[x2][y] == (char)254)
			return;
		else
			break;
		x2--;
	}
	y2++;
	while (y2 < 10)
	{
		if (tab2[x][y2] == 'T')
			size++;
		else if (tab2[x][y2] == (char)254)
			return;
		else
			break;
		y2++;
	}
	y2 = y - 1;
	while (y2 >= 0)
	{
		if (tab2[x][y2] == 'T')
			size++;
		else if (tab2[x][y2] == (char)254)
			return;
		else
			break;
		y2--;
	}
	if (!size)
		return;
	x2=x; 
	y2=y;
	if (x2+1<10&&tab2[x2 + 1][y2] == 'T')
	{
		for (int i = 0; i < size; i++)
			tab2[x2 + i][y2] = 'D';
	}
	else if (y2+1<10&&tab2[x2][y2+1] == 'T')
	{
		for (int i = 0; i < size; i++)
			tab2[x2][y2+i] = 'D';
	}
}

void Area::saveMap(string filename)
{
	ofstream MyFile(filename);
	for (auto n : object->ships)
	{
		MyFile << n.first << n.second << endl;
	}
}

void Area::loadMap(string filename)
{
	string tmp;
	string tmp2="";
	ifstream MyReadFile(filename);
	while (getline(MyReadFile, tmp))
	{
		if (tmp == "Empty")
			throw exception("Save file is empty\n");
		tmp2 += tmp[0];
		tmp2 += tmp[1];
		object->ships.insert(make_pair(tmp2, tmp[2]));
		tmp2 = "";
	}
}

void Area::insertToArea(int x1, int y1, char c)
{
	tab[x1][y1] = c;
}



