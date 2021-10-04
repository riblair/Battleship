/*
 * Board.h
 *
 *  Created on: Oct 4, 2021
 *      Author: black
 */

#ifndef BOARD_H_
#define BOARD_H_
#include "ship.h"
#include <stdlib.h>
#include <stdio.h>

class Board {
public:
	Board();
	virtual ~Board();

	typedef struct Location{
		int row;
		int col;
	}Location;


	void initBoard(bool manual);

	void manuallyPlaceShips();
	void randomlyPlaceShips();
	bool checkShip(Ship* ship, Location* loc, int dir);

	void makePlayerMove();
	bool checkMove(Location* loc);
	void makeRandomMove();

	void printMoveToFile(FILE* fp, Location* loc);
	void printBoard(bool showShips);
private:
	char* board[8][8];
	bool showShips;
	Ship* battle;
	Ship* destroy;
	Ship* care;
	Ship* cruise;
	Ship* sub;
	int hits;
};

#endif /* BOARD_H_ */
