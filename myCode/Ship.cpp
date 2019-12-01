/*
 * Ship.cpp
 *
 *  Created on: Nov 30, 2019
 *      Author: Aadarshxp
 */

#include "Ship.h"
#include "iostream"

using namespace std;

Ship::Ship(const GridPosition& bow,const GridPosition& stern)
{
	m_bow = bow ;
	m_stern = stern;
}

bool Ship::isValid() const
{
	bool checkSanity = false;

	if (m_bow.isValid() && m_stern.isValid())
	{
		if ((m_bow.getRow() == m_stern.getRow()) || (m_bow.getColumn() == m_stern.getColumn()))
		{
			if ((length() >= 2) && (length() <= 5))
			{
				checkSanity = true;
			}
		}
	}

	return checkSanity;

}

GridPosition Ship::getBow() const
{
	return m_bow;
}

GridPosition Ship::getStern() const
{
	return m_stern ;
}

int Ship::length() const
{
	int shipLength = 0 ;

	if (m_stern < m_bow)
	{
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


const set<GridPosition> Ship::occupiedArea()
{
	int shipLength = length();
	set<GridPosition> areaOccupied;
	set<GridPosition>::iterator it = areaOccupied.begin();
	char row;
	int column;

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
//
//const set<GridPosition> Ship::blockedArea()
//{
//
//
//}
//
