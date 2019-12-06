/*
 * OwnGrid.h
 *
 *  Created on: Nov 30, 2019
 *      Author: Aadarshxp
 */

#ifndef OWNGRID_H_
#define OWNGRID_H_

#include "Ship.h"
#include "Shot.h"
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
	set<GridPosition> m_shotAt;
	set<GridPosition> m_sunkenShipOwnGrid;

public:
	OwnGrid(int rows, int columns);
	OwnGrid();
	int getRows();
	int getColumns();
	bool placeShip(const Ship& ship);
	const vector<Ship> getShips() const;
	Impact_t takeBlow(const Shot& shot);
	const set<GridPosition> getDestroyedShip();
	const set<GridPosition> getShotAt();
	const set<GridPosition> getSunkenShipOwnGrid();
	~OwnGrid();
};

#endif /* OWNGRID_H_ */
