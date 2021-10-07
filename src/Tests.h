/*
 * Tests.h
 *
 *  Created on: Oct 4, 2021
 *      Author: Ryand
 */

#ifndef TESTS_H_
#define TESTS_H_
#include <stdio.h>

class Tests {
public:
	Tests();
	virtual ~Tests();
	bool tests();
private:
	bool testCheckShip();
	bool testmanuallyPlaceShips();
	bool testrandomlyPlaceShips();
	bool testCheckMove();
	bool testMakePlayerMove();
	bool testMakeRandomMove();
	bool testUpdateHits();
	bool testIsSunk();
};

#endif /* TESTS_H_ */
