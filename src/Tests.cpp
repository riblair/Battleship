/*
 * Tests.cpp
 *
 *  Created on: Oct 4, 2021
 *      Author: Ryand
 */

#include "Tests.h"

Tests::Tests() {
	// TODO Auto-generated constructor stub

}

Tests::~Tests() {
	// TODO Auto-generated destructor stub
}

bool Tests::tests() {
	bool answer = true;

	bool ok1 = test1();

	answer = ok1;
	return answer;
}

bool Tests::test1() {
	return true;
}
