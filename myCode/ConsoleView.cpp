/*
 * ConsoleView.cpp
 *
 *  Created on: Nov 30, 2019
 *      Author: Aadarshxp
 */

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
	delete m_pboard;
}
