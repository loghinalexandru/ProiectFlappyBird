#include "stdafx.h"
#include "menuAndGameOver.h"
#include <conio.h>
#include <iostream>
#include "consoleFunctions.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <windows.h>
#include <string>

using namespace std;

ifstream input;
ofstream output;


struct players
{
	unsigned long long score;
	string nickname;
	unsigned long long time;
};


struct axis
{
	int X;
	int Y;
};

vector<players> wallOfLegends;

bool isEmpty(ifstream& pFile)
{
	return pFile.peek() == ifstream::traits_type::eof();
}

void writePlayersToFile()
{
	output.open("C:\\HighScore.txt");
	for (int i = wallOfLegends.size() - 1; i >= 0; i--)
	{
		output << wallOfLegends[i].score;
		output << '\n';
		output << wallOfLegends[i].nickname;
		output << '\n';
		output << wallOfLegends[i].time;
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
		input.get();
		input >> x.time;
		wallOfLegends.push_back(x);
	}
	input.close();
}

void checkNewRecord(unsigned long long playerHighScore, time_t duration)
{
	players x;
	input.open("C:\\HighScore.txt");
	if (isEmpty(input))
	{
		x.score = playerHighScore;
		cout << "         Congratulations you have set a NEW record !!!\n";
		cout << "         Set your nickname(max length 20): ";
		cin >> x.nickname;
		if (x.nickname.size() > 20)
		{
			x.nickname.resize(20);
		}
		x.time = duration;
		wallOfLegends.push_back(x);
		writePlayersToFile();
		input.close();
	}
	else
	{
		input.close();
		storePlayers();
		reverse(wallOfLegends.begin(), wallOfLegends.end());
		if (wallOfLegends[wallOfLegends.size() - 1].score < playerHighScore)
		{

			x.score = playerHighScore;
			cout << "         Congratulations you have set a NEW record !!!\n";
			cout << "         Set your nickname(max length 20): ";
			cin >> x.nickname;
			if (x.nickname.size() > 20)
			{
				x.nickname.resize(20);
			}
			x.time = duration;
			wallOfLegends.push_back(x);
			writePlayersToFile();
			return;
		}
		else return;
	}

}



void printWallOfLegends()
{
	system("MODE CON: COLS=120 LINES=25");
	setColor(11);
	bool backToMenu = true;
	unsigned long long duration;
	system("cls");
	unsigned long long topScore;
	string playerName;
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
		cout << "                               ";
		cout << index << '.' << ' ';
		input.get();
		input >> playerName;
		cout << playerName << " with ";
		cout << topScore;
		input >> duration;
		cout << " points ";
		cout << "in " << duration << " seconds";
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
	system("MODE CON: COLS=120 LINES=25");
	customizeConsole();
	setColor(10);
	hideCursor();
	cout << '\n';
	cout << "                    _______ ___     _______ _______ _______ __   __ _______ ___ ______   ______ \n";
	cout << "                   |       |   |   |   _   |       |       |  | |  |  _    |   |    _ | |      | \n";
	cout << "                   |    ___|   |   |  |_|  |    _  |    _  |  |_|  | |_|   |   |   | || |  _    |\n";
	cout << "                   |   |___|   |   |       |   |_| |   |_| |       |       |   |   |_||_| | |   | \n";
	cout << "                   |    ___|   |___|       |    ___|    ___|_     _|  _   ||   |    __  | |_|   | \n";
	cout << "                   |   |   |       |   _   |   |   |   |     |   | | |_|   |   |   |  | |       | \n";
	cout << "                   |___|   |_______|__| |__|___|   |___|     |___| |_______|___|___|  |_|______| \n";
	cout << "\n\n\n\n";
	setColor(15);
	cout << "                                                    M E N U:   \n\n";
	setColor(10);
	cout << "                                                   1: Classic\n\n";
	setColor(12);
	cout << "                                                   2: Arcade\n\n";
	setColor(9);
	cout << "                                                   3: HowToPlay \n\n";
	setColor(11);
	cout << "                                                   4: WallOfLegends\n\n";
	setColor(15);
	cout << "                                                   5: Exit\n\n";
	axis pos;
	pos.X = 47;
	pos.Y = 14;
	gotoxy(pos.X, pos.Y);
	cout << "-->";
	gotoxy(47, 22);
	while (true)
	{
		switch (_getch())
		{
		case 72: case 119: case 87:
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
				gotoxy(47, 22);
			}
			break;
		case 80: case 115: case 83:
			if (pos.Y != 22)
			{
				for (unsigned int i = pos.X; i < pos.X + 3; i++)
				{
					gotoxy(i, pos.Y);
					cout << ' ';
				}
				pos.Y += 2;
				gotoxy(pos.X, pos.Y);
				cout << "-->";
				gotoxy(47, 22);
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
				return 3;
			}
			if (pos.Y == 20)
			{
				return 4;
			}
			if (pos.Y == 22)
			{
				gameRunning = false;
				return 5;
			}
		default:
			break;
		}
	}
}


void gameOver(unsigned long long playerHighScore, bool& gameRunning, time_t duration, unsigned long long& timesPlayed)
{
	system("MODE CON: COLS=120 LINES=25");
	setColor(10);
	system("cls");
	timesPlayed++;
	cout << '\n';
	cout << "       ,ad8888ba,                                                  ,ad8888ba," << endl;
	cout << "       d8''    `'8b                                               d8''    ''8b" << endl;
	cout << "      d8'                                                        d8'        `8b" << endl;
	cout << "      88             ,adPPYYba,  88,dPYba,,adPYba,    ,adPPYba,  88          88  8b       d8   ,adPPYba,  8b,dPPYba, " << endl;
	cout << "      88      88888    ''   `Y8  88P'   '88'    '8a  a8P_____88  88          88  `8b     d8'  a8P_____88  88P'   'Y8" << endl;
	cout << "      Y8,        88  ,adPPPPP88  88      88      88  8PP'''''''  Y8,         8P   `8b   d8'   8PP'''''''  88         " << endl;
	cout << "       Y8a.    .a88   88,    ,88 88      88      88  '8b,   ,aa   Y8a.    .a8P     `8b,d8'    '8b,   ,aa  88   " << endl;
	cout << "       `'Y88888P'   ` '8bbdP'Y8  88      88      88   `'Ybbd8''    `'Y8888Y''        '8'       `'Ybbd8''  88  " << endl;
	cout << '\n';
	cout << '\n';
	setColor(15);
	cout << "         You got: " << playerHighScore << " points                                      " << "TimeSpent: " << duration;
	cout << '\n';
	cout << "         RANK:";
	if (playerHighScore < 20)
	{
		cout << "Baboon\n";
	}
	else
	{
		if (playerHighScore < 50)
		{
			cout << "Drunk Student\n";
		}
		else
		{
			if (playerHighScore < 200)
			{
				cout << "Rookie\n";
			}
			else
			{
				cout << "GameMaster\n";
			}
		}
	}
	cout << "         GamesPlayed: " << timesPlayed << endl;
	gameOverSound();
	checkNewRecord(playerHighScore, duration);
	cout << "         Do you want to play again ? Press [y/n] ";
	bool validInput = false;
	while (!validInput)
	{
		switch (_getch())
		{
		case 89: case 121:
			validInput = true;
			gameRunning = true;
			break;
		case 78: case 110:
			validInput = true;
			gameRunning = false;
			break;
		}

	}
}

void gameInstructions()
{
	system("MODE CON: COLS=120 LINES=25");
	system("cls");
	setColor(15);
	cout << "                                             888 888         888  \n";
	cout << "                                             888 888  ,e e,  888 888 88e  \n";
	cout << "                                             8888888 d88 88b 888 888 888b \n";
	cout << "                                             888 888 888   , 888 888 888P \n";
	cout << "                                             888 888  'YeeP' 888 888 88'  \n";
	cout << "                                                                 888      \n";
	cout << "                                                                 888  \n";
	cout << '\n';
	cout << "                                 Use SPACE to move the bird and do not touch the ground \n";
	cout << "                                                    PowerUps \n";
	cout << "                                              (only in arcade mode)     \n";
	cout << "                                            1. G-no collision with the pipes for 15 seconds\n";
	cout << "                                            2. S-reduces the game speed slightly\n";
	cout << "                                            3. P-doubles the points\n";
	while (!_getch())
	{

	}
}

