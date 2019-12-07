/***************************************************************************
****************************************************************************
 * \file part2tests.cpp
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 30.11.2019
 *
 * \brief part2tests.cpp
 *
 *  Contains test cases for arrangement Rules on own grid
 *
****************************************************************************/

#include "Board.h"
#include "part2tests.h"

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTruePart2Test(bool condition, string failedMessage) {
    static int i =0;

	if (!condition) {
        cout << failedMessage << endl;
    }
    else
    {
    	cout <<"Part 2::>Test case ::> No "<<++i<<" Working"<<endl;
    }
}


/**
 */
void part2tests ()
{
	// Blocked area
	if (Ship{GridPosition{"B2"}, GridPosition{"C2"}}.isValid())
	{
		assertTruePart2Test(Ship{GridPosition{"B2"}, GridPosition{"C2"}}.blockedArea()
			            == set<GridPosition>{GridPosition{"A1"},
			    	GridPosition{"B1"}, GridPosition{"C1"},
					GridPosition{"D1"}, GridPosition{"A2"}, GridPosition{"B2"},
					GridPosition{"C2"}, GridPosition{"D2"}, GridPosition{"A3"},
					GridPosition{"B3"}, GridPosition{"C3"}, GridPosition{"D3"}},"Occupied area not correct");
	}
	else
	{
		cout <<"Invalid Ship for testing"<<endl;
	}

	// Placement Rules Limited Ships with given length can only be placed.
	OwnGrid testOwnGrid = OwnGrid(10,10);

	// check trying to place invalid length (> 5)
	assertTruePart2Test((!(testOwnGrid.placeShip(Ship{GridPosition{"B2"}, GridPosition{"F3"}}))),"Ship of invalid length placed");

	// check placing ships of length  5
	assertTruePart2Test(((testOwnGrid.placeShip(Ship{GridPosition{"B2"}, GridPosition{"F2"}}))),"More than 1 Ship of length 5 on board");
	assertTruePart2Test((!(testOwnGrid.placeShip(Ship{GridPosition{"D3"}, GridPosition{"D7"}}))),"More than 1 Ship of length 5 on board");

	// check placing ships of length  4
	assertTruePart2Test(((testOwnGrid.placeShip(Ship{GridPosition{"A4"}, GridPosition{"A7"}}))),"More than 2 Ship of length 4 on board");

	// When Placing ships where ship is already placed
	assertTruePart2Test((!(testOwnGrid.placeShip(Ship{GridPosition{"A4"}, GridPosition{"A7"}}))),"Placing ship where ship is already placed");

	// Check ships must not touch
	assertTruePart2Test((!(testOwnGrid.placeShip(Ship{GridPosition{"B4"}, GridPosition{"B7"}}))),"ships must not touch");

	// Again placing ship of length 4
	assertTruePart2Test(((testOwnGrid.placeShip(Ship{GridPosition{"C4"}, GridPosition{"C7"}}))),"More than 2 Ship of length 4 on board");
	assertTruePart2Test((!(testOwnGrid.placeShip(Ship{GridPosition{"E4"}, GridPosition{"E7"}}))),"More than 2 Ship of length 4 on board");

	// check placing ships of length  3
	assertTruePart2Test(((testOwnGrid.placeShip(Ship{GridPosition{"H1"}, GridPosition{"J1"}}))),"More than 3 Ship of length 3 on board");
	assertTruePart2Test(((testOwnGrid.placeShip(Ship{GridPosition{"H3"}, GridPosition{"J3"}}))),"More than 3 Ship of length 3 on board");
	assertTruePart2Test(((testOwnGrid.placeShip(Ship{GridPosition{"H5"}, GridPosition{"J5"}}))),"More than 3 Ship of length 3 on board");
	assertTruePart2Test((!(testOwnGrid.placeShip(Ship{GridPosition{"H7"}, GridPosition{"J7"}}))),"More than 3 Ship of length 3 on board");

	// check placing ships of length  2
	assertTruePart2Test(((testOwnGrid.placeShip(Ship{GridPosition{"A9"}, GridPosition{"A10"}}))),"More than 4 Ship of length 2 on board");
	assertTruePart2Test(((testOwnGrid.placeShip(Ship{GridPosition{"C9"}, GridPosition{"C10"}}))),"More than 4 Ship of length 2 on board");
	assertTruePart2Test(((testOwnGrid.placeShip(Ship{GridPosition{"E9"}, GridPosition{"E10"}}))),"More than 4 Ship of length 2 on board");
	assertTruePart2Test(((testOwnGrid.placeShip(Ship{GridPosition{"G9"}, GridPosition{"G10"}}))),"More than 4 Ship of length 2 on board");
	assertTruePart2Test((!(testOwnGrid.placeShip(Ship{GridPosition{"I9"}, GridPosition{"I10"}}))),"More than 4 Ship of length 2 on board");


}

