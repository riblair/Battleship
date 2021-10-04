/*
 * Ship.h
 *
 *  Created on: Oct 4, 2021
 *      Author: black
 */

#ifndef SHIP_H_
#define SHIP_H_

class Ship {
public:
	Ship();
	virtual ~Ship();

	bool isSunk();
	void updateHits(Location* loc);
};

#endif /* SHIP_H_ */
