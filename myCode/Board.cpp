/***************************************************************************
****************************************************************************
 * \file Board.cpp
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 30.11.2019
 *
 * \brief Board.cpp
 *
 *	Source file defines the APIs to creates own Grid and Opponent Grid .
 *	Defines API to place the Ship on Own Board,Checks the impact of opponent
 *	shot on own grid. It has API to determine the impact of the player shots
 *	on the opponent grid and to get sunken ships of opponent. Also Updates
 *	 if the player shot is a HIT or a MISS
 *
 * \note  The size of Own Grid Board and Opponent Grid Board is defined as
 *        BOARD_SIZE.
 *
****************************************************************************/

#include "Board.h"


Board::Board(int rows, int columns)
{
	/*Create own Grid */
	m_ownGrid = OwnGrid(rows,columns);

	/*Create opponent Grid */
	m_opponentGrid = OpponentGrid(rows,columns);

	/*Create Own grid Board*/
	m_ownBoard = new char*[rows];
	for (int rowIndex = 0; rowIndex < rows; rowIndex++)
	{
		m_ownBoard[rowIndex] = new char[columns];
	}

	/*Create Opponent grid Board*/
	m_opponentBoard = new char*[rows];
	for (int rowIndex = 0; rowIndex < rows; rowIndex++)
	{
		m_opponentBoard[rowIndex] = new char[columns];
	}
	/*Fill the Own Grid and opponent grid board with empty state */
	createEmptyBoard(m_ownBoard,rows,columns);
	createEmptyBoard(m_opponentBoard,rows,columns);
}

/* Return rows of the board */
int Board::getRows()
{
	return (m_ownGrid.getRows());
}

/* Return columns of the board */
int Board::getColumns()
{
	return(m_ownGrid.getColumns());
}

/* Return the own grid */
OwnGrid& Board::getOwnGrid()
{
	return (m_ownGrid);
}

/*Default Construtor*/
Board::Board()
{

}

/* Create Empty board of size row x column*/
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

/*Return own Board */
char** Board::getOwnBoard()
{
	return(m_ownBoard);
}

/*Return opponent Board */
char** Board::getOpponentBoard()
{
	return(m_opponentBoard);
}

/*API to Place the ship on Own Grid of the Board if its fulfills rearrangement rules*/
bool Board::setShipOnOwnBoard(const Ship &ship)
{
	bool checkFlag = false ;
	set<GridPosition> toBePlacedOnBoard ;

	// if ship fulfills the arrangement rules
	if (m_ownGrid.placeShip(ship))
	{
		checkFlag = true;
		toBePlacedOnBoard = ship.occupiedArea();

		// place all the grid position set of the occupied area on the board.
		for(set<GridPosition>::iterator iteratorGridPos = toBePlacedOnBoard.begin(); iteratorGridPos != toBePlacedOnBoard.end(); ++iteratorGridPos)
		{
			for (int rowIndex =0 ; rowIndex < m_ownGrid.getRows();rowIndex++)
			{
				for (int colIndex =0 ; colIndex < m_ownGrid.getRows();colIndex++)
				{
					if((char(rowIndex+65) == iteratorGridPos->getRow()) && (colIndex == (iteratorGridPos->getColumn()-1)))
					{
						m_ownBoard[rowIndex][colIndex] = '#';
					}
				}
			}
		}
	}

	return checkFlag ;
}

/*sets the impact of opponent shot on own grid board.*/
Impact_t Board::makeOpponentMoveOnOwnGrid(const Shot& shot)
{
	Impact_t checkResults = NONE;
	GridPosition shotPosition = shot.getTargetPosition();
	int row = ((int)shotPosition.getRow()-65);
	int column = (shotPosition.getColumn()-1);
	checkResults = m_ownGrid.takeBlow(shot);

	//Check if shot has resulted in hit update the own grid Board
	if (checkResults == NONE)
	{
		m_ownBoard[row][column] ='^';
	}
	//Check if shot has resulted in miss update the own grid Board
	else if (checkResults == HIT)
	{
		m_ownBoard[row][column] = 'O';
	}
	//Check if shot has resulted sunken update the own grid Board
	else if (checkResults == SUNKEN)
	{
		// Get the sunken ship from the own grid and place on the board.
		set<GridPosition> ownSunkenShips = m_ownGrid.getSunkenShipOwnGrid();
		for (auto iteratorGrid : ownSunkenShips)
		{
			m_ownBoard[((int)iteratorGrid.getRow()-65)][(iteratorGrid.getColumn()-1)] = 'X';
		}
	}
	return checkResults;
}

// Return the opponent Grid
OpponentGrid& Board::getOpponentGrid()
{
	return (m_opponentGrid);
}

/*sets the impact of the player shots on the opponent grid board.*/
void Board::checkOwnMovesOnOpponentGrid(const Shot &shot, Impact_t impact)
{
	int row =0;
	int column =0;
	vector<Ship> sunkenShipOpponent;
	m_opponentGrid.shotResult(shot,impact);

	//Iterate on Map that contains shots Position and corresponding Impact
	for ( auto iteratorMap : m_opponentGrid.getShotsAt())
	{
		row =(iteratorMap.first.getRow()-65);
		column = (iteratorMap.first.getColumn()-1);

		// update hit on opponent Board
		if (iteratorMap.second == HIT)
		{
			m_opponentBoard[row][column] = 'O';
		}
		// update miss on opponent Board
		else if (iteratorMap.second == NONE)
		{
			m_opponentBoard[row][column] = '^';
		}
		//update sunken ships on opponent Board.
		else if(iteratorMap.second == SUNKEN)
		{
			// Get the sunken ship from the opponent grid and place on the board.
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

/*Destructor of the board Class*/
Board::~Board()
{
	for (int rowIndex = 0 ; rowIndex < BOARD_SIZE; rowIndex++)
	{
	    	delete[] m_ownBoard[rowIndex]; // clean up already allocated rows
	    	delete[] m_opponentBoard[rowIndex];
	}

	delete[] m_ownBoard;
	delete[] m_opponentBoard;
}
