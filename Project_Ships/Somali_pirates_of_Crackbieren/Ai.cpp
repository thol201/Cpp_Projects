#include "Ai.h"

Ai::Ai()
{
	x = 0;
	y = 0;
}

Ai::Ai(int a1, int a2) :Users(a1, a2)
{

}

void Ai::move(string, char** tab)
{
	srand(time(NULL));
	int coor_x;
	int coor_y;
	while (1)
	{
		coor_x = rand() % 10;
		coor_y = rand() % 10;
		if (tab[coor_x][coor_y] == 'S' || tab[coor_x][coor_y] == 'T')
			continue;
		if (tab[coor_x][coor_y] == (char)254)
			tab[coor_x][coor_y] = 'T';
		else
			tab[coor_x][coor_y] = 'S';
		break;
	}
}
