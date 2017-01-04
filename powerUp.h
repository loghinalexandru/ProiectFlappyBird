#pragma once

#include <iostream>
#include "pipeClass.h"

class powerUp
{
private:
	int powerUpX, powerUpY;
	int powerUpType = 0;

public:
	int getPowerUpX();
	int getPowerUpY();
	void powerUpUpdatePosition(int x, int y);
	void spawnPowerUp();
	void movePowerUp();
	void deletePowerUp();
	int getPowerUpType();
	void powerUpTypeRandomize();
};


void powerUp::powerUpTypeRandomize()
{
	powerUpType = rand() % 3;
}

int powerUp::getPowerUpType()
{
	return powerUpType;
}

int  powerUp::getPowerUpX()
{
	return powerUpX;
}

int powerUp::getPowerUpY()
{
	return powerUpY;
}
void powerUp::powerUpUpdatePosition(int x, int y)
{

	powerUpX = x;
	powerUpY = y;
}


void powerUp::spawnPowerUp()
{
	gotoxy(powerUpX, powerUpY);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	switch (powerUpType)
	{
	case 0:
		cout << 'G';
		break;
	case 1:
		cout << 'S';
		break;
	case 2:
		cout << 'P';
		break;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);

}


void powerUp::deletePowerUp()
{
	gotoxy(powerUpX, powerUpY);
	cout << ' ';
}

void powerUp::movePowerUp()
{
	deletePowerUp();
	powerUpX--;
	spawnPowerUp();
}