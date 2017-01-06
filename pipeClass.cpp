#include"stdafx.h"
#include<iostream>
#include "pipeClass.h"
#include "consoleFunctions.h"
using namespace std;



int pipe::getGapInThePipe()
{
	return randomNumber;
}

void pipe::pipeReset(int x)
{
	pipex = x;
	randomNumber = (rand() % 11) + 2;

}

void pipe::deletePipe()
{
	for (unsigned int i = 0; i < randomNumber; i++)
	{
		gotoxy(pipex, i);
		cout << ' ';
	}
	for (unsigned int i = randomNumber + 4; i < MAX_HEIGHT - 3; i++)
	{
		gotoxy(pipex, i);
		cout << ' ';
	}
}


void pipe::movePipeLeftByOne()
{
	deletePipe();
	pipex--;
	for (unsigned int i = 0; i < randomNumber; i++)
	{
		gotoxy(pipex, i);
		cout << pipeChar;
	}
	for (unsigned int i = randomNumber + 4; i < MAX_HEIGHT - 3; i++)
	{
		gotoxy(pipex, i);
		cout << pipeChar;
	}

}