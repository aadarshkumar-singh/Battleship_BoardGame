/***************************************************************************
****************************************************************************
 * \file GridPosition.h
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 30.11.2019
 *
 * \brief GridPosition.h
 *
 *	Header file to create grid Positions using an alphabet and number.
 *	Also checks the created Grid Position is valid.
 *
 * \note  Alphabet can range from A to Z and numbers from 1 to 10.
 *
****************************************************************************/

#ifndef GRIDPOSITION_H_
#define GRIDPOSITION_H_

#include <string>

using namespace std;

/**
 * \brief creates Grid Positions and checks if its valid
 */
class GridPosition
{
	char m_row;    //!< Row of the Grid Position
	int  m_column; //!< Column of the Grid Position

public:

	/**
	 * Default constructor
	 */
	GridPosition();

	/**
	 * \brief Constructor which Creates a Grid Position with given row and column
	 * @param row  type<char> Row of the Grid Position
	 * @param column type<int> Column of the Grid Position
	 */
	GridPosition(char row, int column);

	/**
	 * \brief Constructor which Creates a Grid Position from a string
	 * @param position type<String> : Grid Position given as a string
	 */
	GridPosition(string position);

	/**
	 * \brief Checks if the grid position is valid or not.
	 *
	 * @return true if the Grid Position is a valid position
	 * 		   false if the Grid Position is invalid.
	 */
	bool isValid() const ;
	/**
	 * \brief returns the row of the Grid Position
	 *
	 * @return type <char> row of the Grid Position
	 */
	char getRow() const ;

	/**
	 * \brief returns the column of the Grid Position
	 *
	 * @return type<int> column of the Grid Position
	 */
	int getColumn() const;

	/**
	 * \brief Operator overloading of string so that
	 *        GridPosition can be considered as a string
	 */
	operator string()const ;

	/**
	 * \brief Equal to Operating Overloading on GridPosition Objects
	 * @param cmpGridPosition Grid Position to be equated with
	 * @return true if the two grids are equal.
	 *         false if the two grids are unequal.
	 */
	bool operator==(const GridPosition& cmpGridPosition) const;

	/**
	 * \brief less than Operating Overloading on GridPosition Objects
	 * @param cmpGridPosition Grid Position to be compared with
	 * @return true if first is smaller than the other
	 *         false if first is greater than the other
	 */
	bool operator<(const GridPosition& cmpGridPosition) const ;
};

#endif /* GRIDPOSITION_H_ */
