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
	*ships = care;
	*(ships+1) = battle;
	*(ships+2) = destroy;
	*(ships+3) = sub;
	*(ships+4) = cruise;

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
		Ship* shippy = *(ships+i);
		int size = shippy->getSize();
		Location** locations = (Location**)malloc(size*sizeof(Location*));
		Location* shipLoc = (Location*)malloc(sizeof(Location)); // I could do shipLoc[*(*(ships+i))->getSize()] if shits not working
		*(locations) = shipLoc;
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
			if(checkShip(*(ships+i),locations,dir)) {
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
	placeAllShips();
}

void Board::randomlyPlaceShips() {

	for(int i = 0; i < 5; i++) {
		Ship* shippy = *(ships+i);
		int size = shippy->getSize();
		Location** locations = (Location**)malloc(size*sizeof(Location*));
		Location* shipLoc = (Location*)malloc(sizeof(Location));
		*(locations) = shipLoc;
		shipLoc->row = -1;
		shipLoc->col = -1;
		int row = -1;
		int col = -1;
		int dir = -1;
		bool correct = false;
		do {
			printf("trying to put ship # %d on the board \n", i);
			fflush(stdout);
			row = rand() % 8;
			col = rand() % 8;
			dir = rand() % 4;
			shipLoc->row = row;
			shipLoc->col = col;
			printf("ship is trying to be placed at (%d,%d) with direction %d \n",row,col,dir);
			fflush(stdout);
			if(checkShip(*(ships+i), locations, dir)) {
				correct = true;
				puts("ship is in valid location");
			}
			else {
				correct = false;
			}
		} while(!correct);
		puts("yay!");
		fflush(stdout);
	}
	placeAllShips();
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

bool Board::checkShip(Ship* ship, Location** loc, int dir) {
	int size = ship->getSize();
	Location* anchor = *(loc);
	if(dir < 0) {
		puts("Either dir was null, or dir was less than 0");
		fflush(stdout);
		return false;
	}
	if(anchor->col > 7 || anchor->col < 0 || anchor->row > 7 || anchor->row < 0) {
		puts("location suggested was out of bounds");
		fflush(stdout);
		return false;
	}
	//straight up
	if(dir == 0) {
		if(anchor->row-size < 0) {
			puts("Direction led ship out of bounds");
			fflush(stdout);
			return false;
		}
		for(int i = 0; i < size; i++) {
			Location* pos1 = (Location*)malloc(sizeof(Location));
			pos1->row = anchor->row-i;
			pos1->col = anchor->col;
			*(loc+i) = pos1;
			char place = board[anchor->row-i][anchor->col];
			printf("The character at (%d,%d) is %c \n",anchor->row - i,anchor->col,place);
			fflush(stdout);
			if(place != '~') {
				return false;
			}
		}
	}
	//right
	else if(dir == 1) {
		if(anchor->col+size > 7) {
			puts("Direction led ship out of bounds");
			fflush(stdout);
			return false;
		}
		for(int i = 0; i < size; i++) {
			Location* pos1 = (Location*)malloc(sizeof(Location));
			pos1->row = anchor->row;
			pos1->col = anchor->col+i;
			*(loc+i) = pos1;
			char place = board[anchor->row][anchor->col + i];
			printf("The character at (%d,%d) is %c \n",anchor->row,anchor->col + i,place);
			fflush(stdout);
			if(place != '~') {
				return false;
			}
		}
	}
	//straight down
	else if(dir == 2) {
		if(anchor->row+size > 7) {
			puts("Direction led ship out of bounds");
			fflush(stdout);
			return false;
		}
		for(int i = 0; i < size; i++) {
			Location* pos1 = (Location*)malloc(sizeof(Location));
			pos1->row = anchor->row+i;
			pos1->col = anchor->col;
			*(loc+i) = pos1;
			char place = board[anchor->row+i][anchor->col];
			printf("The character at (%d,%d) is %c \n",anchor->row + i,anchor->col,place);
			fflush(stdout);
			if(place != '~') {
				return false;
			}
		}
	}
	//left
	else { // (dir ==3)
		if(anchor->col-size < 0) {
			puts("Direction led ship out of bounds");
			fflush(stdout);
			return false;
		}
		for(int i = 0; i < size; i++) {
			Location* pos1 = (Location*)malloc(sizeof(Location));
			pos1->row = anchor->row;
			pos1->col = anchor->col-i;
			*(loc+i) = pos1;
			char place = board[anchor->row][anchor->col - i];
			printf("The character at (%d,%d) is %c \n",anchor->row,anchor->col - i,place);
			fflush(stdout);
			if(place != '~') {
				return false;
			}
		}
	}
	puts("success!!");
	fflush(stdout);
	ship->updateShipLoc(loc);
	return true;
}

void Board::placeAllShips() {
	for(int i = 0; i < 5; i++) {
		Ship* shippy = *(ships+i);
		Location** shipLoc = shippy->getLocation();
		int size = shippy->getSize();
		char c = shippy->getName();
		for(int j = 0; j < size; j++) {
			Location* loccy = *(shipLoc+j);
			board[loccy->row][loccy->col] = c;
		}
	}
	puts("Success!");
	fflush(stdout);
}

void Board::printMoveToFile(FILE* fp, Location* loc) {

}

void Board::printBoard(bool showShips) {

}

Board::~Board() {
	// TODO Auto-generated destructor stub
}

void Board::makePlayerMove()
{
	bool okMove = false;
	int row = -1;
	int col = -1;
	Location* loc = new Location();

	while(!okMove)
	{
		this->printBoard(false);
		puts("Enter a row number for hit (0-7)");
		fflush(stdout);
		scanf("%d",&row);
		puts("Enter a column number for hit (0-7)");
		fflush(stdout);
		scanf("%d",&col);
		loc->row = row;
		loc->col = col;
		okMove = this->checkMove(loc);
		if(!okMove)
		{
			puts("Move was invalid! Try Again Please");
			fflush(stdout);
		}
	}
	switch(board[row][col])
	{
	case 'a':
		puts("Hit!");
		fflush(stdout);
		care->updateHits(loc);
		board[row][col] = 'X';
		break;
	case 'b':
		puts("Hit!");
		fflush(stdout);
		battle->updateHits(loc);
		board[row][col] = 'X';
		break;
	case 'd':
		puts("Hit!");
		fflush(stdout);
		destroy->updateHits(loc);
		board[row][col] = 'X';
		break;
	case 's':
		puts("Hit!");
		fflush(stdout);
		sub->updateHits(loc);
		board[row][col] = 'X';
		break;
	case 'r':
		puts("Hit!");
		fflush(stdout);
		cruise->updateHits(loc);
		board[row][col] = 'X';
		break;
	default:
		puts("Miss!");
		fflush(stdout);
		board[row][col] = 'M';
		break;
	}
	this->printBoard(false);
}

bool Board::checkMove(Location* loc)
{

	bool ok = false;
	if(loc->col < 0 || loc->col > 8 || loc->row < 0 || loc->row > 8)
	{
		return ok;
	}
	int col = loc->col;
	int row = loc->row;
	if(board[row][col] == '~')
	{
		return true;
	}
	else if(board[row][col] == 'a' || board[row][col] == 'b' || board[row][col] == 'd' || board[row][col] == 's' || board[row][col] == 'r')
	{
		return true;
	}
	else if(board[row][col] == 'X' || board[row][col] == 'M')
	{
		return ok;
	}
	return ok;
}

void Board::makeRandomMove()
{

	bool okMove = false;
	int row = rand() % 8;
	int col = rand() % 8;
	Location* loc = new Location();
	this->printBoard(false);
	puts("Taking Random Move...");
	fflush(stdout);
	while(!okMove)
	{
		row = rand() % 8;
		col = rand() % 8;
		loc->row = row;
		loc->col = col;
		okMove = this->checkMove(loc);
	}
	switch(board[row][col])
	{
	case 'a':
		puts("Hit!");
		fflush(stdout);
		care->updateHits(loc);
		board[row][col] = 'X';
		break;
	case 'b':
		puts("Hit!");
		fflush(stdout);
		battle->updateHits(loc);
		board[row][col] = 'X';
		break;
	case 'd':
		puts("Hit!");
		fflush(stdout);
		destroy->updateHits(loc);
		board[row][col] = 'X';
		break;
	case 's':
		puts("Hit!");
		fflush(stdout);
		sub->updateHits(loc);
		board[row][col] = 'X';
		break;
	case 'r':
		puts("Hit!");
		fflush(stdout);
		cruise->updateHits(loc);
		board[row][col] = 'X';
		break;
	default:
		puts("Miss!");
		fflush(stdout);
		board[row][col] = 'M';
		break;
	}
	this->printBoard(false);
}
