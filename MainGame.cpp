// ScreenRender.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include "birdClass.h"
#include "pipeClass.h"
#include "PowerUps.h"

using namespace std;


#define MAX_HEIGHT 20
#define MAX_LENGTH 120


std::vector<pipe> arrayOfPipes;
char gameScreen[MAX_HEIGHT][MAX_LENGTH];
long long playerHighScore;
unsigned long long secondsPassed;
bool renderedPowerUp;
powerUp perk;
unsigned int gameSpeed = 75;
bool noCollision;



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
	gotoxy(105, 10);
	cout << "Score:";
	cout << playerHighScore;
	gotoxy(105, 11);
	if (noCollision == true)
	{
		cout << "GodMode: ON";
	}
	else
	{
		for (unsigned int i = 105; i <120; i++)
		{
			gotoxy(i, 11);
			cout << ' ';
		}
	}



}

bool checkCollision()
{
	bool pipeCheck = false;
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
				if (noCollision == true)
				{
					playerHighScore++;
					displayScore();
				}
				return true;
			}
		}
	}
	return false;
}


void generatePowerUp()
{
	unsigned int randomPipe = rand() % 5;
	unsigned int randomPositionForPerk = rand() % 4;
	unsigned int perkX = arrayOfPipes[randomPipe].getPipeX() + 1, perkY = arrayOfPipes[randomPipe].getGapInThePipe() + randomPositionForPerk;
	perk.powerUpUpdatePosition(perkX, perkY);
}

void powerUpCheckCollision()
{
	if (jack.getBirdX() == perk.getPowerUpX() && (jack.getBirdY() == perk.getPowerUpY() || jack.getBirdY() + 1 == perk.getPowerUpY() || jack.getBirdY() - 1 == perk.getPowerUpY()))
	{
		perk.deletePowerUp();
		renderedPowerUp = false;
		switch (perk.getPowerUpType())
		{
		case 0:
			noCollision = true;
			displayScore();
			break;
		case 1:
			gameSpeed -= 10;
			break;
		case 2:
			playerHighScore *= 2;
			displayScore();
			break;


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

void startGame()
{
	unsigned int timeInGodMode = 0;
	initialize();
	showScreen();
	dropDown = 1;
	while (true)
	{
		if (noCollision == true)
		{
			timeInGodMode++;
			if (timeInGodMode == 115)
			{

				noCollision = false;
				displayScore();
				timeInGodMode = 0;
			}
		}
		if (secondsPassed == 15)
		{
			dropDown++;
			secondsPassed = 0;
		}
		Sleep(gameSpeed);
		if (_kbhit() && _getch() == 32)
		{
			dropDown = 1;

			if (jack.getBirdY() > 2)
			{
				jack.moveBirdUp();

			}
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
		}
		if (checkCollision() == true && noCollision == false)
		{
			gameOver();
			return;
		}
		if (playerHighScore % 10 == 0 && playerHighScore && renderedPowerUp == false)
		{
			perk.powerUpTypeRandomize();
			generatePowerUp();
			perk.spawnPowerUp();
			renderedPowerUp = true;
		}

		if (renderedPowerUp == true)
		{
			if (perk.getPowerUpX() == 1)
			{
				perk.deletePowerUp();
				renderedPowerUp = false;
			}
			else perk.movePowerUp();
			powerUpCheckCollision();
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
	cout << "           --------------------------------------------------------  " << endl;
	cout << "          |                                                        | " << endl;
	cout << "          |   **** *    **** **** **** *   *    ***  * ***  ***    | " << endl;
	cout << "          |   *    *    *  * *  * *  * *   *    *  * * *  * *  *   | " << endl;
	cout << "          |   ***  *    **** **** **** *****    ***  * ***  *  *   | " << endl;
	cout << "          |   *    *    *  * *    *      *      *  * * *  * *  *   | " << endl;
	cout << "          |   *    **** *  * *    *      *      ***  * *  * ***    | " << endl;
	cout << "          |                                                        | " << endl;
	cout << "           --------------------------------------------------------  " << endl;
	cout << "" << endl << endl;
	cout << "" << endl << endl;
	cout << "                               M E N U:    " << endl << endl;
	cout << "                            1: Start Game  " << endl << endl;
	cout << "                            2: Help        " << endl << endl;
	cout << "                            3: Credits     " << endl << endl;
	cout << "                            4: Exit        " << endl << endl;
	cin >> inputUser;
	if (inputUser == 1)
	{
		jack.getPlayerChar();
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
	return 0;
}

