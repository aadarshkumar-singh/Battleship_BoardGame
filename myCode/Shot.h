/*
 * Shot.h
 *
 *  Created on: Dec 5, 2019
 *      Author: Aadarshxp
 */

#ifndef SHOT_H_
#define SHOT_H_

#include "GridPosition.h"

typedef enum Impact_e
{
	NONE,
	HIT,
	SUNKEN,
} Impact_t;

class Shot
{
	GridPosition m_targetPosition;

public:
	Shot(GridPosition targetPosition);
	Shot();
	const GridPosition getTargetPosition() const;
	~Shot();
};

#endif /* SHOT_H_ */
