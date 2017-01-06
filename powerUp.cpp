#include "stdafx.h"
#include "powerUp.h"
#include "consoleFunctions.h"
#include <iostream>

using namespace std;


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
	setColor(15);
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
	setColor(2);

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