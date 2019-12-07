/***************************************************************************
****************************************************************************
 * \file Ship.cpp
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 30.11.2019
 *
 * \brief Ship.cpp
 *
 *	Source file to create ships for the battleship game using the bow and
 *	stern positions. it checks the created ship is a valid ship also
 *	provides API to determine its size, occupied area and the blocked area.
 *
 * \note  The bow and stern indicates the ends of the ship. A valid Ship has
 * 		  length in between 2 and 5. Blocked area are all the tiles one step
 * 		  to the occupied area of the ship.
 *
****************************************************************************/

#include "Ship.h"
#include "iostream"

using namespace std;

/* sets the bow(end1) and stern(end2) of the ship. */
Ship::Ship(const GridPosition& bow,const GridPosition& stern)
{
	m_bow = bow ;
	m_stern = stern;
}

/*Checks if the ship created is valid or not*/
bool Ship::isValid() const
{
	bool checkSanity = false;

	/* Checks if bow and stern Grid is valid*/
	if (m_bow.isValid() && m_stern.isValid())
	{
		/*
		 * The ships can only be placed horizontally or vertically , either row or column of ends should
		 * be same
		 */
		if ((m_bow.getRow() == m_stern.getRow()) || (m_bow.getColumn() == m_stern.getColumn()))
		{
			if ((length() >= SHIP_MINIMUM_SIZE) && (length() <= SHIP_MAXIMUM_SIZE))
			{
				checkSanity = true;
			}
		}
	}

	return checkSanity;

}

/*Returns the bow (END1) of the ship.*/
GridPosition Ship::getBow() const
{
	return m_bow;
}

/*Returns the stern (END2) of the ship.*/
GridPosition Ship::getStern() const
{
	return m_stern ;
}

int Ship::length() const
{
	int shipLength = 0 ;

	/* The ships can be placed vertically and horizontally in any way  */
	if (m_stern < m_bow)
	{
		/* if placed horizontal*/
		if(m_bow.getRow() == m_stern.getRow())
		{
			shipLength = (m_bow.getColumn() - m_stern.getColumn()) + 1;
		}
		else
		{
			shipLength = (m_bow.getRow() - m_stern.getRow()) + 1;
		}
	}
	else
	{
		if(m_bow.getRow() == m_stern.getRow())
		{
			shipLength = (m_stern.getColumn() - m_bow.getColumn()) + 1;
		}
		else
		{
			shipLength = (m_stern.getRow() - m_bow.getRow()) + 1;
		}
	}

	return shipLength ;

}

/*All grid positions in which ships are present are returned*/
const set<GridPosition> Ship::occupiedArea() const
{
	int shipLength = length();
	int column;
	char row;
	set<GridPosition> areaOccupied;

	/* Determine the starting position to count grid Position occupied by the ship */
	if (m_bow < m_stern)
	{
		row = m_bow.getRow();
		column = m_bow.getColumn();
	}
	else
	{
		row = m_stern.getRow();
		column = m_stern.getColumn();
	}
	/* insert in a set all the grid position from starting to the length of ship */
	for (int i =0;i< shipLength ; i++)
	{
		if(m_bow.getRow() == m_stern.getRow())
		{
			areaOccupied.insert(GridPosition(row,column++));
		}
		else
		{
			areaOccupied.insert(GridPosition(row++,column));
		}
	}

	return areaOccupied ;
}

/*
 * All grid positions in which ships are present and the grid positions
 * one step near to the occupied area
 */
const set<GridPosition> Ship::blockedArea() const
{
	int shipLength = length();
	char traverseRow;
	int traverseColumn;
	set<GridPosition> areaBlocked;
	char row;
	int column;
	/* Determine the starting position to count grid Position blocked by the ship */
	if (m_bow < m_stern)
	{
		row = m_bow.getRow();
		column = m_bow.getColumn();
	}
	else
	{
		row = m_stern.getRow();
		column = m_stern.getColumn();
	}

	/* traverse one step in all direction from the starting position */
	for (int i =0;i< shipLength ; i++)
	{
		/*
		 * If placed horizontal keep traversing along the same row and
		 * increment the column by 1 from starting position
		 */
		if(m_bow.getRow() == m_stern.getRow())
		{
			for (char rowshift =-1 ; rowshift <= 1 ; rowshift++)
			{
				for (int colshift =-1 ; colshift <= 1 ; colshift++)
				{
					traverseRow = row + rowshift ;
					traverseColumn = column + colshift ;
					if (traverseRow >='A' && traverseRow <='J'  &&
							traverseColumn >= 1 && traverseColumn <= 10)
					{
						areaBlocked.insert(GridPosition(traverseRow,traverseColumn));
					}
				}
			}

			column++;
		}
		else
		{
			/*
			 * If placed vertically keep traversing along the same column and
			 * increment the row by 1 from starting position
			 */
			for (char rowshift =-1 ; rowshift <= 1 ; rowshift++)
			{
				for (int colshift =-1 ; colshift <= 1 ; colshift++)
				{
					traverseRow = row + rowshift ;
					traverseColumn = column + colshift ;
					if (traverseRow >='A' && traverseRow <='J'  &&
							traverseColumn >= 1 && traverseColumn <= 10)
					{
						areaBlocked.insert(GridPosition(traverseRow,traverseColumn));
					}
				}
			}
			row++;
		}
	}
	return areaBlocked;
}
