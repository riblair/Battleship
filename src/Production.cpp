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
	int   option  = -1;
	Board* board1 = new Board();
	Board* board2 = new Board();
	board2->initBoard(false);

	printf ("> Please select from the following menu:\n");
		fflush(stdout);
		printf ("> [1] Manually\n");
		printf ("> [2] Randomly\n");
		printf ("> Enter Option: ");
		fflush(stdout);
		scanf ("%d", &option);
		fflush(stdin);


		switch (option) {
			case 1:
				board1->initBoard(true);
		            break;
			case 2:
				board1->initBoard(false);
					break;
		}
		return false;
}

Production::~Production() {
	// TODO Auto-generated destructor stub
}

