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
	char** m_opponentBoard ;
	OwnGrid m_ownGrid;
	OpponentGrid m_opponentGrid;
	void createEmptyBoard(char **gameBoard,int rows, int columns);
public:
	Board(int rows, int columns);
	Board();
	int getRows();
	int getColumns();
	char** getOwnBoard();
	char** getOpponentBoard();
	bool setShipOnBoard(const Ship& ship);
	Impact_t makeOpponentMoveOnOwnGrid(const Shot& shot);
	void checkOwnMovesOnOpponentGrid(const Shot& shot,Impact_t impact);
	OwnGrid& getOwnGrid();
	OpponentGrid& getOpponentGrid();
	~Board();
};

#endif /* BOARD_H_ */
