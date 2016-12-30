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
	int secondstillHeavyFall = 0;


public:
	stupidBird()
	{
		birdx = 20;
		birdy = 10;
		birdxCurrentPosition = birdx;
		birdyCurrentPosition = birdy;
	}
	void getPlayerChar();
	void moveJackUp();
	void moveJackDown();
	void eraseJack(int x, int y);
	void writeJack(int x, int y);
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
	system("cls");
}


void stupidBird::eraseJack(int x, int y)
{
	gotoxy(x, y);
	cout << ' ';
}

void stupidBird::writeJack(int x, int y)
{
	gotoxy(x, y);
	cout << playerChar;
}

void stupidBird::moveJackUp()
{
	eraseJack(birdxCurrentPosition, birdyCurrentPosition);
	birdyCurrentPosition -= 3;
	writeJack(birdxCurrentPosition, birdyCurrentPosition);
}

void stupidBird::moveJackDown()
{
	eraseJack(birdxCurrentPosition, birdyCurrentPosition);
	birdyCurrentPosition += dropDown;
	writeJack(birdxCurrentPosition, birdyCurrentPosition);

}
