/***************************************************************************
****************************************************************************
 * \file Shot.h
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 5.12.2019
 *
 * \brief Shot.h
 *
 * Header file to set the target on the Grid Position where the player wants to shoot
 * and obtain the Grid Position which has been shot.
 *
 * \note  The impact on the Grid Position is defined as NONE,HIT,SUNKEN
 *
****************************************************************************/

#ifndef SHOT_H_
#define SHOT_H_

#include "GridPosition.h"

/**
 * \brief Impact of Shot on the Ships placed on the battleship Board
 */
typedef enum Impact_e
{
	NONE,  	//!< NONE  : shot does not hit any ship placed on board.
	HIT,   	//!< HIT   : shot hits part of a ship placed on board
	SUNKEN,	//!< SUNKEN: shot completely destroys a ship placed on the board
} Impact_t;

/**
 * \brief sets the target on the Grid Position where the player wants to shoot
 * 		  obtains the Grid Position which has been shot.
 */
class Shot
{
	GridPosition m_targetPosition; //!< The target Grid Position which is to be shot.

public:

	/**
	 * \brief Constructor to set the target Grid Position.
	 * @param targetPosition : Grid Position where the player want to shoot.
	 */
	Shot(GridPosition targetPosition);

	/**
	 * Default constructor initializes the target Position.
	 */
	Shot();

	/**
	 * \brief The Grid Position which was targeted is returned.
	 * @return GridPosition : Returns the GridPosition which was targeted.
	 */
	const GridPosition getTargetPosition() const;

	/**
	 * Destructor of the Class Shot.
	 */
	~Shot();
};

#endif /* SHOT_H_ */
