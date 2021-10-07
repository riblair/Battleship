/*
 * Tests.cpp
 *
 *  Created on: Oct 4, 2021
 *      Author: Ryand
 */

#include "Tests.h"
#include "Board.h"
#include "Ship.h"

Tests::Tests() {
	// TODO Auto-generated constructor stub

}

Tests::~Tests() {
	// TODO Auto-generated destructor stub
}

bool Tests::tests() {
	bool answer = true;

	bool ok1 = testCheckShip();
	bool ok2 = testmanuallyPlaceShips();
	//bool ok2 = true;
	bool ok3 = testrandomlyPlaceShips();
	bool ok4 = testCheckMove();
	bool ok5 = testMakePlayerMove();
	bool ok6 = testMakeRandomMove();
	bool ok7 = testUpdateHits();
	bool ok8 = testIsSunk();

	answer = ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8;
	return answer;
}


bool Tests::testCheckShip() {

	bool placed = false;
	Board* board = new Board();
	Ship* shippy = new Ship(5,'a');
	Location** shippyLoc = (Location**)malloc(5*sizeof(Location*));

	Location* loc1 = (Location*)malloc(sizeof(Location));
	Location* loc2 = (Location*)malloc(sizeof(Location));
	Location* loc3 = (Location*)malloc(sizeof(Location));
	Location* loc4 = (Location*)malloc(sizeof(Location));
	Location* loc5 = (Location*)malloc(sizeof(Location));
	Location* loc6 = (Location*)malloc(sizeof(Location));
	Location* loc7 = (Location*)malloc(sizeof(Location));
	Location* loc8 = (Location*)malloc(sizeof(Location));
	Location* loc9 = (Location*)malloc(sizeof(Location));
	Location* loc10 = (Location*)malloc(sizeof(Location));
	Location* loc11 = (Location*)malloc(sizeof(Location));
	Location* loc12 = (Location*)malloc(sizeof(Location));
	Location* loc13 = (Location*)malloc(sizeof(Location));
	Location* loc14 = (Location*)malloc(sizeof(Location));

	//out of bounds errors
	loc1->row = -1;
	loc1->col = 4;
	*(shippyLoc) = loc1;
	placed = placed||board->checkShip(shippy,shippyLoc,0);

	loc2->row = 4;
	loc2->col = -1;
	*(shippyLoc) = loc2;
	placed = placed||board->checkShip(shippy,shippyLoc,0);

	loc3->row = 8;
	loc3->col = 2;
	*(shippyLoc) = loc3;
	placed = placed||board->checkShip(shippy,shippyLoc,0);

	loc4->row = -1;
	loc4->col = -1;
	*(shippyLoc) = loc4;
	placed = placed||board->checkShip(shippy,shippyLoc,0);

	loc5->row = 2;
	loc5->col = 8;
	*(shippyLoc) = loc5;
	placed = placed||board->checkShip(shippy,shippyLoc,0);

	// testing the ship going out of bounds
	loc6->row = 2;
	loc6->col = 7;
	*(shippyLoc) = loc6;
	placed = placed||board->checkShip(shippy,shippyLoc,0);

	loc7->row = 2;
	loc7->col = 7;
	*(shippyLoc) = loc7;
	placed = placed||board->checkShip(shippy,shippyLoc,1);

	loc8->row = 6;
	loc8->col = 7;
	*(shippyLoc) = loc8;
	placed = placed||board->checkShip(shippy,shippyLoc,2);

	loc9->row = 2;
	loc9->col = 2;
	*(shippyLoc) = loc9;
	placed = placed||board->checkShip(shippy,shippyLoc,3);

	//testing collisions with a properly placed ship
	loc10->row = 3;
	loc10->col = 1;
	*(shippyLoc) = loc10;
	placed = placed || !(board->checkShip(shippy, shippyLoc, 1));

	loc11->row = 5;
	loc11->col = 4;
	*(shippyLoc) = loc11;
	placed = placed || board->checkShip(shippy, shippyLoc, 0);

	loc12->row = 3;
	loc12->col = 0;
	*(shippyLoc) = loc12;
	placed = placed || board->checkShip(shippy, shippyLoc, 1);

	loc13->row = 2;
	loc13->col = 5;
	*(shippyLoc) = loc13;
	placed = placed || board->checkShip(shippy, shippyLoc, 2);

	loc14->row = 3;
	loc14->col = 7;
	*(shippyLoc) = loc14;
	placed = placed || board->checkShip(shippy, shippyLoc, 3);

	if(!placed) {
		puts("testCheckShip Passed!");
		fflush(stdout);
	}
	else {
		puts("testCheckShip FAILED!");
		fflush(stdout);
	}
	return !placed;

}

bool Tests::testmanuallyPlaceShips() {
	bool worked = true;

	Board* board = new Board();
	worked = board->manuallyPlaceShips();
	if(worked) {
		puts("testmanuallyPlaceShips Passed!");
		fflush(stdout);
	}
	else {
		puts("testmanuallyPlaceShips FAILED!");
		fflush(stdout);
	}
	//if the function doesnt crash we r good!
	return worked;
}

bool Tests::testrandomlyPlaceShips() {
	bool worked = true;

	Board* board = new Board();
	worked = board->randomlyPlaceShips();
	if(worked) {
		puts("testrandomlyPlaceShips Passed!");
		fflush(stdout);
	}
	else {
		puts("testrandomlyPlaceShips FAILED!");
		fflush(stdout);
	}
	//if the function doesnt crash we r good!
	return worked;
}

bool Tests::testCheckMove()
{
	bool ok = true;
	Board* board = new Board();
	Location* loc = (Location*)malloc(sizeof(Location));
	loc->col = 0;
	loc->row = 0;
	ok = ok && board->checkMove(loc);
	loc->col = 100;
	loc->row = 0;
	ok = ok && !(board->checkMove(loc));
	loc->col = 0;
	loc->row = 100;
	ok = ok && !(board->checkMove(loc));
	loc->col = -100;
	loc->row = 0;
	ok = ok && !(board->checkMove(loc));
	loc->col = 0;
	loc->row = -100;
	ok = ok && !(board->checkMove(loc));
	board->board[0][0] = 'a';
	loc->col = 0;
	loc->row = 0;
	ok = ok && board->checkMove(loc);
	board->board[0][0] = 'b';
	ok = ok && board->checkMove(loc);
	board->board[0][0] = 'd';
	ok = ok && board->checkMove(loc);
	board->board[0][0] = 's';
	ok = ok && board->checkMove(loc);
	board->board[0][0] = 'a';
	ok = ok && board->checkMove(loc);
	board->board[0][0] = 'r';
	ok = ok && board->checkMove(loc);
	board->board[0][0] = 'X';
	ok = ok && !(board->checkMove(loc));
	board->board[0][0] = 'M';
	ok = ok && !(board->checkMove(loc));
	if(ok) {
		puts("testCheckMove Passed!");
		fflush(stdout);
	}
	else {
		puts("testCheckMove FAILED!");
		fflush(stdout);
	}
	return ok;

}

bool Tests::testMakePlayerMove()
{
	bool ok = true;
	Board* board = new Board();
	board->makePlayerMove();
	if(ok) {
		puts("testMakePlayerMove Passed!");
		fflush(stdout);
	}
	else {
		puts("testMakePlayerMove FAILED!");
		fflush(stdout);
	}
	return ok;
}
bool Tests::testMakeRandomMove()
{
	bool ok = true;
	Board* board = new Board();
	board->makeRandomMove();
	if(ok) {
		puts("testMakeRandomMove Passed!");
		fflush(stdout);
	}
	else {
		puts("testMakeRandomMove FAILED!");
		fflush(stdout);
	}
	return ok;
}

bool Tests::testUpdateHits()
{
	bool ok = true;
	Ship* testCruiser= new Ship(2, 'r');

	Location** shipLoc = (Location**)malloc(2*sizeof(Location*));
	Location*  loc1= (Location*)malloc(sizeof(Location));
	Location*  loc2= (Location*)malloc(sizeof(Location));

	loc1->col = 1;
	loc1->row = 1;
	loc2->col = 1;
	loc2->row = 2;
	*(shipLoc) = loc1;
	*(shipLoc+1) = loc2;


	testCruiser->updateShipLoc(shipLoc);

	testCruiser->updateHits(loc1);
	testCruiser->updateHits(loc2);

	if (testCruiser->isSunk()){
		ok = true;
	}
	else
		ok = false;

	if(ok) {
			puts("testUpdateHits Passed!");
			fflush(stdout);
		}
		else {
			puts("testUpdateHits1 FAILED!");
			fflush(stdout);
		}

	return ok;
}

bool Tests::testIsSunk()
{
	 bool ok = true;

	return ok;
}
