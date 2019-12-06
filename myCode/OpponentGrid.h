/*
 * OpponentGrid.h
 *
 *  Created on: Nov 30, 2019
 *      Author: Aadarshxp
 */

#ifndef OPPONENTGRID_H_
#define OPPONENTGRID_H_

#include "Ship.h"
#include "Shot.h"
#include <map>
#include <vector>
using namespace std;

class OpponentGrid
{
	int m_rows;
	int m_columns;
	vector<Ship> m_sunkenShips;
	map<GridPosition,Impact_t> m_shots ;

public:
	OpponentGrid(int rows, int columns);
	OpponentGrid();
	int getRows();
	int getColumns();
	void shotResult(const Shot& shot, Impact_t impact);
	const map<GridPosition,Impact_t>& getShotsAt();
	const vector<Ship> getShunkenShipsOfOpponent();
	~OpponentGrid();
};

#endif /* OPPONENTGRID_H_ */
