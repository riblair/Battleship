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
	virtual ~Ship();
	bool isSunk();
	void updateHits(Location* loc);
	void updateShip(int size,char name,Location** pos, bool* hits);
private:
	int size;
	char name;
	Location* pos;
	bool* hits[];
};

#endif /* SHIP_H_ */
