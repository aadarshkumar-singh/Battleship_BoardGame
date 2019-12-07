/***************************************************************************
****************************************************************************
 * \file Shot.cpp
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 5.12.2019
 *
 * \brief Shot.cpp
 *
 * Source file to set the target on the Grid Position where the player wants to shoot
 * and obtain the Grid Position which has been shot.
 *
 * \note  The impact on the Grid Position is defined as NONE,HIT,SUNKEN
 *
****************************************************************************/
#include "Shot.h"

/*Default constructor to initialize the Grid Position*/
Shot::Shot()
{
	m_targetPosition = GridPosition("A0");
}

/* Constructor sets the Grid Position which has to be targeted */
Shot::Shot(GridPosition targetPosition)
{
	m_targetPosition = targetPosition ;
}

/* Returns the targeted grid position*/
const GridPosition Shot::getTargetPosition() const
{
	return m_targetPosition ;
}

Shot::~Shot()
{
	// Does Nothing
}

