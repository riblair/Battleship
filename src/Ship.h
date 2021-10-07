/*
 * Ship.h
 *
 *  Created on: Oct 4, 2021
 *      Author: black
 */

#ifndef SHIP_H_
#define SHIP_H_


typedef struct Location
{
	int row;
	int col;
}Location;

class Ship {
public:
	Ship();
	Ship(int size, char name);
	virtual ~Ship();
	bool isSunk();
	void updateHits(Location* loc);
	void updateShipLoc(Location** pos);
	int getSize();
	Location** getLocation();
	char getName();
private:
	int size;
	char name;
	Location** pos; // (3,4),(3,5),(3,6)
	int hits;
};

#endif /* SHIP_H_ */
