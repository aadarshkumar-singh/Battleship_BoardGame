/*
 * part2tests.cpp
 *
 *  Created on: 15.11.2019
 *      Author: mnl
 */


#include "Board.h"
#include "part2tests.h"
#include "ConsoleView.h"
/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
/*
void assertTrue(bool condition, string failedMessage) {
    static int i =0;
	if (!condition) {
        cout << failedMessage << endl;
    }
    else
    {
    	cout <<"Test case ::> No "<<++i<<" Working"<<endl;
    }
}
*/

/**
 */
void part2tests ()
{
	OwnGrid testGrid(2,5);
	vector<Ship> shipsOnBoard;
	vector<Ship> testShipsOnBoard;

	testGrid.placeShip(Ship{GridPosition{"B2"}, GridPosition{"B4"}});
	testGrid.placeShip(Ship{GridPosition{"D4"}, GridPosition{"G4"}});
	testGrid.placeShip(Ship{GridPosition{"F6"}, GridPosition{"F9"}});

	shipsOnBoard= testGrid.getShips();
	cout <<"OnGrid"<<endl;
	for(vector<Ship>::iterator it = shipsOnBoard.begin(); it != shipsOnBoard.end(); ++it)
	{
	    cout <<it->getBow().getRow()<<it->getBow().getColumn()<<"  ";
	    cout <<it->getStern().getRow()<<it->getStern().getColumn()<<endl;
	}

	cout <<"OnBoard"<<endl;
	Board testBoard(10,10);

	testBoard.getOwnGrid().placeShip(Ship{GridPosition{"B2"}, GridPosition{"B4"}});
	testBoard.getOwnGrid().placeShip(Ship{GridPosition{"D4"}, GridPosition{"G4"}});
	testBoard.getOwnGrid().placeShip(Ship{GridPosition{"F6"}, GridPosition{"F9"}});

	testShipsOnBoard = testBoard.getOwnGrid().getShips();
	for(vector<Ship>::iterator it = testShipsOnBoard.begin(); it != testShipsOnBoard.end(); ++it)
	{
	    cout <<it->getBow().getRow()<<it->getBow().getColumn()<<"  ";
	    cout <<it->getStern().getRow()<<it->getStern().getColumn()<<endl;
	}

	cout <<"Check via Console view";
	Board testBoard1(10,10);
	testBoard1.setShipOnBoard(Ship{GridPosition{"B2"}, GridPosition{"B4"}});
	testBoard1.setShipOnBoard(Ship{GridPosition{"D4"}, GridPosition{"G4"}});
	testBoard1.setShipOnBoard(Ship{GridPosition{"F6"}, GridPosition{"F9"}});
	ConsoleView testConsoleView(&testBoard1);
	testConsoleView.print();
}

