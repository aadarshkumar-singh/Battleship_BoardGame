/***************************************************************************
****************************************************************************
 * \file OwnGrid.cpp
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 30.11.2019
 *
 * \brief OwnGrid.cpp
 *
 * Source file to place the ship on the Own grid. it Checks if ship can be
 * placed based on arrangement rules of the game.Checks the impact
 * of opponent shot on own grid.
 *
 * \note  Player can place maximum of 10 ships and there is a limit on
 * 		  the ship based on its size which can be placed on the board.
 * 		  Also two ships should never touch. The impact NONE, HIT, SUNKEN
 * 		  is returned based on the opponent shot on own Grid.
 *
****************************************************************************/

#include "OwnGrid.h"

/*
 * Sets the rows columns and limit on each size of ship
 */
OwnGrid::OwnGrid(int rows, int columns)
{
	m_rows = rows;
	m_columns = columns;
	m_limitOnPlaceShip ={{5,1},{4,2},{3,3},{2,4}};
}

OwnGrid::OwnGrid()
{
	m_rows= 0;
	m_columns = 0;
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

/*
 * Checks if intersection of two sets is empty
 */
bool is_disjoint(const set<GridPosition> &set1, const set<GridPosition> &set2)
{
	if(set1.empty() || set2.empty()) return true;

	typename set<GridPosition>::const_iterator  iteratorSet1 = set1.begin(), iteratorSet1End = set1.end();
	typename set<GridPosition>::const_iterator  iteratorSet2 = set2.begin(), iteratorSet2End = set2.end();

	/* Check till the end of iterator if they have common values*/
	while(iteratorSet1 != iteratorSet1End && iteratorSet2 != iteratorSet2End)
	{
		if(*iteratorSet1 == *iteratorSet2) return false;
		if(*iteratorSet1 < *iteratorSet2) { iteratorSet1++; }
		else { iteratorSet2++; }
	}
	return true;
}


bool OwnGrid::placeShip(const Ship& ship)
{
	bool checkFlag = false ;
	int shipLength = ship.length();
	map<int,int>::iterator findAvailableShips ;
	set<GridPosition> GridPositionInOwnGrid;

	/*Check if ship is a valid Ship*/
	if (ship.isValid())
	{
		/*Find if ship size is present in the map which has the limit on allowed ship size*/
		findAvailableShips = m_limitOnPlaceShip.find(shipLength);

		if(findAvailableShips != m_limitOnPlaceShip.end())
		{
			if (findAvailableShips->second > 0)
			{
				checkFlag = true ;
			}
			else
			{
				checkFlag = false;
				//cout<<"Invalid"<<endl;
			}
		}
		/* If Ship of that size is allowed to be placed on board */
		if (checkFlag == true)
		{
			if(m_ships.empty())
			{
				/*If Total ship on board empty directly insert and update the map */
				m_ships.push_back(ship);
				findAvailableShips->second = findAvailableShips->second -1 ;
			}
			else
			{
				/* Check if the ship touches with other ships on board */
				for(vector<Ship>::iterator it = m_ships.begin(); it != m_ships.end(); ++it)
				{
					// Means blocked area intersection with occupied area is not an empty set
					if(is_disjoint(it->blockedArea(),ship.occupiedArea()) == false)
					{
						checkFlag= false;
						break;
					}
				}

				if (checkFlag == true)
				{
					/*
					 * Add the ship in the vector of all ships placed on Own Grid since it doesnt touch
					 * any ship already placed on board and update the map.
					 */
					m_ships.push_back(ship);
					findAvailableShips->second = findAvailableShips->second -1 ;
				}
			}
		}

	}

	return checkFlag;
}

const vector<Ship> OwnGrid::getShips() const
{
	return (m_ships);
}

/*Checks the impact of opponent shot on own grid*/
Impact_t OwnGrid::takeBlow(const Shot& shot)
{
	Impact_t resultFlag = NONE;
	int LengthOfBlowOnShip;

	/*Traverse through all the ships placed on Own Grid*/
	for(vector<Ship>::iterator iteratorShips = m_ships.begin(); iteratorShips != m_ships.end(); ++iteratorShips)
	{
		set<GridPosition> BlowOnShip ;
		set<GridPosition> shipPositions = iteratorShips->occupiedArea();

		// target position is not present in this ship, goto next ship , iterate over all
		if (shipPositions.find(shot.getTargetPosition()) == shipPositions.end())
		{
			resultFlag = NONE;
		}
		else
		{
			// One shot can hit only one grid position, once hit we need to check if it just hit or sunk the current ship
			set_intersection(m_shotAt.begin(),m_shotAt.end(),shipPositions.begin(),shipPositions.end(),std::inserter(BlowOnShip,BlowOnShip.begin()));
			LengthOfBlowOnShip =BlowOnShip.size();
			/*check the intersected length is one less than size of ship s*/
			if(LengthOfBlowOnShip == (iteratorShips->length()-1))
			{
				/*Update the flag and insert the shots in total shots played by opponent*/
				resultFlag = SUNKEN;
				m_sunkenShipOwnGrid = shipPositions;
				m_shotAt.insert(shot.getTargetPosition());
				return (resultFlag);
			}
			else
			{
				resultFlag = HIT;
				m_shotAt.insert(shot.getTargetPosition());
				return (resultFlag);
			}
		}
	}
	m_shotAt.insert(shot.getTargetPosition());
	return resultFlag;
}

const set<GridPosition> OwnGrid::getShotAt()
{
	return m_shotAt ;
}

const set<GridPosition> OwnGrid::getSunkenShipOwnGrid()
{
	return m_sunkenShipOwnGrid ;
}

OwnGrid::~OwnGrid()
{

}
