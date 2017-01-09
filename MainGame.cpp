#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include "birdClass.h"
#include "pipeClass.h"
#include "powerUp.h"
#include "menuAndGameOver.h"
#include "consoleFunctions.h"
#include <ctime>

using namespace std;


vector<pipe> arrayOfPipes;
unsigned long long playerHighScore;
unsigned long long secondsPassed;
bool renderedPowerUp;
bool gameRunning = true;
unsigned int gameMode;
unsigned int dropDown;
powerUp perk;
unsigned int gameSpeed = 75;
bool noCollision;
stupidBird jack(20, 10);
stupidBird daniels(18, 10);
time_t gameStart, gameEnd, godModeStart, godModeEnd;


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
	gotoxy(103, 10);
	cout << "Score:";
	cout << playerHighScore;
	gotoxy(103, 11);

	if (noCollision == true)
	{
		cout << "GodMode: ON";
		gotoxy(103, 12);
		cout << "TimeRemaining:" << godModeStart - godModeEnd;
		if (godModeStart - godModeEnd < 10)
		{
			gotoxy(118, 12);
			cout << ' ';
		}
	}
	else
	{
		for (unsigned int i = 103; i < 120; i++)
		{
			gotoxy(i, 11);
			cout << ' ';
		}
		for (unsigned int i = 103; i < 120; i++)
		{
			gotoxy(i, 12);
			cout << ' ';
		}
	}
	setColor(2);
}
bool checkGroundCollision()
{
	if (jack.getBirdY() >= MAX_HEIGHT - 3)
	{
		return true;
	}
	else return false;

}

bool checkPipeCollision()
{
	bool pipeCheck = false;
	for (unsigned int i = 0; i < 5; i++)
	{
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
	unsigned int randomPipe = rand() % 3 + 2;
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
			godModeStart = time(NULL);
			godModeStart += 15;
			godModeEnd = time(NULL);
			displayScore();
			break;
		case 1:
			if (gameSpeed < 150)
			{
				gameSpeed += 10;
			}
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
	gameStart = time(NULL);
	system("cls");
	unsigned int timeInGodMode = 0;
	showScreen();
	dropDown = 1;
	while (true)
	{
		if (noCollision == true)
		{
			if (godModeStart - godModeEnd == 0)
			{
				noCollision = false;
				displayScore();
			}
			else
			{
				godModeEnd = time(NULL);
				displayScore();
			}
		}
		if (secondsPassed == 30)
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
			jack.moveBirdDown(dropDown);
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
		if (checkPipeCollision() == true && noCollision == false)
		{
			jack.writeBird(jack.getBirdX(), jack.getBirdY());
			Sleep(300);
			gameEnd = time(NULL);
			gameOver(playerHighScore, gameRunning, gameEnd - gameStart);
			return;
		}
		if (checkGroundCollision())
		{
			jack.writeBird(jack.getBirdX(), jack.getBirdY());
			Sleep(300);
			gameEnd = time(NULL);
			gameOver(playerHighScore, gameRunning, gameEnd - gameStart);
			return;
		}
		if (playerHighScore % 10 == 0 && playerHighScore && renderedPowerUp == false && gameMode)
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
	playerHighScore = 0;
	gameSpeed = 75;
}

int main()
{
	while (gameRunning)
	{
		switch (printMenu(gameRunning))
		{
		case 1:
			resetAll();
			generatePipesInArray();
			jack.getPlayerBird();
			gameMode = 0;
			startGame();
			break;
		case 2:
			resetAll();
			generatePipesInArray();
			jack.getPlayerBird();
			gameMode = 1;
			startGame();
			break;
		case 3:
			resetAll();
			generatePipesInArray();
			jack.getPlayerBird();

			gameMode = 1;
			startGame();
			break;
		case 4:
			gameInstructions();
			break;
		case 5:
			printWallOfLegends();
			break;
		case 6:
			resetAll();
			break;
		default:
			break;
		}
	}
	return 0;
}

