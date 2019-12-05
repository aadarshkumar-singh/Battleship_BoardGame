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
	m_pdisplayBoard = NULL;
}


void ConsoleView::print()
{
	m_pdisplayBoard = m_pboard->getOwnBoard();
	cout<<endl;
	cout<<"\t \t1\t2\t3\t4\t5\t6\t7\t8\t9\t10"<<endl;
	for (int rowIndex =0 ; rowIndex < BOARD_SIZE;rowIndex++)
	{
		cout <<"\t"<<char(rowIndex+65);
		for (int colIndex =0 ; colIndex < BOARD_SIZE;colIndex++)
		{
			cout<<"\t"<<m_pdisplayBoard[rowIndex][colIndex];
		}
		cout <<endl;
	}
}

ConsoleView::~ConsoleView()
{
	delete m_pboard;
}
