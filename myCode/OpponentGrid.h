/***************************************************************************
****************************************************************************
 * \file OpponentGrid.h
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 30.11.2019
 *
 * \brief OpponentGrid.h
 *
 * Header file to determine the impact of the player shots on the
 * opponent grid.It provides information on sunken ships of opponent
 * Also Updates if the player shot is a HIT or a MISS
 *
****************************************************************************/

#ifndef OPPONENTGRID_H_
#define OPPONENTGRID_H_

#include "Ship.h"
#include "Shot.h"
#include <map>
#include <vector>
using namespace std;

/**
 * \brief determine the impact of the player shots on the opponent grid.
 *        gives all the sunken ships of opponent, Also Updates if the
 *        player shot is a HIT or a MISS
 */
class OpponentGrid
{
	int m_rows; 	//!< Number of rows in opponent Grid
	int m_columns;  //!< Number of columns in opponent Grid
	vector<Ship> m_sunkenShips; //!< Vector containing list of all sunken ships
	map<GridPosition,Impact_t> m_shots ; //!< Map containing impact of shots in a given grid position.

public:

	/**
	 * \brief Sets the Rows and columns of opponent grid
	 *
	 * @param rows Number of rows in opponent Grid
	 * @param columns Number of columns in opponent Grid
	 *
	 */
	OpponentGrid(int rows, int columns);

	/**
	 * \brief Default Constructor of opponent Grid.
	 */
	OpponentGrid();

	/**
	 * \brief Returns Number of rows in opponent Grid
	 *
	 * @return type<int> Number of rows in opponent Grid
	 */
	int getRows();

	/**
	 * \brief Returns Number of columns in opponent Grid
	 *
	 * @return type<int> Number of columns in opponent Grid
	 */
	int getColumns();

	/**
	 * \brief Determine the impact of a shot
	 *
	 * @param shot <type Shot> : target Grid position where player wants to shoot
	 * @param impact <type Impact_t > NONE: shot does not hit any ship placed on board.
	 * 						  		  HIT : shot hits part of a ship placed on board
	 * 						  		  SUNKEN : shot completely destroys a ship placed on the board
	 */
	void shotResult(const Shot& shot, Impact_t impact);

	/**
	 * \brief Maps impact to the target grid position which was shot by player.
	 *
	 * @return type<map<GridPosition,Impact_t>> Map containing the impact on a grid Position
	 */
	const map<GridPosition,Impact_t>& getShotsAt();

	/**
	 * \brief returns all the sunken ships of opponent
	 *
	 * @return type<vector<Ship>> All the sunken ships of opponent
	 */
	const vector<Ship> getShunkenShipsOfOpponent();

	/**
	 * \brief destructor of Opponent Grid
	 */
	~OpponentGrid();
};

#endif /* OPPONENTGRID_H_ */
