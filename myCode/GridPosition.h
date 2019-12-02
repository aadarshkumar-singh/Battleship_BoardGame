/*
 * GridPosition.h
 *
 *  Created on: Nov 30, 2019
 *      Author: Aadarshxp
 */

#ifndef GRIDPOSITION_H_
#define GRIDPOSITION_H_

#include <string>

using namespace std;

class GridPosition
{
	char m_row;
	int  m_column;

public:

	GridPosition();
	GridPosition(char row, int column);
	GridPosition(string position);
	bool isValid() const ;
	char getRow() const ;
	int getColumn() const;
	operator string()const ;
	bool operator==(const GridPosition& cmpGridPosition) const;
	bool operator<(const GridPosition& cmpGridPosition) const ;
};

#endif /* GRIDPOSITION_H_ */
