/*
 * Production.cpp
 *
 *  Created on: Oct 4, 2021
 *      Author: Ryand
 */

#include "Production.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>//strncpy
#include <stdlib.h>//strtol
#include "Board.h"

Production::Production() {
	// TODO Auto-generated constructor stub

}

bool Production::prod(int argc, char* argv[])
{

	welcomeScreen();
	eraseLogFile();
	int option  = -1;
	int turnLimit = -1;
	Board* board1 = new Board();
	Board* board2 = new Board();
	board2->initBoard(false);
	if(argc <=1) //no interesting information
	{
		puts("Didn't find any arguments.");
		fflush(stdout);
	}
	else
	{
		printf("Found %d interesting arguments.\n", argc-1);
		fflush(stdout);
		for(int i = 1; i<argc; i++) //don't want to read argv[0]
		{//argv[i] is a string
			switch(i)
			{
			case 1:
				if((strcmp(argv[i], "false") == 0)||(strcmp(argv[i], "False") == 0)){
					option = 2;
					printf("Your ships will be placed for you");
					fflush(stdout);
				}
				else if((strcmp(argv[i], "true") == 0)||(strcmp(argv[i], "True") == 0)){
					option = 1;
					printf("You will place your ships manually");
					fflush(stdout);
				}
				else{
					puts("Unexpected argument.");
					fflush(stdout);
				}
				break;
			case 2:
				turnLimit = atoi(argv[i]);
				if(turnLimit < 0)
				{
					printf("The number of turns will be %d\n", turnLimit);
					fflush(stdout);
				}
				else
				{
					printf("No game will be conducted");
					fflush(stdout);
				}
				break;
			default:
				puts("Unexpected argument count.");
				fflush(stdout);
				break;

			}
		}
	}

	switch (option) {
	case 1:
		board1->initBoard(true);
		break;
	case 2:
		board1->initBoard(false);
		break;
	}
	//0 = player first, 1 = AI first
	int turnOrder = rand() % 2;
	bool playerTurn = false;
	if(turnOrder == 0) {
		playerTurn = true;
	}
	int curTurn = 1;
	bool itHit = false;
	while(!isWon(board1,board2) && curTurn < turnLimit) {

		switch(playerTurn)
		{
		case true: //player's turn
			puts("It's ur turn");
			board2->makePlayerMove();
			playerTurn = !playerTurn;
			break;
		case false:
			puts("It's the AI's turn");
			board1->makeRandomMove();
			playerTurn = !playerTurn;
			break;
		}
	}

	//while(currrent turn < turnLimit && !game Won)
	//take first players turn (assuming its player)
	//ask player for a legal Move
	//make legal move
	//check hit
	//print result of move (to consoloe and file)
	//check for win
	//take seconds players turn (assuming its AI)
	//make random move
	//check hit
	//print result of move (to consoloe and file)
	//check for win

	/*
	 * The program must record the chosen move, whether it was a hit, a miss,
	 * or a redundant shot, and successive sea and fleet configurations for each
	 * turn in a log file. You can choose the file format, but you must document
	 * that, and adhere to what you describe
	 */


	return true;
}



Production::~Production() {
	// TODO Auto-generated destructor stub
}

bool Production::isWon(Board* board, Board* board2) {
	if(board->hits == 17) {
		puts("PLAYER 2 WINS!");
		fflush(stdout);
		return true;
	}
	else if(board2->hits == 17) {
		puts("PLAYER 1 WINS!");
		fflush(stdout);
		return true;
	}
	else {
		return false;
	}
}

void Production::welcomeScreen (void) {
	printf ("XXXXX   XXXX  XXXXXX XXXXXX XX     XXXXXX  XXXXX XX  XX XX XXXX\n");
	printf ("XX  XX XX  XX   XX     XX   XX     XX     XX     XX  XX XX XX  XX\n");
	printf ("XXXXX  XX  XX   XX     XX   XX     XXXX    XXXX  XXXXXX XX XXXX\n");
	printf ("XX  XX XXXXXX   XX     XX   XX     XX         XX XX  XX XX XX\n");
	printf ("XXXXX  XX  XX   XX     XX   XXXXXX XXXXXX XXXXX  XX  XX XX XX\n");
	printf ("\n\n");
	printf ("RULES OF THE GAME:\n");
	printf ("1. This is a two player game.\n");
	printf ("2. Player 1 is you and Player 2 is the computer.\n");
	printf ("3. Player 1 will be prompted if user wants to manually input coordinates\n");
	printf ("   for the game board or have the computer randomly generate a game board\n");
	printf ("4. There are five types of ships to be placed by longest length to the\n");
	printf ("   shortest; [c] Carrier has 5 cells, [b] Battleship has 4 cells, [r] Cruiser\n");
	printf ("   has 3 cells, [s] Submarine has 3 cells, [d] Destroyer has 2 cells\n");
	printf ("5. The computer randomly selects which player goes first\n");
	printf ("6. The game begins as each player tries to guess the location of the ships\n");
	printf ("   of the opposing player's game board; [*] hit and [m] miss\n");
	printf ("7. First player to guess the location of all ships wins\n\n");
	fflush(stdout);
}

void Production::eraseLogFile() {
	FILE* fp = fopen("battleship.log","w");
	fprintf(fp,"Game has not Started yet");

}
