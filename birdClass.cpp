#include "stdafx.h"
#include "birdClass.h"
#include <iostream>
#include "consoleFunctions.h"


using namespace std;


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


void stupidBird::eraseBird(int x, int y)
{
	gotoxy(x, y);
	cout << ' ';
}

void stupidBird::writeBird(int x, int y)
{
	gotoxy(x, y);
	setColor(14);
	cout << playerBird;
	setColor(2);
}

void stupidBird::moveBirdUp()
{
	eraseBird(birdxCurrentPosition, birdyCurrentPosition);
	birdyCurrentPosition -= 3;
	writeBird(birdxCurrentPosition, birdyCurrentPosition);
}

void stupidBird::moveBirdDown(unsigned int dropDown)
{
	eraseBird(birdxCurrentPosition, birdyCurrentPosition);
	birdyCurrentPosition += dropDown;
	writeBird(birdxCurrentPosition, birdyCurrentPosition);

}