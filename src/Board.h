/*
 * Board.h
 *
 *  Created on: Oct 4, 2021
 *      Author: black
 */

#ifndef BOARD_H_
#define BOARD_H_
#include "Ship.h"
#include <stdlib.h>
#include <stdio.h>

//typedef struct Location
//{
//	int row;
//	int col;
//}Location;

class Board {
public:
	Board();
	virtual ~Board();
	void initBoard(bool manual);

	bool manuallyPlaceShips();
	bool randomlyPlaceShips();
	bool checkShip(Ship* ship, Location** loc, int dir);

	void makePlayerMove();
	bool checkMove(Location* loc);
	void makeRandomMove();

	void printMoveToFile(Location* loc);
	void printBoard(bool showShips);

	int hits;
	char board[8][8];
private:

	Ship* battle;
	Ship* destroy;
	Ship* care;
	Ship* cruise;
	Ship* sub;
	Ship* ships[5];

};

#endif /* BOARD_H_ */
