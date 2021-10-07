/*
 * Ship.cpp
 *
 *  Created on: Oct 4, 2021
 *      Author: black
 */

#include "Ship.h"
#include <stdlib.h>
#include <stdio.h>

Ship::Ship() {

}

Ship::Ship(int size, char name) {
	this->size = size;
	this->name = name;
	Location** positions = (Location**)malloc(size*sizeof(Location*));

	bool hitsArray[size];
	for(int i = 0; i < size; i++) {
		positions[i] = (Location*)malloc(sizeof(Location));
	}
	pos = positions;
	hits = 0;
}

Ship::~Ship() {
	// TODO Auto-generated destructor stub
}

bool Ship::isSunk() {

	bool sunk = false;
	if(hits == size){
		sunk = true;
	}

	return sunk;

}

void Ship::updateHits(Location* loc) {
	char* whichShip = "none";
	for(int i = 0; i < size; i++){
		if (loc->row == pos[i]->row || loc->col == pos[i]->col){
			hits++;
		}
	}
	if(this->isSunk()){


		switch(name)
			{
			case 'a':
				whichShip = "Carrier";
				break;
			case 'b':
				whichShip = "Battleship";
				break;
			case 'd':
				whichShip = "Destroyer";
				break;
			case 's':
				whichShip = "Sub";
				break;
			case 'r':
				whichShip = "Cruiser";
				break;
			default:
				whichShip = "none";
				break;

			}
	}
	printf("%s has been sunk!\n", whichShip);
	fflush(stdout);

	return;
}
void Ship::updateShipLoc(Location** pos) {
	this->pos = pos;
	return;
}

int Ship::getSize() {
	return size;
}

Location** Ship::getLocation() {
	return pos;
}

char Ship::getName() {
	return name;
}

