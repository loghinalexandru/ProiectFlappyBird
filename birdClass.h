#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include"pipeClass.h"

using namespace std;


#define MAX_HEIGHT 20
#define MAX_LENGTH 120

char playerChar = 'J';
int dropDown;


class stupidBird
{
private:
	int birdx, birdy;
	int birdxCurrentPosition, birdyCurrentPosition;


public:
	stupidBird()
	{
		birdx = 20;
		birdy = 10;
		birdxCurrentPosition = birdx;
		birdyCurrentPosition = birdy;
	}
	void getPlayerChar();
	void moveBirdUp();
	void moveBirdDown();
	void eraseBird(int x, int y);
	void writeBird(int x, int y);
	int getBirdX();
	int getBirdY();
};

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
	cout << playerChar;
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
