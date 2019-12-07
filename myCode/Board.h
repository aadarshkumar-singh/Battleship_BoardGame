/***************************************************************************
 ****************************************************************************
 * \file Board.h
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 30.11.2019
 *
 * \brief Board.h
 *
 *	Header file defines the APIs to creates own Grid and Opponent Grid .
 *	Defines API to place the Ship on Own Board,Checks the impact of opponent
 *	shot on own grid. It has API to determine the impact of the player shots
 *	on the opponent grid and to get sunken ships of opponent. Also Updates
 *	 if the player shot is a HIT or a MISS
 *
 * \note  The size of Own Grid Board and Opponent Grid Board is defined as
 *        BOARD_SIZE.
 *
 ****************************************************************************/


#ifndef BOARD_H_
#define BOARD_H_

#include "OwnGrid.h"
#include "OpponentGrid.h"

/**
 * \brief The size of the battleship board
 */
#define BOARD_SIZE 10

/**
 * \brief creates own Grid and Opponent Grid.
 *        place the Ships on Own Board, Checks the impact of opponent shot on own grid.
 *        determines the impact of the player shots on the opponent grid and
 *        updates if the player shot is a HIT/ MISS/SUNKEN
 */
class Board
{
	char** m_ownBoard ;          //!<Pointer to store Own Grid Board
	char** m_opponentBoard ;     //!<Pointer to store Opponent Grid Board
	OwnGrid m_ownGrid;           //!<Own Grid Object of battleship game.
	OpponentGrid m_opponentGrid; //!<Opponent Grid Object of battleship game.

	/**
	 * \brief Creates Empty Board of size rows and columns
	 * @param gameBoard : type <**char>: Pointer to store the empty board
	 * @param rows : type<int> : Rows of the board
	 * @param columns : type<int> : Columns of the board
	 */
	void createEmptyBoard(char **gameBoard,int rows, int columns);

public:

	/**
	 * \brief Creates OwnGrid and Opponent Grid of size row x column
	 *        Create an OwnGrid Board and OpponentGrid Empty board of row x column.
	 *
	 * @param rows : type<int> : Rows of the board
	 * @param columns : type<int> : Columns of the board
	 */
	Board(int rows, int columns);

	/**
	 * \brief Default Constructor
	 */
	Board();

	/**
	 * \brief Returns the row of Board
	 *
	 * @return type<int> Returns the row of Board
	 */
	int getRows();

	/**
	 * \brief Returns the column of Board
	 *
	 * @return type<int> Returns the column of Board
	 */
	int getColumns();

	/**
	 * \brief Returns address of the OwnGrid Board.
	 *
	 * @return type <**char>: Pointer to OwnGrid Board.
	 */
	char** getOwnBoard();

	/**
	 * \brief Returns address of the OpponentGrid Board.
	 *
	 * @return type <**char>: Pointer to OpponentGrid Board.
	 */
	char** getOpponentBoard();

	/**
	 * \brief API to Place the ship on Own Grid of the Board if its fulfills rearrangement rules
	 *
	 * @param   ship : type <Ship> Ship to be placed on OwnGrid Board
	 *
	 * @return  true : if ship can be placed
	 * 			false : if ship can't be placed
	 */
	bool setShipOnOwnBoard(const Ship& ship);

	/**
	 * \brief sets the impact of opponent shot on own grid board.
	 *
	 * @param shot takes the target Grid Position where the opponent want to shoot
	 *
	 * @return type<Impact_t> NONE: shot does not hit any ship placed on board.
	 * 						  HIT : shot hits part of a ship placed on board
	 * 						  SUNKEN : shot completely destroys a ship placed on the board
	 */
	Impact_t makeOpponentMoveOnOwnGrid(const Shot& shot);

	/**
	 * \brief sets the impact of the player shots on the opponent grid board.
	 * @param shot <type Shot> : target Grid position where player wants to shoot
	 * @param impact <type Impact_t > NONE: shot does not hit any ship placed on board.
	 * 						  		  HIT : shot hits part of a ship placed on board
	 * 						  		  SUNKEN : shot completely destroys a ship placed on the board
	 */
	void checkOwnMovesOnOpponentGrid(const Shot& shot,Impact_t impact);

	/**
	 * \brief Returns address of the Own Grid.
	 *
	 * @return type <OwnGrid>: Pointer to Own Grid.
	 */
	OwnGrid& getOwnGrid();

	/**
	 * \brief Returns address of the Opponent Grid.
	 *
	 * @return type <OpponentGrid>: Pointer to Opponent Grid.
	 */
	OpponentGrid& getOpponentGrid();

	/**
	 * \brief Destructor of the Board
	 */
	~Board();
};

#endif /* BOARD_H_ */
