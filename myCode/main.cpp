// Standard (system) header files
#include <iostream>
#include <stdlib.h>
#include "part1tests.h"
#include "part2tests.h"
#include "part3tests.h"
#include "Board.h"
#include "ConsoleView.h"

using namespace std;

/**
 * \brief Simulates the Battleship game and print the own and
 *        opponent grid boards.
 */
void simulatedGamePlay();

// Main program
int main (void)
{
	/* test cases for ships and GridPosition*/
	part1tests ();

	/* test cases for arrangement Rules on own grid */
	part2tests ();

	/* test cases for shots */
	part3tests();
	cout <<"Check Game Play "<<endl;

	/*Simulate the game*/
	simulatedGamePlay();
	return 0;
}

void simulatedGamePlay()
{
	/*Create board of size BOARD_SIZE*/
	Board battleshipBoard(BOARD_SIZE,BOARD_SIZE);
	ConsoleView testConsoleView(&battleshipBoard);

	/*place ship on the own Grid */
	battleshipBoard.setShipOnOwnBoard(Ship{GridPosition{"B2"}, GridPosition{"B4"}});
	battleshipBoard.setShipOnOwnBoard(Ship{GridPosition{"D4"}, GridPosition{"G4"}});
	battleshipBoard.setShipOnOwnBoard(Ship{GridPosition{"F6"}, GridPosition{"F9"}});
	/* Simulating opponent moves on own Grid*/
	battleshipBoard.makeOpponentMoveOnOwnGrid(Shot{GridPosition{"B5"}});
	battleshipBoard.makeOpponentMoveOnOwnGrid(Shot{GridPosition{"B3"}});
	battleshipBoard.makeOpponentMoveOnOwnGrid(Shot{GridPosition{"B4"}});
	battleshipBoard.makeOpponentMoveOnOwnGrid(Shot{GridPosition{"F5"}});
	battleshipBoard.makeOpponentMoveOnOwnGrid(Shot{GridPosition{"D4"}});
	battleshipBoard.makeOpponentMoveOnOwnGrid(Shot{GridPosition{"G4"}});

	/* Simulating player moves on opponent grid*/
	battleshipBoard.checkOwnMovesOnOpponentGrid(Shot{GridPosition{"C2"}}, NONE);
	battleshipBoard.checkOwnMovesOnOpponentGrid(Shot{GridPosition{"G5"}}, HIT);
	battleshipBoard.checkOwnMovesOnOpponentGrid(Shot{GridPosition{"F5"}}, NONE);
	battleshipBoard.checkOwnMovesOnOpponentGrid(Shot{GridPosition{"C3"}}, HIT);
	battleshipBoard.checkOwnMovesOnOpponentGrid(Shot{GridPosition{"G4"}}, NONE);
	battleshipBoard.checkOwnMovesOnOpponentGrid(Shot{GridPosition{"G6"}}, HIT);
	battleshipBoard.checkOwnMovesOnOpponentGrid(Shot{GridPosition{"C4"}}, HIT);
	battleshipBoard.checkOwnMovesOnOpponentGrid(Shot{GridPosition{"I5"}}, NONE);
	battleshipBoard.checkOwnMovesOnOpponentGrid(Shot{GridPosition{"C5"}}, SUNKEN);

	/* print own and opponent grid*/
	cout <<"Own Grid"<<endl;
	testConsoleView.printOwnBoard();
	cout <<"Opponent grid"<<endl;
	testConsoleView.printOpponentBoard();

}
