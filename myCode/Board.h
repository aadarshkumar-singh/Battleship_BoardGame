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
	char** m_ownBoard ;
	OwnGrid m_ownGrid;
	void createEmptyBoard();

	//OpponentGrid m_opponentGrid;
public:
	Board(int rows, int columns);
	Board();
	int getRows();
	int getColumns();
	char** getOwnBoard();
	bool setShipOnBoard(const Ship& ship);
	OwnGrid& getOwnGrid();
	OpponentGrid& getOpponentGrid();
	~Board();
};

#endif /* BOARD_H_ */
