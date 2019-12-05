/*
 * OwnGrid.h
 *
 *  Created on: Nov 30, 2019
 *      Author: Aadarshxp
 */

#ifndef OWNGRID_H_
#define OWNGRID_H_

#include "Ship.h"
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

class OwnGrid
{
	int m_rows;
	int m_columns;
	vector<Ship> m_ships;
	map<int,int> m_limitOnPlaceShip ;


public:
	OwnGrid(int rows, int columns);
	OwnGrid();
	int getRows();
	int getColumns();
	bool placeShip(const Ship& ship);
	const vector<Ship> getShips() const;
	~OwnGrid();
};

#endif /* OWNGRID_H_ */
