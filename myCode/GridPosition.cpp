/***************************************************************************
****************************************************************************
 * \file GridPosition.cpp
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 30.11.2019
 *
 * \brief GridPosition.cpp
 *
 *	Source file to create grid Positions using an alphabet and number.
 *	Also checks the created Grid Position is valid.
 *
 * \note  Alphabet can range from A to Z and numbers from 1 to 10.
 *
****************************************************************************/

#include "GridPosition.h"

GridPosition::GridPosition(char row, int column)
{
	m_row = row;
	m_column = column;
}

GridPosition::GridPosition(string position)
{
	/*Divide the string into two substring of size 1 and n*/

	string row = position.substr(0,1);
	string column = position.substr(1);

	/* convert the substring into char and number*/
	m_row = row.at(0);
	m_column = stoi(column);
}

/*Checks sanity of the Grid Positions*/
bool GridPosition::isValid() const
{
	bool checkSanity = false;
	if ((m_row >='A') && (m_row <='Z') && (m_column > 0))
	{
		checkSanity = true ;
	}
	return checkSanity ;
}

char GridPosition::getRow() const
{
	return m_row ;
}

int GridPosition::getColumn() const
{
	return m_column;
}

GridPosition::operator string() const
{
	string position;
	position.push_back(m_row);
	position = position + to_string(m_column);
	return position;
}

bool GridPosition::operator==(const GridPosition& cmpGridPosition) const
{
	bool checkIfEqual = false ;
	if ((m_row == cmpGridPosition.getRow()) && (m_column == cmpGridPosition.getColumn()))
	{
		checkIfEqual = true;
	}
	return checkIfEqual;
}

bool GridPosition::operator<(const GridPosition& cmpGridPosition) const
{
	bool checkIfSmaller = false ;

	/*Given that the increasing order is from A1 to J10 */
	/*Check the row is smaller*/
	if (m_row < cmpGridPosition.getRow())
	{
		return true ;
	}
	/*Check the row is greater*/
	else if (m_row > cmpGridPosition.getRow())
	{
		return false;
	}
	/*if equal than take the smaller column*/
	else if (m_row == cmpGridPosition.getRow())
	{
		if(m_column < cmpGridPosition.getColumn())
			return true ;
		else
			return false;
	}

	return checkIfSmaller;

}

GridPosition::GridPosition()
{
	m_column = 0;
	m_row='a';
}
