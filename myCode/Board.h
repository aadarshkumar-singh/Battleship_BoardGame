/*
 * Board.h
 *
 *  Created on: Nov 30, 2019
 *      Author: Aadarshxp
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "OwnGrid.h"
#include "OpponentGrid.h"

class Board
{
	OwnGrid m_ownGrid;
	OpponentGrid m_opponentGrid;
public:
	Board(int rows, int columns);
	int getRows();
	int getColumns();
	OwnGrid& getOwnGrid();
	OpponentGrid& getOpponentGrid();
	~Board();
};

#endif /* BOARD_H_ */
