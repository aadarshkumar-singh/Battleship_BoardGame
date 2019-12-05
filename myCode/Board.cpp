/*
 * Board.cpp
 *
 *  Created on: Nov 30, 2019
 *      Author: Aadarshxp
 */

#include "Board.h"

Board::Board(int rows, int columns)
{
	m_ownGrid = OwnGrid(rows,columns);
	m_ownBoard = new char*[rows];
	for (int rowIndex = 0; rowIndex < 10; rowIndex++)
	{
		m_ownBoard[rowIndex] = new char[columns];
	}
	createEmptyBoard();
}

int Board::getRows()
{
	return (m_ownGrid.getRows());
}

int Board::getColumns()
{
	return(m_ownGrid.getColumns());
}

OwnGrid& Board::getOwnGrid()
{
	return (m_ownGrid);
}

Board::Board()
{

}

void Board::createEmptyBoard()
{
	for (int rowIndex =0 ; rowIndex < m_ownGrid.getRows();rowIndex++)
	{
		for (int colIndex =0 ; colIndex < m_ownGrid.getRows();colIndex++)
		{
			m_ownBoard[rowIndex][colIndex] = '~';
		}
	}

}

char** Board::getOwnBoard()
{
	return(m_ownBoard);
}

bool Board::setShipOnBoard(const Ship &ship)
{
	bool checkFlag = false ;
	set<GridPosition> toBePlacedOnBoard ;
	if (m_ownGrid.placeShip(ship))
	{
		checkFlag = true;
		toBePlacedOnBoard = ship.occupiedArea();
		for(set<GridPosition>::iterator it = toBePlacedOnBoard.begin(); it != toBePlacedOnBoard.end(); ++it)
		{
			//cout <<it->getRow()<<it->getColumn()<<"  ";

			for (int rowIndex =0 ; rowIndex < m_ownGrid.getRows();rowIndex++)
			{
				for (int colIndex =0 ; colIndex < m_ownGrid.getRows();colIndex++)
				{
					if((char(rowIndex+65) == it->getRow()) && (colIndex == (it->getColumn()-1)))
					{
						m_ownBoard[rowIndex][colIndex] = '#';
					}
				}
			}
		}
	}

	return checkFlag ;
}

//
//OpponentGrid& Board::getOpponentGrid()
//{
//}

Board::~Board()
{

}
