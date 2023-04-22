#include "Game_Menager.h"
#include <limits>
#include <string>
#include <time.h>

Game_Menager::Game_Menager()
{
	game_time = 0;
	diff = 1;
	status = 0;
	objects = NULL;
	player_sprite = '1';
	ai_sprite = '2';
}

Game_Menager::Game_Menager(int x1, int x2)
{
	objects = NULL;
	status = 0;
	game_time = x1;
	diff = x2;
}

void Game_Menager::Start()
{
	objects = new Moveable_Object*[3];
	objects[0] = &ball;
	objects[1] = &player;
	objects[2] = &ai;
	area = Area(100, 25);
	diff2 = diff;
	status = 1;

}

void Game_Menager::Beggin()
{
	cout << "Chose Your Look - like '@' " << endl;
	cin >> player_sprite;
	cout << "Chose Enemy" << endl;
	cin >> ai_sprite;
	cout << "Chose Difficulty" << endl;
	cout << "1: Easy Difficulty" << endl;
	cout << "2: Medium Difficulty" << endl;
	cout << "3: Hard Difficulty" << endl;
	cout << "4: Imposible Difficulty" << endl;
	cin >> diff;
	switch ((int)diff)
	{
		case 1:
		{
			diff2 = 1;
			break;
		}
		case 2:
		{
			diff2 = 1.3;
			break;
		}
		case 3:
		{
			diff2 = 1.7;
			break;
		}
		case 4:
		{
			diff2 = 2;
			break;
		}
	}
}

void Game_Menager::Stop(bool s)
{
	status = 0;
	if (s == false)
		area.lust();
	else
		area.win();
}

void Game_Menager::Instantate()
{
	srand(time(NULL));

	double speed2,speed1 = (float)rand() / RAND_MAX +1*diff2 ;
	if (speed1 > .5)
	{
		speed2 = 1 - speed1;
	}
	else
	{
		speed2 = speed1;
		speed1 = 1 - speed2;
	}

	if (rand() % 2 == 1)
		speed2 = -speed2;

	area.player = player_sprite;
	area.ai = ai_sprite;

	player = Player(0,area.y / 2,0.,0.,area.player,area.x,area.y);
	ai = AI(area.x-1,area.y / 2, 0., 1.*diff2, area.ai, area.x, area.y);
	ball = Ball(area.x/2,area.y / 2, speed1, speed2, '+');
	
}

void Game_Menager::Collisions()
{

	char* tabb = new char[7];

	if ((int)ball.y - 2 < 0)
	{
		ball.y = 2;
	}
	else if ((int)ball.y + 2 >= area.y)
		ball.y = area.y - 3;

	if (ball.vx > 0)
	{
		tabb[0] = area.tab[(int)ball.y - 2][(int)ball.x + 2];
		tabb[1] = area.tab[(int)ball.y - 1][(int)ball.x + 2];
		tabb[2] = area.tab[(int)ball.y    ][(int)ball.x + 2];
		tabb[3] = area.tab[(int)ball.y + 1][(int)ball.x + 2];
		tabb[4] = area.tab[(int)ball.y + 2][(int)ball.x + 2];
		tabb[5] = area.tab[(int)ball.y + 2][(int)ball.x + 1];
		tabb[6] = area.tab[(int)ball.y - 2][(int)ball.x + 1];


		if (tabb[0] == 'X' || tabb[4] == 'X')
		{
			ball.vy = -ball.vy;
		}
		if ((tabb[0] == ai.sprite && tabb[1] != ai.sprite && tabb[6] != ai.sprite && ball.vy <0 ))
		{
			ball.vx = -ball.vx;
			ball.vy = -ball.vy;
		}
		else if ((tabb[4] == ai.sprite && tabb[3] != ai.sprite && tabb[5] != ai.sprite && ball.vy > 0))
		{
			ball.vx = -ball.vx;
			ball.vy = -ball.vy;
		}
		else if ((tabb[0] == ai.sprite && tabb[1] != ai.sprite && tabb[6] == ai.sprite) || (tabb[4] == ai.sprite && tabb[3] != ai.sprite && tabb[5] == ai.sprite))
		{
			ball.vy = -ball.vy;
		}
		else if (tabb[1] == ai.sprite || tabb[2] == ai.sprite || tabb[3] == ai.sprite)
		{
			ball.vx = -ball.vx;
			ball.vx = ball.vx * diff2;
			ball.vy = ball.vy * diff2;
			diff2 *= 1.1;
		}
	}
	else
	{
		

		tabb[0] = area.tab[(int)ball.y - 2][(int)ball.x - 2];
		tabb[1] = area.tab[(int)ball.y - 1][(int)ball.x - 2];
		tabb[2] = area.tab[(int)ball.y]    [(int)ball.x - 2];
		tabb[3] = area.tab[(int)ball.y + 1][(int)ball.x - 2];
		tabb[4] = area.tab[(int)ball.y + 2][(int)ball.x - 2];
		tabb[5] = area.tab[(int)ball.y + 2][(int)ball.x - 1];
		tabb[6] = area.tab[(int)ball.y - 2][(int)ball.x - 1];
		if (tabb[0] == 'X' || tabb[4] == 'X')
			ball.vy = -ball.vy;
		if ((tabb[0] == player.sprite && tabb[1] != player.sprite && tabb[6] != player.sprite && ball.vy < 0))
		{
			ball.vx = -ball.vx;
			ball.vy = -ball.vy;
		}
		else if ((tabb[4] == player.sprite && tabb[3] != player.sprite && tabb[5] != player.sprite)&& ball.vy > 0)
		{
			ball.vx = -ball.vx;
			ball.vy = -ball.vy;
		}
		else if ((tabb[0] == player.sprite && tabb[1] != player.sprite && tabb[6] == player.sprite) || (tabb[4] == player.sprite && tabb[3] != player.sprite && tabb[5] == player.sprite))
		{
			ball.vy = -ball.vy;
		}
		else if (tabb[1] == player.sprite || tabb[2] == player.sprite || tabb[3] == player.sprite)
		{
			ball.vx = -ball.vx;
			ball.vx = ball.vx * diff2;
			ball.vy = ball.vy * diff2;
			diff2 *= 1.1;
		}
	}
	delete[] tabb;
	if (diff2 > 4)
		diff2 = 4;
	Trim();
}

void Game_Menager::Trim()
{
	if (ball.vy > 2)
		ball.vy = 2;
	else if (ball.vy < -2)
		ball.vy = -2;
	if (ball.vx > 2.5)
		ball.vx = 2.5;
	else if (ball.vx < -2.5)
		ball.vx = -2.5;
}

void Game_Menager::Calc()
{
	area.prep();
	ai.bally = ball.y;
	area.add_elements(player);
	area.add_elements(ai);

	Collisions();

	area.add_elements(ball);


	for (int i = 0; i < 3; i++)
	{
		objects[i]->Move();
	}
	if (ball.x >= area.x - 1)
	{
		Stop(true);
		return;
	}
	else if (ball.x <= 0)
	{
		Stop(false);
		return;
	}
}
