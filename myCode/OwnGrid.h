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

using namespace std;

class OwnGrid
{
	int m_rows;
	int m_columns;
	Ship m_ships;

public:
	OwnGrid(int rows, int columns);
	int getRows();
	int getColumns();
	bool placeShip(const Ship& ship);
	const vector<Ship> getShips();
	~OwnGrid();
};

#endif /* OWNGRID_H_ */
