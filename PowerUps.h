#pragma once

#include <iostream>
#include <windows.h>
#include <conio.h>
#include "pipeClass.h"

class powerUp
{
private:
	int powerUpX, powerUpY;
	int powerUpType = rand() % 3;

public:
	int getPowerUpX();
	void powerUpUpdatePosition(int x,int y);
	void spwanPowerUp();
	void movePowerUp();
	void deletePowerUp();
};



int  powerUp::getPowerUpX(void)
{
	return powerUpX;

}
void powerUp::powerUpUpdatePosition(int x,int y)
{

	powerUpX = x;
	powerUpY = y;
}


void powerUp::spwanPowerUp()
{
	gotoxy(powerUpX, powerUpY);
	cout << 'P';
}


void powerUp::deletePowerUp()
{
	gotoxy(powerUpX, powerUpY);
	cout <<' ';
}

void powerUp::movePowerUp()
{
	deletePowerUp();
	powerUpX--;
	gotoxy(powerUpX, powerUpY);
	cout << 'P';
}