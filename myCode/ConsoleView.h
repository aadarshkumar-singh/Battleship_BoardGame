/***************************************************************************
****************************************************************************
 * \file ConsoleView.h
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 30.11.2019
 *
 * \brief ConsoleView.h
 *
 *	Header file to print the board of own grid and opponent grid.
 *
****************************************************************************/

#ifndef CONSOLEVIEW_H_
#define CONSOLEVIEW_H_

#include "Board.h"

/**
 * \brief prints the board of own grid and opponent grid.
 */
class ConsoleView
{
	char **m_pdisplayOwnBoard; 	    //!<Pointer to store the address of Own Grid Board
	char **m_pdisplayOpponentBoard; //!<Pointer to store the address of Opponent Grid Board
	Board *m_pboard;				//!<Pointer to store the address of board

	/**
	 * \brief API to print the board passed as parameter
	 * @param pBoard : Board that has to be printed.
	 */
	void printBoard(char **pBoard);

public:

	/**
	 * Constructor to store the address of the battleship board.
	 * @param board Pointer to the Battleship board
	 */
	ConsoleView(Board* board);

	/**
	 * \brief API to print opponent board
	 */
	void printOpponentBoard();

	/**
	 * \brief API to print Own board
	 */
	void printOwnBoard();

	/**
	 * \brief Destructor of opponent Board
	 */
	~ConsoleView();
};

#endif /* CONSOLEVIEW_H_ */
