#include <string>
#include <iostream>
#include "Game_Menager.h"
#include "windows.h" 

using namespace std;

int main()
{
	Game_Menager game(50, 1);
	game.Beggin();

	bool session = true;
	while(session)
	{
		game.Start();
		game.Instantate();
		while (!(GetKeyState(VK_ESCAPE) & 0x8000) && game.status)
		{
			game.Calc();
			if (!game.status)
				break;
			game.area.print();
			//cout << game.diff2;
			Sleep(game.game_time);
			system("cls");
		}
		cout <<endl<< "Press Esc To Exit" << endl << "Press Enter to continue";
		while (!(GetKeyState(VK_RETURN) & 0x8000))
		{
			if ((GetKeyState(VK_ESCAPE) & 0x8000))
			{
				session = false;
				break;
			}
		}
	}
	
return 0;
}