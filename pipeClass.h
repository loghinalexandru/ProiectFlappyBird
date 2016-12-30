#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

#define MAX_HEIGHT 20
#define MAX_LENGTH 120

void gotoxy(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

class pipe
{
private:
	char pipeChar = '#';
	int pipex, pipey;
	int pipexInitialPosition, pipeyInitialPosition;
	int randomNumber = (rand() % 11) + 2;


public:

	pipe(int x)
	{
		pipex = x;
		pipey = 0;
		pipexInitialPosition = pipex;
		pipeyInitialPosition = pipey;
	}

	void deletePipe();
	void getPlayerPipe();
	void pipeReset(int x);
	int getPipeX() { return pipex; }

};

int pipe::getGapInThePipe()
{
	return randomNumber;
}

void pipe::pipeReset(int x)
{
	pipex = x;
	randomNumber = (rand() % 11) + 2;

}

void pipe::getPlayerPipe()
{
	system("cls");
	cout << "Choose you're pipe mothafucka , write 5 ASCII chars or one by one if you like typing: ";
	cin >> pipeChar;
}