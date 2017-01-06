#include "stdafx.h"
#include "menuAndGameOver.h"
#include <conio.h>
#include <iostream>
#include "consoleFunctions.h"
#include <fstream>
using namespace std;

ifstream input;
ofstream output;

struct axis
{
	int X;
	int Y;
};

void checkNewRecord(unsigned long long playerHighScore)
{
	char playerNickName[50];
	unsigned int long long topScore;
	input.open("C:\\HighScore.txt");
	while (input>>topScore)
	{
		if (topScore < playerHighScore)
		{
			input.close();
			output.open("C:\\HighScore.txt");
			cout << "Congratulations you set a NEW highscore !!!";
			cout << '\n';
			cout << "Set you're nickname: ";
			cin >> playerNickName;
			output << playerHighScore;
			output << '\n';
			output << playerNickName;
		}
	}
	output.close();
}


void printWallOfLegends()
{ 
	bool backToMenu = true;
	system("cls");
	unsigned int topScore;
	char playerName[50];
	int index = 1;
	input.open("C:\\HighScore.txt");
	cout << "             _______ _______ _______ _______ ___     _______ __   __ _______ ______   _______ \n";
	cout << "            |       |       |       |       |   |   |   _   |  | |  |       |    _ | |       | \n";
	cout << "            |_     _|   _   |    _  |    _  |   |   |  |_|  |  |_|  |    ___|   | || |  _____| \n";
	cout << "              |   | |  | |  |   |_| |   |_| |   |   |       |       |   |___|   |_||_| |_____  \n";
	cout << "              |   | |  |_|  |    ___|    ___|   |___|       |_     _|    ___|    __  |_____  | \n";
	cout << "              |   | |       |   |   |   |   |       |   _   | |   | |   |___|   |  | |_____| | \n";
	cout << "              |___| |_______|___|   |___|   |_______|__| |__| |___| |_______|___|  |_|_______| \n";
	cout << "\n";
	cout << "\n";
	while (input >> topScore)
	{
		cout << "                                          ";
		cout << index<<'.'<<' ';
		input.get();
		input.getline(playerName, 50);
		cout << playerName<<" with ";
		cout << topScore;
		cout << " points";
		index++;
		cout << '\n';
	}
	input.close();
	while (!_getch())
	{

	}
}

int printMenu(bool& gameRunning)
{
	customizeConsole();
	setColor(2);
	hideCursor();
	cout << "" << endl;
	cout << "                              --------------------------------------------------------  " << endl;
	cout << "                             |                                                        | " << endl;
	cout << "                             |   **** *    **** **** **** *   *    ***  * ***  ***    | " << endl;
	cout << "                             |   *    *    *  * *  * *  * *   *    *  * * *  * *  *   | " << endl;
	cout << "                             |   ***  *    **** **** **** *****    ***  * ***  *  *   | " << endl;
	cout << "                             |   *    *    *  * *    *      *      *  * * *  * *  *   | " << endl;
	cout << "                             |   *    **** *  * *    *      *      ***  * *  * ***    | " << endl;
	cout << "                             |                                                        | " << endl;
	cout << "                              --------------------------------------------------------  " << endl;
	cout << "" << endl << endl;
	cout << "                                                      M E N U:    " << endl << endl;
	cout << "                                                   1: Classic  "    << endl << endl;
	cout << "                                                   2: Arcade  "     << endl << endl;
	cout << "                                                   3: 1vs1       " << endl << endl;
	cout << "                                                   4: Help     " << endl << endl;
	cout << "                                                   5: WallOfLegends    " << endl << endl;
	cout << "                                                   6: Exit        " << endl << endl;

	axis pos;
	pos.X = 47;
	pos.Y = 14;
	gotoxy(pos.X, pos.Y);
	cout << "-->";
	while (true)
	{
		switch (_getch())
		{
		case 56: case 119:
			if (pos.Y != 14)
			{
				for (unsigned int i = pos.X; i < pos.X + 3; i++)
				{
					gotoxy(i, pos.Y);
					cout << ' ';
				}
				pos.Y -= 2;
				gotoxy(pos.X, pos.Y);
				cout << "-->";
			}
			break;
		case 50: case 115:
			if (pos.Y != 24)
			{
				for (unsigned int i = pos.X; i < pos.X + 3; i++)
				{
					gotoxy(i, pos.Y);
					cout << ' ';
				}
				pos.Y += 2;
				gotoxy(pos.X, pos.Y);
				cout << "-->";
			}
			break;

		case 13:
			if (pos.Y == 14)
			{
				return 1;
				break;
			}
			if (pos.Y==16)
			{
				return 2;
				break;
			}
			if (pos.Y == 18)
			{
				gameRunning = false;
				return 3;
				break;
			}
			if (pos.Y==20)
			{
				return 4;
				break;
			}
			if (pos.Y==22)
			{
				return 5;
				break;
			}
			if (pos.Y==24)
			{
				return 6;
				break;
			}
		default:
			break;
		}
	}
}


void gameOver(unsigned long long playerHighScore,bool& gameRunning)
{
	setColor(15);
	system("cls");
	cout << " d8888b .db    db d8888b .db      d888888b  .o88b.  d888888b d888888b  .d8b.  d888888b d88888b\n";
	cout << " 88  `8D 88    88 88  `8D 88        `88'   d8P  Y8    `88'   `~~88~~' d8' `8b `~~88~~' 88\n";
	cout << " 88oodD' 88    88 88oooY' 88         88    8P          88       88    88ooo88    88    88ooooo\n";
	cout << " 88~~~   8     88 88~~~b. 88         88    8b          88       88    88~~~88    88    88~~~~~\n";
	cout << " 88      88b  d88 88   8D 88booo.   .88.    Y8b  d8   .88.      88    88   88    88    88.\n";
	cout << " 88      ~Y8888P' Y8888P' Y88888P Y888888P  `Y88P'  Y888888P    YP    YP   YP    YP    Y88888P\n";
	cout << '\n';
	cout << "You got: " << playerHighScore << " points\n";
	cout << "RANK :";
	if (playerHighScore < 20)
	{
		cout << "Baboon\n";
	}
	else
	{
		if (playerHighScore > 50)
		{
			cout << "Drunk Student\n";
		}
		else
		{
			if (playerHighScore > 200)
			{
				cout << "GameMaster\n";

			}
			else
			{
				cout << "Rookie\n";
			}
		}
	}
	gameOverSound();
	checkNewRecord(playerHighScore);
	char userInput = 'n';
	cout << "Do you want to play again ? [y/N]: ";
	cin >> userInput;
	if (userInput == 'y' || userInput == 'Y')
	{
		gameRunning = true;
	}
	else
	{
		gameRunning = false;
	}

}



