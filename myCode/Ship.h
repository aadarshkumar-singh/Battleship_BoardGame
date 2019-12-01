/*
 * Ship.h
 *
 *  Created on: Nov 30, 2019
 *      Author: Aadarshxp
 */

#ifndef SHIP_H_
#define SHIP_H_

#include "GridPosition.h"
#include <set>

using namespace std;

class Ship
{
	GridPosition m_bow;
	GridPosition m_stern;

public:
	Ship(const GridPosition& bow,const GridPosition& stern);
	bool isValid() const ;
	GridPosition getBow() const ;
	GridPosition getStern()const ;
	int length() const;
	const set<GridPosition> occupiedArea();
	//const set<GridPosition> blockedArea();
};

#endif /* SHIP_H_ */
