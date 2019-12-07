// Standard (system) header files
#include <iostream>
#include <stdlib.h>
#include "part1tests.h"
#include "part2tests.h"
#include "part3tests.h"
#include "Board.h"
#include "ConsoleView.h"

// Add more standard header files as required
// #include <string>

using namespace std;

// Add your project's header files here
// #include "CFraction.h"

void simulatedGamePlay();

// Main program
int main (void)
{
	part1tests ();
	part2tests ();
	part3tests();
	cout <<"Check Game Play "<<endl;
	simulatedGamePlay();
	return 0;
}

void simulatedGamePlay()
{
	Board battleshipBoard(10,10);
	ConsoleView testConsoleView(&battleshipBoard);
	battleshipBoard.setShipOnOwnBoard(Ship{GridPosition{"B2"}, GridPosition{"B4"}});
	battleshipBoard.setShipOnOwnBoard(Ship{GridPosition{"D4"}, GridPosition{"G4"}});
	battleshipBoard.setShipOnOwnBoard(Ship{GridPosition{"F6"}, GridPosition{"F9"}});
	battleshipBoard.makeOpponentMoveOnOwnGrid(Shot{GridPosition{"B5"}});
	battleshipBoard.makeOpponentMoveOnOwnGrid(Shot{GridPosition{"B3"}});
	battleshipBoard.makeOpponentMoveOnOwnGrid(Shot{GridPosition{"B4"}});
	battleshipBoard.makeOpponentMoveOnOwnGrid(Shot{GridPosition{"F5"}});
	battleshipBoard.makeOpponentMoveOnOwnGrid(Shot{GridPosition{"D4"}});
	battleshipBoard.makeOpponentMoveOnOwnGrid(Shot{GridPosition{"G4"}});

	battleshipBoard.checkOwnMovesOnOpponentGrid(Shot{GridPosition{"C2"}}, NONE);
	battleshipBoard.checkOwnMovesOnOpponentGrid(Shot{GridPosition{"G5"}}, HIT);
	battleshipBoard.checkOwnMovesOnOpponentGrid(Shot{GridPosition{"F5"}}, NONE);
	battleshipBoard.checkOwnMovesOnOpponentGrid(Shot{GridPosition{"C3"}}, HIT);
	battleshipBoard.checkOwnMovesOnOpponentGrid(Shot{GridPosition{"G4"}}, NONE);
	battleshipBoard.checkOwnMovesOnOpponentGrid(Shot{GridPosition{"G6"}}, HIT);
	battleshipBoard.checkOwnMovesOnOpponentGrid(Shot{GridPosition{"C4"}}, HIT);
	battleshipBoard.checkOwnMovesOnOpponentGrid(Shot{GridPosition{"I5"}}, NONE);
	battleshipBoard.checkOwnMovesOnOpponentGrid(Shot{GridPosition{"C5"}}, SUNKEN);

	cout <<"Own Grid"<<endl;
	testConsoleView.printOwnBoard();
	cout <<"Opponent grid"<<endl;
	testConsoleView.printOpponentBoard();

}
