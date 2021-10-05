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

}

void Board::initBoard(bool manual) {
//	for(char* row[]: board) {
//		for(char a : row) {
//			a = '~';
//		}
//	}
	if(manual) {
		manuallyPlaceShips();
	}
	else {
		randomlyPlaceShips();
	}
}

void Board::manuallyPlaceShips() {
	puts("You will now be placing ships manually");
	puts("DIRECTIONS: First, you enter a row, then you will enter a col, and finnally, you will enter the direction for the ship to be placed.");
	puts("Direction indicator: ");
	puts("0 - ship will go face above the coordinate u choose");

}

void Board::randomlyPlaceShips() {

	care = new Ship();
	Location* cl[5];
	*cl = new Location();
	*(cl+1) = new Location();
	*(cl+2) = new Location();
	*(cl+3) = new Location();
	*(cl+4) = new Location();

	bool hits[5] = {false, false,false,false,false};

	care->updateShip(5, 'a', cl, hits);
}

bool Board::checkShip(Ship* ship, Location* loc, int dir) {
	return false;
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
