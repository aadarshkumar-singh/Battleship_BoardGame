/*
 * OpponentGrid.cpp
 *
 *  Created on: Nov 30, 2019
 *      Author: Aadarshxp
 */

#include "OpponentGrid.h"

OpponentGrid::OpponentGrid(int rows, int columns)
{
	m_rows =rows ;
	m_columns =columns;
}

OpponentGrid::OpponentGrid()
{
	m_rows = 0;
	m_columns =0;
}

int OpponentGrid::getRows()
{
	return m_rows;
}

int OpponentGrid::getColumns()
{
	return m_columns;
}

void OpponentGrid::shotResult(const Shot &shot, Impact_t impact)
{
	set<GridPosition> sunkenShipPos;
	GridPosition targetPos = shot.getTargetPosition();
	m_shots[targetPos] = impact ;

	if (impact == SUNKEN)
	{
		sunkenShipPos.insert(targetPos);

		// Check is Ships extend on right side
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

		// Check is Ships extend on left hand side
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

		// Check is Ships extend on top side
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

		// Check is Ships extend on bottom side
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






