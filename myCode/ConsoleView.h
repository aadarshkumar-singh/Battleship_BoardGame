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
	char **m_pdisplayBoard;
	Board *m_pboard;
	void createEmptyBoard();
public:
	ConsoleView(Board* board);
	void print();
	~ConsoleView();
};

#endif /* CONSOLEVIEW_H_ */
