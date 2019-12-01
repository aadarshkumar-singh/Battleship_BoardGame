/*
 * OpponentGrid.h
 *
 *  Created on: Nov 30, 2019
 *      Author: Aadarshxp
 */

#ifndef OPPONENTGRID_H_
#define OPPONENTGRID_H_

#include "Ship.h"

class OpponentGrid
{
	int m_rows;
	int m_columns;
	Ship m_sunkenShips;

public:
	OpponentGrid(int rows, int columns);
	int getRows();
	int getColumns();
	~OpponentGrid();
};

#endif /* OPPONENTGRID_H_ */
