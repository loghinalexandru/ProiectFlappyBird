#pragma once
#include "pipeClass.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void hideCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void gameOver(unsigned long long playerHighScore)
{
	system("cls");
	cout << " d8888b .db    db d8888b .db      d888888b  .o88b.  d888888b d888888b  .d8b.  d888888b d88888b\n";
	cout << " 88  `8D 88    88 88  `8D 88        `88'   d8P  Y8    `88'   `~~88~~' d8' `8b `~~88~~' 88\n";
	cout << " 88oodD' 88    88 88oooY' 88         88    8P          88       88    88ooo88    88    88ooooo\n";
	cout << " 88~~~   8     88 88~~~b. 88         88    8b          88       88    88~~~88    88    88~~~~~\n";
	cout << " 88      88b  d88 88   8D 88booo.   .88.    Y8b  d8   .88.      88    88   88    88    88.\n";
	cout << " 88      ~Y8888P' Y8888P' Y88888P Y888888P  `Y88P'  Y888888P    YP    YP   YP    YP    Y88888P\n";
	cout << '\n';
	cout << '\n';
	cout << "You got: " << playerHighScore << " points\n";
	cout << "RANK :";
	if (playerHighScore < 20)
	{
		cout << "Baboon\n";
	}
	else
	{
		if (playerHighScore > 50)
		{
			cout << "Drunk Student\n";
		}
		else
		{
			if (playerHighScore > 200)
			{
				cout << "GameMaster\n";

			}
			else
			{
				cout << "Rookie\n";
			}
		}
	}
	Beep(440, 500);
	Beep(440, 500);
	Beep(440, 500);
	Beep(349, 350);
	Beep(523, 150);
	Beep(440, 500);
	Beep(349, 350);
	Beep(523, 150);
	Beep(440, 1000);
}

int printMenu()
{
	system("color F0");
	hideCursor();
	cout << "" << endl;
	cout << "                              --------------------------------------------------------  " << endl;
	cout << "                             |                                                        | " << endl;
	cout << "                             |   **** *    **** **** **** *   *    ***  * ***  ***    | " << endl;
	cout << "                             |   *    *    *  * *  * *  * *   *    *  * * *  * *  *   | " << endl;
	cout << "                             |   ***  *    **** **** **** *****    ***  * ***  *  *   | " << endl;
	cout << "                             |   *    *    *  * *    *      *      *  * * *  * *  *   | " << endl;
	cout << "                             |   *    **** *  * *    *      *      ***  * *  * ***    | " << endl;
	cout << "                             |                                                        | " << endl;
	cout << "                              --------------------------------------------------------  " << endl;
	cout << "" << endl << endl;
	cout << "                                                      M E N U:    " << endl << endl;
	cout << "                                                   1: Start Game  " << endl << endl;
	cout << "                                                   2: Help        " << endl << endl;
	cout << "                                                   3: Credits     " << endl << endl;
	cout << "                                                   4: Exit        " << endl << endl;
	COORD pos;
	pos.X = 47;
	pos.Y = 14;
	gotoxy(pos.X, pos.Y);
	cout << "-->";
	while (true)
	{
		switch (_getch())
		{
		case 56: case 119:
			if (pos.Y != 14)
			{
				for (unsigned int i = pos.X; i < pos.X + 3; i++)
				{
					gotoxy(i, pos.Y);
					cout << ' ';
				}
				pos.Y -= 2;
				gotoxy(pos.X, pos.Y);
				cout << "-->";
			}
			break;
		case 50: case 115:
			if (pos.Y != 20)
			{
				for (unsigned int i = pos.X; i < pos.X + 3; i++)
				{
					gotoxy(i, pos.Y);
					cout << ' ';
				}
				pos.Y += 2;
				gotoxy(pos.X, pos.Y);
				cout << "-->";
			}
			break;

		case 13:
			if (pos.Y == 14)
			{
				return 1;
				break;
			}
			else if (pos.Y == 20)
			{
				return 0;
			}
		default:
			break;
		}
	}
}