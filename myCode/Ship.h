/***************************************************************************
****************************************************************************
 * \file Ship.h
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 30.11.2019
 *
 * \brief Ship.h
 *
 *	Header file to create ships for the battleship game using the bow and
 *	stern positions. it checks the created ship is a valid ship also
 *	provides API to determine its size, occupied area and the blocked area.
 *
 * \note  The bow and stern indicates the ends of the ship. A valid Ship has
 * 		  length in between 2 and 5. Blocked area are all the tiles one step
 * 		  to the occupied area of the ship.
 *
****************************************************************************/
#ifndef SHIP_H_
#define SHIP_H_

#include "GridPosition.h"
#include <set>

using namespace std;


/**
 * \brief Minimum size possible for the ship
 */
#define SHIP_MINIMUM_SIZE 2

/**
 * \brief Maximum size possible for the ship
 */
#define SHIP_MAXIMUM_SIZE 5

/**
 * \brief create ships using the bow and stern positions
 * 		  checks the created ship is a valid ship
 * 		  determines the size, occupied area and blocked area of ship
 */
class Ship
{
	GridPosition m_bow; 	//!< Bow(End1) of the ship
	GridPosition m_stern;	//!< Stern(End2) of the ship

public:
	/**
	 * \brief sets the bow(end1) and stern(end2) of the ship.
	 * @param bow 	: type<GridPosition> END1 of the ship
	 * @param stern : type<GridPosition> END2 of the ship
	 */
	Ship(const GridPosition& bow,const GridPosition& stern);

	/**
	 * \brief Checks if the ship created is valid or not
	 * @return true  : Valid Ship
	 * 		   false : Invalid Ship
	 */
	bool isValid() const ;

	/**
	 *  \brief Returns the bow (END1) of the ship.
	 *
	 *  @return  type<GridPosition> END1 of the ship.
	 */
	GridPosition getBow() const ;

	/**
	 * \brief  Returns the stern(END2) of the ship.
	 *
	 * @return type<GridPosition> stern(END2) of the ship.
	 */
	GridPosition getStern()const ;

	/**
	 * \brief  Returns the length of the ship.
	 *
	 * @return type<int> Length of the ship
	 */
	int length() const;

	/**
	 * \brief All grid positions in which ships are present.
	 *
	 * @return set<GridPosition> : All grid positions in which ships are present.
	 */
	const set<GridPosition> occupiedArea() const;

	/**
	 * \brief All grid positions in which ships are present and the grid positions
	 *        one step near to the occupied area
	 *
	 * @return set<GridPosition> : All grid positions in which ships are present
	 *							   and the grid positions one step near to the
	 *							   occupied area.
	 */
	const set<GridPosition> blockedArea() const;
};

#endif /* SHIP_H_ */
