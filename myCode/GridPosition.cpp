/*
 * GridPosition.cpp
 *
 *  Created on: Nov 30, 2019
 *      Author: Aadarshxp
 */
#include "GridPosition.h"

GridPosition::GridPosition(char row, int column)
{
	m_row = row;
	m_column = column;
}

GridPosition::GridPosition(string position)
{
	string row = position.substr(0,1);
	string column = position.substr(1);
	m_row = row.at(0);
	//ToDo , column string starting with word not handled.
	m_column = stoi(column);
}

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

bool GridPosition::operator==(GridPosition cmpGridPosition) const
{
	bool checkIfEqual = false ;
	if ((m_row == cmpGridPosition.getRow()) && (m_column == cmpGridPosition.getColumn()))
	{
		checkIfEqual = true;
	}
	return checkIfEqual;
}

bool GridPosition::operator<(GridPosition cmpGridPosition) const
{
	bool checkIfSmaller = false ;
	if (m_row < cmpGridPosition.getRow() || m_column < cmpGridPosition.getColumn())
	{
		checkIfSmaller = true ;
	}
	return checkIfSmaller;
}

GridPosition::GridPosition()
{
	m_column = 0;
	m_row='a';
}
