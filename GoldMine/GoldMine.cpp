// GoldMine.cpp : Defines the entry point for the console application.
/*
	Author: Malik Hicks
	Program Description:  This program is utilized to produce a game board and provide the user with
						   5 chances to locate/mine gold or a bomb.  The program will terminate if a bomb is found.
*/

#include "stdafx.h"
#include <iostream>
#include <time.h>
using namespace std;


const int ROW = 8;				// Declares a constant integer for board row, column, number of gold and bombs, as well as chances
const int COL = 8;
const int BOMB = 1;
const int CHANCE = 5;
const int GOLD = 5;

void initializeArray(char board[ROW][COL]);
void items(char board[ROW][COL]);
void displayBoard(char mArray[ROW][COL]);
void finishedBoard(char board[ROW][COL]);



int main()
{
	char answer;
	cout << "\t\t\t\t\t\tGreetings User ^.^" << endl;
	cout << "\t\t\t\t\t===============================" << endl; 
	cout << "\t\t\t\t\tWelcome to the Gold Mine game.\n\t\t\t\t      Please read the instructions below!" << endl;
	cout << "\t\t\t\t   =========================================" << endl << endl;

	do
	{
		char board[ROW][COL];

		initializeArray(board);
		displayBoard(board);
		items(board);
		finishedBoard(board);


		cout << endl;

		cout << "\nWould you like to play again? Press Y for 'yes', otherwise press another key for 'no': ";	 // Asks the user if they wish to play the game again
		cin >> answer;
		cout << "\n";

	} while (answer == 'y' || answer == 'Y');

	return 0;

}

void initializeArray(char board[ROW][COL])						// Function used to initialize the Game Array
{
	int rows, cols;

	for (rows = 0; rows < ROW; rows++)
	{

		for (cols = 0; cols < COL; cols++)
		{
			board[rows][cols] = ' ';
		}
	}
}
void items(char board[ROW][COL])							// Function that assigns the letters G and B randomly throughout the board
{
	int gold = 0;
	int x, y;
	int bomb = 0;
	srand(time(NULL));


	for (gold = 0; gold < GOLD; gold++)
	{
		x = rand() % ROW;
		y = rand() % COL;
		board[x][y] = 'G';
	}

	for (bomb = 0; bomb < BOMB; bomb++)
	{
		x = rand() % ROW;
		y = rand() % COL;
		board[x][y] = 'B';
	}

}

void displayBoard(char mArray[ROW][COL])							//Displays the game instructions and game board to the user
{
	cout << " **  ********************  **" << endl;
	cout << " **   Use the Board Below! **" << endl;
	cout << " **  Find the Hidden Gold! **" << endl;
	cout << " ** You Have Five Guesses, **" << endl;
	cout << " **   5 Pieces of Gold     **" << endl;
	cout << " **      and 1 Bomb        **" << endl;
	cout << " **      Good Luck!        **" << endl;
	cout << " **  ********************  **" << endl << endl;


	int r, c;

	cout << "    ";

	for (c = 0; c < COL; c++)

		cout << c + 1 << "  ";

	cout << endl;
	cout << "   ------------------------" << endl;



	for (r = 0; r < ROW; r++)
	{
		cout << r + 1 << " ";
		cout << "| ";

		for (c = 0; c < COL; c++)
		{
			cout << "?" << "  ";
		}
		cout << "| ";
		cout << endl;
	}
	cout << "   ------------------------" << endl << endl;

	cout << endl;
}


void finishedBoard(char board[ROW][COL])									//Prompts the user for desired coordinates of which spot they wish to guess on
{
	int r, c;
	int attempts = CHANCE;
	int points = 0;

	while (attempts > 0)
	{
		cout << endl;
		cout << "===============================" << endl;
		cout << "Enter a X coordinate: ";
		cin >> r;
		cout << endl;
		cout << "Enter a Y coordinate: ";
		cin >> c;
		

		if (board[r - 1][c - 1] == 'G')															// Informs the user whether they found gold, a bomb, or nothing.
		{
			cout << endl;
			cout << "You found GOLD!! Here's another attempt on the house ;). ";
			board[r - 1][c - 1] = 'F';
			points = points + 1;
			attempts--;
			attempts++;
			cout << "\nYou have " << attempts << " guesses left." << endl;
			cout << "===============================" << endl;
			cout << endl;
			continue;
		}
		else if (board[r - 1][c - 1] == 'B')
		{
			cout << endl;
			attempts = 0;
			cout << "It's a BOMB!!!!" << " GAME OVER..." << endl;
			cout << "===============================" << endl;
			break;

		}
		else
			cout << endl;
		cout << "Too Bad! ";
		attempts--;
		cout << "You have " << attempts << " guesses left." << endl;
		cout << "===============================" << endl;
		cout << endl;

	}

	cout << "You earned " << points << " points." << endl << endl;
	cout << "Better Luck Next Time!\n" << endl;
	cout << "===============================" << endl;

	cout << "\n      Here's your board: " << endl;						//Displays the final board back to the user, revealing all locations.
	cout << endl;

	cout << endl;
	cout << "    ";

	for (c = 0; c < COL; c++)

		cout << c + 1 << "  ";

	cout << endl;
	cout << "   ------------------------" << endl;



	for (r = 0; r < ROW; r++)
	{
		cout << r + 1 << " ";
		cout << "| ";

		for (c = 0; c < COL; c++)
		{
			cout << board[c][r] << "  ";
		}
		cout << "| ";
		cout << endl;
	}
	cout << "   ------------------------" << endl << endl;
}