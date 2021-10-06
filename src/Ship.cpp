/*
 * Ship.cpp
 *
 *  Created on: Oct 4, 2021
 *      Author: black
 */

#include "Ship.h"

Ship::Ship() {

}

Ship::Ship(int size, char name) {
	this->size = size;
	this->name = name;
	Location* positions[size];
	pos = *(positions);
	bool hitsArray[size];
	for(int i = 0; i < size; i++) {
		*(hitsArray+i) = false;
	}
	hits = hitsArray;
}

Ship::~Ship() {
	// TODO Auto-generated destructor stub
}

bool Ship::isSunk() {

	bool sunk = false;

	if(true){

	}

	return sunk;

}

void Ship::updateHits(Location* loc) {

	return;
}
void Ship::updateShipLoc(Location* pos) {
	this->pos = pos;
	return;
}

int Ship::getSize() {
	return size;
}
