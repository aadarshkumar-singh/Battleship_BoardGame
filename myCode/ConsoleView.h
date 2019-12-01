/*
 * ConsoleView.h
 *
 *  Created on: Nov 30, 2019
 *      Author: Aadarshxp
 */

#ifndef CONSOLEVIEW_H_
#define CONSOLEVIEW_H_

#include "Board.h"

class ConsoleView
{
	Board* m_board;

public:
	ConsoleView(Board* board);
	void print();
	~ConsoleView();
};

#endif /* CONSOLEVIEW_H_ */
