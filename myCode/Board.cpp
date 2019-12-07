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
	m_opponentGrid = OpponentGrid(rows,columns);

	m_ownBoard = new char*[rows];
	for (int rowIndex = 0; rowIndex < rows; rowIndex++)
	{
		m_ownBoard[rowIndex] = new char[columns];
	}

	m_opponentBoard = new char*[rows];
	for (int rowIndex = 0; rowIndex < rows; rowIndex++)
	{
		m_opponentBoard[rowIndex] = new char[columns];
	}

	createEmptyBoard(m_ownBoard,rows,columns);
	createEmptyBoard(m_opponentBoard,rows,columns);
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

void Board::createEmptyBoard(char **gameBoard,int rows, int columns)
{
	for (int rowIndex =0 ; rowIndex < rows ;rowIndex++)
	{
		for (int colIndex =0 ; colIndex < columns;colIndex++)
		{
			gameBoard[rowIndex][colIndex] = '~';
		}
	}
}

char** Board::getOwnBoard()
{
	return(m_ownBoard);
}

char** Board::getOpponentBoard()
{
	return(m_opponentBoard);
}

bool Board::setShipOnOwnBoard(const Ship &ship)
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

Impact_t Board::makeOpponentMoveOnOwnGrid(const Shot& shot)
{
	Impact_t checkResults = NONE;
	GridPosition shotPosition = shot.getTargetPosition();
	int row = ((int)shotPosition.getRow()-65);
	int column = (shotPosition.getColumn()-1);
	//set<GridPosition>::iterator it;
	checkResults = m_ownGrid.takeBlow(shot);

	if (checkResults == NONE)
	{
		cout<< "Its a miss"<<endl;
		m_ownBoard[row][column] ='^';
	}
	else if (checkResults == HIT)
	{
		cout<< "Its a hit"<<endl;
		m_ownBoard[row][column] = 'O';
	}
	else if (checkResults == SUNKEN)
	{
		cout<< "Ship Destroyed"<<endl;
		set<GridPosition> ownSunkenShips = m_ownGrid.getSunkenShipOwnGrid();
		for (auto iteratorGrid : ownSunkenShips)
		{
			m_ownBoard[((int)iteratorGrid.getRow()-65)][(iteratorGrid.getColumn()-1)] = 'X';
		}
	}
	return checkResults;
}

OpponentGrid& Board::getOpponentGrid()
{
	return (m_opponentGrid);
}

void Board::checkOwnMovesOnOpponentGrid(const Shot &shot, Impact_t impact)
{
	int row =0;
	int column =0;
	vector<Ship> sunkenShipOpponent;
	m_opponentGrid.shotResult(shot,impact);

	for ( auto iteratorMap : m_opponentGrid.getShotsAt())
	{
		row =(iteratorMap.first.getRow()-65);
		column = (iteratorMap.first.getColumn()-1);

		if (iteratorMap.second == HIT)
		{
			m_opponentBoard[row][column] = 'O';
		}
		else if (iteratorMap.second == NONE)
		{
			m_opponentBoard[row][column] = '^';
		}
		else if(iteratorMap.second == SUNKEN)
		{
			sunkenShipOpponent = m_opponentGrid.getShunkenShipsOfOpponent();
			for (auto iteratorShip : sunkenShipOpponent)
			{
				for (auto iteratorGridPos :iteratorShip.occupiedArea())
				{
					m_opponentBoard[iteratorGridPos.getRow()-65][iteratorGridPos.getColumn()-1]='#';
				}
			}
		}
	}
}

Board::~Board()
{

}
