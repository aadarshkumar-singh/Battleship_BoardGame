/*
 * OwnGrid.cpp
 *
 *  Created on: Nov 30, 2019
 *      Author: Aadarshxp
 */

#include "OwnGrid.h"

OwnGrid::OwnGrid(int rows, int columns)
{
	m_rows = rows;
	m_columns = columns;
	m_limitOnPlaceShip ={{5,1},{4,2},{3,3},{2,4}};
}

int OwnGrid::getRows()
{
	return m_rows;
}

int OwnGrid::getColumns()
{
	return m_columns;
}

bool is_disjoint(const set<GridPosition> &set1, const set<GridPosition> &set2)
{
	if(set1.empty() || set2.empty()) return true;

	typename set<GridPosition>::const_iterator  it1 = set1.begin(), it1End = set1.end();
	typename set<GridPosition>::const_iterator  it2 = set2.begin(), it2End = set2.end();

	// when it1 is not at the end and it2 is also not at the end
	while(it1 != it1End && it2 != it2End)
	{
		if(*it1 == *it2) return false;
		if(*it1 < *it2) { it1++; }
		else { it2++; }
	}

	return true;
}


bool OwnGrid::placeShip(const Ship& ship)
{
	bool checkFlag = false ;
	int shipLength = ship.length();
	map<int,int>::iterator findAvailableShips ;
	set<GridPosition> GridPositionInOwnGrid;

	/* Check for valid length is not neccesary as
	 * we need to pass only valid ship to place ship
	 * so check for the length is already covered in isValid condition
	 * of ship. Hence finding value of a single key without itrating in for
	 */
	findAvailableShips = m_limitOnPlaceShip.find(shipLength);
	if(findAvailableShips != m_limitOnPlaceShip.end())
	{
		if (findAvailableShips->second > 0)
		{
			checkFlag = true ;
			findAvailableShips->second = findAvailableShips->second -1 ;
		}
		else
		{
			checkFlag = false;
			cout<<"Invalid"<<endl;
		}
	}

	if (checkFlag == true)
	{
		if(m_ships.empty())
		{
			cout <<"Added Extra Ship"<<endl;
			m_ships.push_back(ship);
		}
		else
		{
			for(vector<Ship>::iterator it = m_ships.begin(); it != m_ships.end(); ++it)
			{
				if(is_disjoint(it->blockedArea(),ship.occupiedArea()) == false)
				{
					checkFlag= false;
					cout<<"Invalid"<<endl;
					break;
				}
			}

			if (checkFlag == true)
			{
				m_ships.push_back(ship);
				cout <<"Added Extra Ship"<<endl;
			}

		}
	}

	return checkFlag;
}

const vector<Ship> OwnGrid::getShips() const
{
	return (m_ships);
}

OwnGrid::OwnGrid()
{
	m_rows= 0;
	m_columns = 0;
	m_limitOnPlaceShip ={{5,1},{4,2},{3,3},{2,4}};
}

OwnGrid::~OwnGrid()
{
}
