/*
 * part3tests.cpp
 *
 *  Created on: Dec 7, 2019
 *      Author: Aadarshxp
 */

#include "Board.h"
#include "part3tests.h"
#include "ConsoleView.h"
/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
/*
void assertTruePart3Test(bool condition, string failedMessage) {
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
void part3tests ()
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
	cout<<"Opponent Grid"<<endl;

	OpponentGrid testGrid1(10,10);

	testGrid1.shotResult(Shot{GridPosition{"B2"}}, HIT );
	testGrid1.shotResult(Shot{GridPosition{"B4"}}, HIT );
	testGrid1.shotResult(Shot{GridPosition{"B3"}}, SUNKEN);

	vector<Ship> test =testGrid1.getShunkenShipsOfOpponent();

	for(vector<Ship>::const_iterator it = test.begin(); it != test.end();++it)
	{
		cout <<it->getBow().getRow()<<it->getBow().getColumn()<<"  ";
		cout <<it->getStern().getRow()<<it->getStern().getColumn()<<endl;
	}

	cout <<"Length of sunkenship"<<testGrid1.getShunkenShipsOfOpponent().size()<<endl;

}

