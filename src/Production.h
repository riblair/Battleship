/*
 * Production.h
 *
 *  Created on: Oct 4, 2021
 *      Author: Ryand
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_
#include <stdio.h>
#include <stdbool.h>
#include <string.h>//strncpy
#include <stdlib.h>//strtol
#include "Board.h"

class Production {
public:
	Production();
	virtual ~Production();
	bool prod(int argc, char* argv[]);
private:
	void welcomeScreen();
	bool isWon(Board* board, Board* board2);
	void eraseLogFile();
};

#endif /* PRODUCTION_H_ */
