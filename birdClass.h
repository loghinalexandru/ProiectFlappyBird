#pragma once
#include <iostream>
#include"pipeClass.h"
#include "menuAndGameOver.h"

using namespace std;

char playerChar = 'J';
int dropDown;


class stupidBird
{
private:
	int birdx, birdy;
	int birdxCurrentPosition, birdyCurrentPosition;


public:
	stupidBird(int x,int y)
	{
		birdx = x;
		birdy = y;
		birdxCurrentPosition = birdx;
		birdyCurrentPosition = birdy;
	}
	void birdReset();
	void getPlayerChar();
	void moveBirdUp();
	void moveBirdDown();
	void eraseBird(int x, int y);
	void writeBird(int x, int y);
	int getBirdX();
	int getBirdY();
};

void stupidBird::birdReset()
{
	birdxCurrentPosition = birdx;
	birdyCurrentPosition = birdy;
}

int stupidBird::getBirdX()
{
	return birdxCurrentPosition;
}

int stupidBird::getBirdY()
{
	return birdyCurrentPosition;
}

void stupidBird::getPlayerChar()
{
	cout << "Choose you're ASCII bird : ";
	cin >> playerChar;
}


void stupidBird::eraseBird(int x, int y)
{
	gotoxy(x, y);
	cout << ' ';
}

void stupidBird::writeBird(int x, int y)
{
	gotoxy(x, y);
	setColor(14);
	cout << playerChar;
	setColor(2);
}

void stupidBird::moveBirdUp()
{
	eraseBird(birdxCurrentPosition, birdyCurrentPosition);
	birdyCurrentPosition -= 3;
	writeBird(birdxCurrentPosition, birdyCurrentPosition);
}

void stupidBird::moveBirdDown()
{
	eraseBird(birdxCurrentPosition, birdyCurrentPosition);
	birdyCurrentPosition += dropDown;
	writeBird(birdxCurrentPosition, birdyCurrentPosition);

}
