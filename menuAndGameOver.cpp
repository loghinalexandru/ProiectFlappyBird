#include "stdafx.h"
#include "menuAndGameOver.h"
#include <conio.h>
#include <iostream>
#include "consoleFunctions.h"
#include <fstream>
#include <vector>
using namespace std;

ifstream input;
ofstream output;


struct players
{
	unsigned long long score;
	char nickname[50];
};


struct axis
{
	int X;
	int Y;
};

vector<players> wallOfLegends;

bool isEmpty(std::ifstream& pFile)
{
	return pFile.peek() == std::ifstream::traits_type::eof();
}

void writePlayersToFile()
{
	output.open("C:\\HighScore.txt");
	for (unsigned int i = 0; i < wallOfLegends.size(); i++)
	{
		output << wallOfLegends[i].score;
		output << '\n';
		output << wallOfLegends[i].nickname;
		output << '\n';
	}
	output.close();
}



void storePlayers()
{
	wallOfLegends.clear();
	input.open("C:\\HighScore.txt");
	players x;
	while (input >> x.score)
	{
		input.get();
		input >> x.nickname;
		wallOfLegends.push_back(x);
	}
	input.close();
}

void checkNewRecord(unsigned long long playerHighScore)
{
	players x;
	input.open("C:\\HighScore.txt");
	if (isEmpty(input))
	{
		x.score = playerHighScore;
		cout << "Congratulations you've set a NEW record !!!\n";
		cout << "Set you're nickname: ";
		cin >> x.nickname;
		wallOfLegends.push_back(x);
		writePlayersToFile();
		input.close();
	}
	else
	{
		input.close();
		storePlayers();
		for (unsigned int i = 0; i < wallOfLegends.size(); i++)
		{
			if (wallOfLegends[i].score < playerHighScore)
			{
				if (i == wallOfLegends.size() - 1)
				{
					x.score = playerHighScore;
					cout << "Congratulations you've set a NEW record !!!\n";
					cout << "Set you're nickname: ";
					cin >> x.nickname;
					wallOfLegends.push_back(x);
					writePlayersToFile();
					return;
				}
			}
			else
			{
				return;
			}
		}
	}

}



void printWallOfLegends()
{
	setColor(11);
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
		cout << index << '.' << ' ';
		input.get();
		input.getline(playerName, 50);
		cout << playerName << " with ";
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
	setColor(10);
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
	cout << "                                                   1: Classic  " << endl << endl;
	cout << "                                                   2: Arcade  " << endl << endl;
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
			}
			if (pos.Y == 16)
			{
				return 2;
			}
			if (pos.Y == 18)
			{
				gameRunning = false;
				return 3;
			}
			if (pos.Y == 20)
			{
				return 4;
			}
			if (pos.Y == 22)
			{
				return 5;
			}
			if (pos.Y == 24)
			{
				gameRunning = false;
				return 6;
			}
		default:
			break;
		}
	}
}


void gameOver(unsigned long long playerHighScore, bool& gameRunning)
{
	setColor(10);
	system("cls");

	cout << "       ,ad8888ba,                                                  ,ad8888ba," << endl;
	cout << "       d8''    `'8b                                               d8''    ''8b" << endl;
	cout << "      d8'                                                        d8'        `8b" << endl;
	cout << "      88             ,adPPYYba,  88,dPYba,,adPYba,    ,adPPYba,  88          88  8b       d8   ,adPPYba,  8b,dPPYba, " << endl;
	cout << "      88      88888    ""     `Y8  88P'   '88'    '8a  a8P_____88  88          88  `8b     d8'  a8P_____88  88P'   'Y8" << endl;
	cout << "      Y8,        88  ,adPPPPP88  88      88      88  8PP'''''''  Y8,         8P   `8b   d8'   8PP'''''''  88         " << endl;
	cout << "       Y8a.    .a88   88,    ,88 88      88      88  '8b,   ,aa   Y8a.    .a8P     `8b,d8'    '8b,   ,aa  88   " << endl;
	cout << "      `'Y88888P'    ` '8bbdP'Y8  88      88      88   `'Ybbd8''    `'Y8888Y''        '8'       `'Ybbd8''  88  " << endl;
	cout << '\n';
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



