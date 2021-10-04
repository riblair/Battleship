/*
 * Board.cpp
 *
 *  Created on: Oct 4, 2021
 *      Author: black
 */

#include "board.h"

Board::Board() {
	// TODO Auto-generated constructor stub

}

void Board::initBoard(bool manual) {

}

void Board::manuallyPlaceShips() {

}

void Board::randomlyPlaceShips() {

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
}

	return ok;
}

void makeRandomMove()
{

}
