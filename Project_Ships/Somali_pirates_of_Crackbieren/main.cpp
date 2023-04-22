#include <iostream>
#include <string>
#include "Game_Menager.h"
#include <windows.h>  
#include <mmsystem.h>
#include <mciapi.h>

using namespace std;

int main()
{
	string tmp;
	Game_Menager menager = Game_Menager(0,0);
	menager.start();
	Sleep(2000);

	cout << "\nLoad save?\n" << "YES[enter] NO[esc]\n";
	while (1)
	{
		if ((GetKeyState(VK_RETURN) & 0x8000))
		{
			try
			{
				menager.load();
			}
			catch (exception n)
			{
				cout <<n.what();
				Sleep(2000);
				system("cls");
				menager.placeShips();
				menager.quicksave();
			}
			break;
		}
		if ((GetKeyState(VK_ESCAPE) & 0x8000))
		{
			system("cls");
			menager.placeShips();
			menager.quicksave();
			break;
		}
	}
	system("cls");
	
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

	while (menager.status == 1)
	{
		
		menager.area_AI.print_game(menager.area_AI.tab,false);
		menager.area_Player.print_game(menager.area_Player.tab, true);
		
		cout << "Enter coordinates to shot\n or \"EXIT\" to exit\n";

		cin >> tmp;
		try
		{
			menager.Round(tmp);
			menager.quicksave();
		}
		catch (exception n)
		{
			cout << n.what() << endl;
			Sleep(2000);
		}
		system("cls");
	}
	if (menager.status)
	{
		if (menager.status == 2)
			cout << "You Win\n";
		else
			cout << "You Lose\n";
		menager.clearSave();
		return 0;
	}
	cout << "Do you want to save?\nYES[enter] NO[esc]\n";
	Sleep(500);
	while (1)
	{
		if ((GetKeyState(VK_RETURN) & 0x8000))
		{
			menager.save();
			break;
		}
		if ((GetKeyState(VK_ESCAPE) & 0x8000))
		{
			break;
		}
	}
	return 0;
}

