/***************************************************************************
****************************************************************************
 * \file OwnGrid.h
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 30.11.2019
 *
 * \brief OwnGrid.h
 *
 * Header file to place the ship on the Own grid in the board. it
 * Checks if ship can be placed based on arrangement rules of the game.
 * Returns all the ships placed on the Own grid. Checks the impact
 * of opponent shot on own grid.
 *
 * \note  Player can place maximum of 10 ships and there is a limit on
 * 		  the ship based on its size which can be placed on the board.
 * 		  Also two ships should never touch. The impact NONE, HIT, SUNKEN
 * 		  is returned based on the opponent shot on own Grid.
 *
****************************************************************************/
#ifndef OWNGRID_H_
#define OWNGRID_H_

#include "Ship.h"
#include "Shot.h"
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * \brief place the ship on the Own grid based on arrangement rules of the game.
 *        Checks the impact of opponent shot on own grid.
 */
class OwnGrid
{
	int m_rows;     //!< Number of rows in own Grid
	int m_columns;  //!< Number of columns in own Grid
	vector<Ship> m_ships;  //!< Vector containing all ships placed on OwnGrid
	map<int,int> m_limitOnPlaceShip ; //!< Map that contains number of allowed ships for each valid size of ship
	set<GridPosition> m_shotAt; //!< All grid Position shot by the opponent
	set<GridPosition> m_sunkenShipOwnGrid; //!< Set of grid position of sunken ship

public:

	/**
	 * Constructor that sets the row and column for the own grid.
	 * It sets the map that contains number of allowed ships for each valid size of ship
	 *
	 * @param rows Number of rows in own Grid
	 * @param columns Number of columns in own Grid
	 */
	OwnGrid(int rows, int columns);

	/**
	 * \brief Default constructor of Own Grids
	 */
	OwnGrid();

	/**
	 * \brief Returns the row of OwnGrid
	 *
	 * @return type<int> Returns the row of OwnGrid
	 */
	int getRows();

	/**
	 * \brief Returns the column of OwnGrid
	 *
	 * @return type<int> Returns the column of OwnGrid
	 */
	int getColumns();

	/**
	 * \brief API to Place the ship on Own Grid if its fulfills rearrangement rules
	 *
	 * @param   ship : type <Ship> Ship to be placed on OwnGrid
	 *
	 * @return  true : if ship can be placed
	 * 			false : if ship can't be placed
	 */
	bool placeShip(const Ship& ship);
	/**
	 * \brief Returns all the ships placed on the OwnGrid.
	 *
	 * @return vector<Ship> Containing all the ships placed on the OwnGrid.
	 */
	const vector<Ship> getShips() const;

	/**
	 * \brief determines the impact of opponent shot on own grid.
	 *
	 * @param shot takes the target Grid Position where the opponent want to shoot
	 *
	 * @return type<Impact_t> NONE: shot does not hit any ship placed on board.
	 * 						  HIT : shot hits part of a ship placed on board
	 * 						  SUNKEN : shot completely destroys a ship placed on the board
	 */
	Impact_t takeBlow(const Shot& shot);

	/**
	 * \brief All Grid position that are shot by the opponent are returned.
	 *
	 * @return type<set<GridPosition> All Grid position that are shot by the opponent
	 */
	const set<GridPosition> getShotAt();

	/**
	 * \brief All Grid position of destroyed Ship on OwnGrid are returned.
	 *
	 * @return type<set<GridPosition> All Grid position of destroyed Ship on OwnGrid.
	 */
	const set<GridPosition> getSunkenShipOwnGrid();

	/**
	 * Destructor of Own Grid
	 */
	~OwnGrid();
};

#endif /* OWNGRID_H_ */
