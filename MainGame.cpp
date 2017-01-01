// ScreenRender.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include "birdClass.h"
#include "pipeClass.h"

using namespace std;


#define MAX_HEIGHT 20
#define MAX_LENGTH 120


std::vector<pipe> arrayOfPipes;
char gameScreen[MAX_HEIGHT][MAX_LENGTH];
long long playerHighScore;
unsigned long long secondsPassed;


void hideCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void generatePipesInArray()
{
	int time = 119;
	for (unsigned int i = 0; i < 5; i++)
	{
		arrayOfPipes.push_back(pipe(time));
		time -= 20;
	}
}

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

void displayScore()
{
	COORD pos;
	pos.X = 110;
	pos.Y = 10;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	cout << "Score:";
	cout << playerHighScore;

}

bool checkCollision()
{
	for (unsigned int i = 0; i < 5; i++)
	{
		if (jack.getBirdY() >= MAX_HEIGHT - 3)
		{
			return true;
		}
		if (arrayOfPipes[i].getPipeX() == jack.getBirdX() && jack.getBirdY() >= arrayOfPipes[i].getGapInThePipe() && jack.getBirdY() <= arrayOfPipes[i].getGapInThePipe() + 3)
		{
			playerHighScore++;
			displayScore();
			return false;

		}
		else
		{
			if (arrayOfPipes[i].getPipeX() == jack.getBirdX())
			{
				return true;
			}
		}
	}

}






void gameOver()
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

	//Beep(1000, 3000);


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
			jack.moveBirdUp();

		}

		else
		{
			secondsPassed++;
			jack.moveBirdDown();
		}

		for (unsigned int i = 0; i < 5; i++)
		{
			if (arrayOfPipes[i].getPipeX() == 0)
			{
				arrayOfPipes[i].deletePipe();
				arrayOfPipes[i].pipeReset(100);
			}
			else
			{
				arrayOfPipes[i].movePipeLeftByOne();

			}
			if (checkCollision() == true)
			{
				gameOver();
				return;
			}
		}
	}

}


void createTheMenu()
{
	int inputUser = 0;
	system("cls");
	TCHAR Title[] = L"FLAPPY BIRD";
	SetConsoleTitle(Title);
	hideCursor();
	generatePipesInArray();
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

