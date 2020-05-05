/***************************************************************************
****************************************************************************
 * \file ConsoleView.cpp
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 30.11.2019
 *
 * \brief ConsoleView.cpp
 *
 * Source file to print the board of own grid and opponent grid.
 *
****************************************************************************/

#include "ConsoleView.h"

ConsoleView::ConsoleView(Board *board)
{
	m_pboard = board;
	m_pdisplayOwnBoard = NULL;
	m_pdisplayOpponentBoard =NULL;
}


void ConsoleView::printOwnBoard()
{
	m_pdisplayOwnBoard = m_pboard->getOwnBoard();
	printBoard(m_pdisplayOwnBoard);
}

void ConsoleView::printOpponentBoard()
{
	m_pdisplayOpponentBoard = m_pboard->getOpponentBoard();
	printBoard(m_pdisplayOpponentBoard);
}

void ConsoleView::printBoard(char **pBoard)
{
	cout<<endl;
	cout<<"\t \t1\t2\t3\t4\t5\t6\t7\t8\t9\t10"<<endl;
	for (int rowIndex =0 ; rowIndex < BOARD_SIZE;rowIndex++)
	{
		cout <<"\t"<<char(rowIndex+65);
		for (int colIndex =0 ; colIndex < BOARD_SIZE;colIndex++)
		{
			cout<<"\t"<<pBoard[rowIndex][colIndex];
		}
		cout <<endl;
	}
}

ConsoleView::~ConsoleView()
{

}
