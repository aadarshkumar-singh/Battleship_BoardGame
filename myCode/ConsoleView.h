/*
 * ConsoleView.h
 *
 *  Created on: Nov 30, 2019
 *      Author: Aadarshxp
 */

#ifndef CONSOLEVIEW_H_
#define CONSOLEVIEW_H_

#include "Board.h"

#define BOARD_SIZE 10

class ConsoleView
{
	char **m_pdisplayOwnBoard;
	char **m_pdisplayOpponentBoard;
	Board *m_pboard;
	void printBoard(char **pBoard);

public:
	ConsoleView(Board* board);
	void printOpponentBoard();
	void printOwnBoard();
	~ConsoleView();
};

#endif /* CONSOLEVIEW_H_ */
