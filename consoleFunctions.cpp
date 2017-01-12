#include "stdafx.h"
#include <windows.h>
#include "consoleFunctions.h"

void gotoxy(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setColor(unsigned int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gameOverSound()
{
	Beep(440, 500);
	Beep(440, 500);
	Beep(440, 500);
	Beep(349, 350);
	Beep(523, 150);
	Beep(440, 500);
	Beep(349, 350);
	Beep(523, 150);
	Beep(440, 1000);
}

void hideCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void customizeConsole()
{
	system("cls");
	TCHAR Title[] = L"FLAPPY BIRD";
	SetConsoleTitle(Title);
}

