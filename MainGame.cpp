// ScreenRender.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "birdClass.h"

using namespace std;

#define MAX_HEIGHT 20
#define MAX_LENGTH 120


char gameScreen[MAX_HEIGHT][MAX_LENGTH];
unsigned long long secondsPassed;



void showScreen()
{
	system("cls");
	system("color F0");
	for (unsigned int i = 0; i < MAX_HEIGHT; i++)
	{
		for (unsigned int j = 0; j < MAX_LENGTH; j++)
		{
			cout << gameScreen[i][j];
		}
	}
}


stupidBird jack;

void initialize()
{
	for (unsigned int i = 0; i < MAX_HEIGHT; i++)
	{
		for (unsigned int j = 0; j < MAX_LENGTH; j++)
		{
			switch (i)
			{
			case MAX_HEIGHT - 3:
				gameScreen[i][j] = '-';
				break;
			case MAX_HEIGHT - 2:
				gameScreen[i][j] = '/';
				break;
			case MAX_HEIGHT - 1:
				gameScreen[i][j] = '#';
				break;
			default:
				gameScreen[i][j] = ' ';
				break;
			}
		}
	}
}





void startGame()
{
	initialize();
	showScreen();
	dropDown = 1;
	while (true)
	{
		if (secondsPassed == 15)
		{
			dropDown++;
			secondsPassed = 0;
		}
		Sleep(80);
		if (_kbhit() && _getch() == 32)
		{
			dropDown = 1;
			jack.moveJackUp();
		}

		else
		{
			secondsPassed++;
			jack.moveJackDown();
		}
	}

}


void createTheMenu()
{
	int inputUser = 0;
	system("cls");
	TCHAR Title[] = L"FLAPPY BIRD";
	SetConsoleTitle(Title);
	cout << "" << endl;
	cout << " --------------------------------------------------------  " << endl;
	cout << "|                                                        | " << endl;
	cout << "|   **** *    **** **** **** *   *    ***  * ***  ***    | " << endl;
	cout << "|   *    *    *  * *  * *  * *   *    *  * * *  * *  *   | " << endl;
	cout << "|   ***  *    **** **** **** *****    ***  * ***  *  *   | " << endl;
	cout << "|   *    *    *  * *    *      *      *  * * *  * *  *   | " << endl;
	cout << "|   *    **** *  * *    *      *      ***  * *  * ***    | " << endl;
	cout << "|                                                        | " << endl;
	cout << " --------------------------------------------------------  " << endl;
	cout << "" << endl << endl;
	cout << "" << endl << endl;
	cout << "                     M E N U:    " << endl << endl;
	cout << "                  1: Start Game  " << endl << endl;
	cout << "                  2: Help        " << endl << endl;
	cout << "                  3: Credits     " << endl << endl;
	cout << "                  4: Exit        " << endl << endl;
	cin >> inputUser;
	if (inputUser == 1)
	{
		startGame();
	}
	if (inputUser == 4)
	{
		return;
	}
}

int main()
{

	createTheMenu();
	//Beep(1000, 50000000000);

	return 0;
}

