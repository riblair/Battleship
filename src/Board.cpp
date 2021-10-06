/*
 * Board.cpp
 *
 *  Created on: Oct 4, 2021
 *      Author: black
 */

#include "board.h"


/*
 * In board, characters represent different things
 * '~' represents the water (empty)
 * 'a' = Carrier (5 long ship)
 * 'b' = Battleship (4 long ship)
 * 'd' = Destroyer (3 long ship)
 * 's' = Sub (3 long ship)
 * 'r' = Cruiser (2 long ship)
 * 'X' = hit (showing enemy board)
 * 'M' = miss (showing enemy board)
 */
Board::Board() {
	// TODO Auto-generated constructor stub
	hits = 0;
	care = new Ship(5,'a');
	battle = new Ship(4,'b');
	destroy = new Ship(3,'d');
	sub = new Ship(3,'s');
	cruise = new Ship(2,'r');

}

void Board::initBoard(bool manual) {
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			board[i][j]= '~';
		}
	}
	if(manual) {
		manuallyPlaceShips();
	}
	else {
		randomlyPlaceShips();
	}
}

void Board::manuallyPlaceShips() {
	fflush(stdout);
	puts("You will now be placing ships manually");
	fflush(stdout);
	puts("DIRECTIONS: First, you enter a row, then you will enter a col, and finnally, you will enter the direction for the ship to be placed.");
	fflush(stdout);
	puts("Direction indicator: ");
	fflush(stdout);
	puts("0 - ship will start at the coordinante you chose, and end above the coordinate you chose");
	fflush(stdout);
	puts("1 - ship will start at the coordinante you chose, and end to the right of the coordinate you chose");
	fflush(stdout);
	puts("2 - ship will start at the coordinante you chose, and end below the coordinate you chose");
	fflush(stdout);
	puts("3 - ship will start at the coordinante you chose, and end to the left of the coordinate you chose");
	fflush(stdout);

	Ship* ships[5];
	*ships = care;
	*(ships+1) = battle;
	*(ships+2) = destroy;
	*(ships+3) = sub;
	*(ships+4) = cruise;

	for(int i = 0; i < 5; i++) {

		switch(i)
		{
		case 0:
			puts("You are now placing the Carrier");
			fflush(stdout);
			break;
		case 1:
			puts("You are now placing the Battleship");
			fflush(stdout);
			break;
		case 2:
			puts("You are now placing the Destroyer");
			fflush(stdout);
			break;
		case 3:
			puts("You are now placing the Submarine");
			fflush(stdout);
			break;
		case 4:
			puts("You are now placing the Cruiser");
			fflush(stdout);
			break;
		}
		puts("boop");
		fflush(stdout);
		Location* shipLoc = new Location(); // I could do shipLoc[*(*(ships+i))->getSize()] if shits not working
		shipLoc->row = -1;
		shipLoc->col = -1;
		int row = -1;
		int col = -1;
		int dir = -1;
		bool correct = false;
		do {
			puts("Enter a row (0-7) for the ship");
			fflush(stdout);
			scanf("%d",&row);
			puts("Enter a column (0-7) for the ship");
			fflush(stdout);
			scanf("%d",&col);
			puts("Enter a direction (0-3) for the ship");
			fflush(stdout);
			scanf("%d",&dir);
			shipLoc->row = row;
			shipLoc->col = col;
			if(checkShip(*(ships+i),shipLoc,dir)) {
				puts("Ship is placed!");
				fflush(stdout);
				correct = true;
			}
			else {
				puts("Invalid ship location/direction. Please try again!");
				fflush(stdout);
			}
		} while(!correct);

	}
}

void Board::randomlyPlaceShips() {

	//	care = new Ship();
	//	Location* cl[5];
	//	Location* newLoc;
	//	newLoc->col = 0;
	//	newLoc->row = 0;
	//	*cl = new Location();
	//	*(cl+1) = newLoc;
	//	*(cl+2) = new Location();
	//	*(cl+3) = new Location();
	//	*(cl+4) = new Location();
	//
	//	bool hits[5] = {false, false,false,false,false};
	//
	//	care->updateShip(5, 'a', cl, hits);
}

bool Board::checkShip(Ship* ship, Location* loc, int dir) {
	int size = ship->getSize();
	if(loc == NULL) {
		puts("Location was null");
		fflush(stdout);
		return false;
	}
	if(dir == NULL || dir < 0) {
		puts("Either dir was null, or dir was less than 0");
		fflush(stdout);
		return false;
	}
	if(loc->col > 7 || loc->col < 0 || loc->row > 7 || loc->row < 0) {
		puts("location suggested was out of bounds");
		fflush(stdout);
		return false;
	}
	//straight up
	if(dir == 0) {
		if(loc->row-size < 0) {
			puts("Direction led ship out of bounds");
			fflush(stdout);
			return false;
		}
		for(int i = 0; i < size; i++) {
			Location pos1;
			pos1.row = loc->row-i;
			pos1.col = loc->col;
			*(loc+i) = pos1;
			char place = board[loc->row-i][loc->col];
			printf("The character at (%d,%d) is %c \n",loc->row - i,loc->col,place);
			fflush(stdout);
			if(place != '~') {
				return false;
			}
		}
	}
	//right
	else if(dir == 1) {
		if(loc->col+size > 7) {
			puts("Direction led ship out of bounds");
			fflush(stdout);
			return false;
		}
		for(int i = 0; i < size; i++) {
			Location pos1;
			pos1.row = loc->row;
			pos1.col = loc->col+i;
			*(loc+i) = pos1;
			char place = board[loc->row][loc->col + i];
			printf("The character at (%d,%d) is %c \n",loc->row,loc->col + i,place);
			fflush(stdout);
			if(place != '~') {
				return false;
			}
		}
	}
	//straight down
	else if(dir == 2) {
		if(loc->row+size > 7) {
			puts("Direction led ship out of bounds");
			fflush(stdout);
			return false;
		}
		for(int i = 0; i < size; i++) {
			Location pos1;
			pos1.row = loc->row+i;
			pos1.col = loc->col;
			*(loc+i) = pos1;
			char place = board[loc->row+i][loc->col];
			printf("The character at (%d,%d) is %c \n",loc->row + i,loc->col,place);
			fflush(stdout);
			if(place != '~') {
				return false;
			}
		}
	}
	//left
	else { // (dir ==3)
		if(loc->col-size < 0) {
			puts("Direction led ship out of bounds");
			fflush(stdout);
			return false;
		}
		for(int i = 0; i < size; i++) {
			Location pos1;
			pos1.row = loc->row;
			pos1.col = loc->col-i;
			*(loc+i) = pos1;
			char place = board[loc->row][loc->col - i];
			printf("The character at (%d,%d) is %c \n",loc->row,loc->col - i,place);
			fflush(stdout);
			if(place != '~') {
				return false;
			}
		}
	}
	ship->updateShipLoc(loc);
	return true;
}

void Board::printMoveToFile(FILE* fp, Location* loc) {

}

void Board::printBoard(bool showShips) {

}

Board::~Board() {
	// TODO Auto-generated destructor stub
}

void makePlayerMove()
{

}

bool checkMove(Location* loc)
{

	bool ok = false;
	if(loc->col < 0 || loc->col > 8 || loc->row < 0 || loc->row > 8)
	{
		return ok;
	}
	return ok;
}

void makeRandomMove()
{

}
