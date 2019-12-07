/***************************************************************************
****************************************************************************
 * \file OpponentGrid.cpp
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 30.11.2019
 *
 * \brief OpponentGrid.cpp
 *
 * Source file to determine the impact of the player shots on the
 * opponent grid.It provides information on sunken ships of opponent
 * Also Updates if the player shot is a HIT or a MISS
 *
****************************************************************************/

#include "OpponentGrid.h"

/*Sets the Rows and columns of opponent grid*/
OpponentGrid::OpponentGrid(int rows, int columns)
{
	m_rows =rows ;
	m_columns =columns;
}

/*Default constructor*/
OpponentGrid::OpponentGrid()
{
	m_rows = 0;
	m_columns =0;
}
/*Rows of opponent grid*/
int OpponentGrid::getRows()
{
	return m_rows;
}
/*Columns of opponent grid*/
int OpponentGrid::getColumns()
{
	return m_columns;
}

/*Determine the impact of a shot*/
void OpponentGrid::shotResult(const Shot &shot, Impact_t impact)
{
	set<GridPosition> sunkenShipPos;
	GridPosition targetPos = shot.getTargetPosition();
	m_shots[targetPos] = impact ;

	if (impact == SUNKEN)
	{
		sunkenShipPos.insert(targetPos);

		// Check is Ships can stretch on right hand side
		for (int colIndex =1  ; colIndex <5; colIndex++)
		{
			// check if grid positions exists in the map as key
			if(m_shots.count(GridPosition(targetPos.getRow(),(targetPos.getColumn()+ colIndex)))>0)
			{
				if(m_shots[GridPosition(targetPos.getRow(),(targetPos.getColumn()+ colIndex))] == HIT)
				{
					sunkenShipPos.insert(GridPosition(targetPos.getRow(),(targetPos.getColumn()+ colIndex)));
				}
				else
				{
					break;
				}
			}

		}

		// Check is Ships can stretch on left hand side
		for (int colIndex =1  ; colIndex <5; colIndex++)
		{
			// check if grid positions exists in the map as key
			if(m_shots.count(GridPosition(targetPos.getRow(),(targetPos.getColumn()- colIndex)))>0)
			{
				if(m_shots[GridPosition(targetPos.getRow(),(targetPos.getColumn()- colIndex))] == HIT)
				{
					sunkenShipPos.insert(GridPosition(targetPos.getRow(),(targetPos.getColumn()- colIndex)));
				}
				else
				{
					break;
				}
			}
		}

		// Check is Ships can stretch on top side
		for (int rowIndex =1  ; rowIndex <5; rowIndex++)
		{
			// check if grid positions exists in the map as key
			if(m_shots.count(GridPosition((targetPos.getRow()+rowIndex),targetPos.getColumn())) > 0)
			{
				if(m_shots[GridPosition(targetPos.getRow()+rowIndex,(targetPos.getColumn()))] == HIT)
				{
					sunkenShipPos.insert(GridPosition((targetPos.getRow()+rowIndex),targetPos.getColumn()));
				}
				else
				{
					break;
				}
			}
		}

		// Check is Ships can stretch on bottom side
		for (int rowIndex =1  ; rowIndex <5; rowIndex++)
		{
			// check if grid positions exists in the map as key
			if(m_shots.count(GridPosition((targetPos.getRow()-rowIndex),targetPos.getColumn())) > 0)
			{
				if(m_shots[GridPosition((targetPos.getRow()-rowIndex),targetPos.getColumn())] == HIT)
				{
					sunkenShipPos.insert(GridPosition((targetPos.getRow()-rowIndex),targetPos.getColumn()));
				}
				else
				{
					break;
				}
			}
		}
		/*Starting and ending of the sunken ship set is the ships bow and stern*/
		m_sunkenShips.push_back(Ship(*sunkenShipPos.begin(),*sunkenShipPos.rbegin()));
	}

}

const map<GridPosition, Impact_t>& OpponentGrid::getShotsAt()
{
	return m_shots ;
}

const vector<Ship> OpponentGrid::getShunkenShipsOfOpponent()
{
	return m_sunkenShips;
}

OpponentGrid::~OpponentGrid()
{

}
