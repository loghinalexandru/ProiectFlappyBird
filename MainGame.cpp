// ScreenRender.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include "birdClass.h"
#include "pipeClass.h"
#include "powerUp.h"
#include "menuAndGameOver.h"

using namespace std;


std::vector<pipe> arrayOfPipes;
unsigned long long playerHighScore;
unsigned long long secondsPassed;
bool renderedPowerUp;
powerUp perk;
unsigned int gameSpeed = 75;
bool noCollision;
stupidBird jack(20,10);


void generatePipesInArray()
{
	int time = 119;
	for (unsigned int i = 0; i < 5; i++)
	{
		arrayOfPipes.push_back(pipe(time));
		time -= 20;
	}
}

void initialize(int positionY, char element)
{
	for (unsigned int i = 0; i < MAX_LENGTH; i++)
	{
		gotoxy(i, positionY);
		cout << element;
	}
}

void showScreen()
{
	system("cls");
	setColor(8);
	initialize(MAX_HEIGHT - 1, '/');
	initialize(MAX_HEIGHT - 2, '/');
	initialize(MAX_HEIGHT - 3, 176);
	setColor(2);
}


void displayScore()
{
	setColor(15);
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
	setColor(2);
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
	unsigned int randomPipe = rand() % 5 + 2;
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



void startGame()
{
	system("cls");
	unsigned int timeInGodMode = 0;
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
			jack.writeBird(jack.getBirdX(), jack.getBirdY());
			Sleep(300);
			gameOver(playerHighScore);
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


void resetAll()
{

	jack.birdReset();
	arrayOfPipes.clear();
}

int main()
{
	while (gameRunnig)
	{
		switch (printMenu())
		{
		case 1:
			resetAll();
			generatePipesInArray();
			jack.getPlayerChar();
			startGame();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			resetAll();
			break;
		default:
			break;
		}
	}
	return 0;
}

