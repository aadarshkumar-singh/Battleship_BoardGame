/*
 * Shot.cpp
 *
 *  Created on: Dec 5, 2019
 *      Author: Aadarshxp
 */

#include "Shot.h"

Shot::Shot()
{

}

Shot::Shot(GridPosition targetPosition)
{
	m_targetPosition = targetPosition ;
}

const GridPosition Shot::getTargetPosition() const
{
	return m_targetPosition ;
}

Shot::~Shot()
{
	// TODO Auto-generated destructor stub
}

