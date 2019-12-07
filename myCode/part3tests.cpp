/*
 * part3tests.cpp
 *
 *  Created on: Dec 7, 2019
 *      Author: Aadarshxp
 */

#include "Board.h"
#include "part3tests.h"

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTruePart3Test(bool condition, string failedMessage) {
    static int i =0;
	if (!condition) {
        cout << failedMessage << endl;
    }
    else
    {
    	cout <<"Part 3::>Test case ::> No "<<++i<<" Working"<<endl;
    }
}


/**
 */
void part3tests ()
{
	OwnGrid testOwnGrid(2,5);
	vector<Ship> shipsOnOwnBoard;

	testOwnGrid.placeShip(Ship{GridPosition{"B2"}, GridPosition{"B4"}});
	testOwnGrid.placeShip(Ship{GridPosition{"D4"}, GridPosition{"G4"}});
	testOwnGrid.placeShip(Ship{GridPosition{"F6"}, GridPosition{"F9"}});
	shipsOnOwnBoard= testOwnGrid.getShips();

	// Checking Shots by Opponent in Own Grid NONE, HIT, SUNKEN
	assertTruePart3Test((testOwnGrid.takeBlow(Shot{GridPosition{"B5"}}) == NONE),"IMPACT not identified Correctly");
	assertTruePart3Test((testOwnGrid.takeBlow(Shot{GridPosition{"B2"}}) == HIT),"IMPACT not identified Correctly");
	assertTruePart3Test((testOwnGrid.takeBlow(Shot{GridPosition{"B4"}}) == HIT),"IMPACT not identified Correctly");
	assertTruePart3Test((testOwnGrid.takeBlow(Shot{GridPosition{"B3"}}) == SUNKEN),"IMPACT not identified Correctly");

	//Trying sunken Hits with different ship size
	assertTruePart3Test((testOwnGrid.takeBlow(Shot{GridPosition{"F5"}}) == NONE),"IMPACT not identified Correctly");
	assertTruePart3Test((testOwnGrid.takeBlow(Shot{GridPosition{"F6"}}) == HIT),"IMPACT not identified Correctly");
	assertTruePart3Test((testOwnGrid.takeBlow(Shot{GridPosition{"F7"}}) == HIT),"IMPACT not identified Correctly");
	assertTruePart3Test((testOwnGrid.takeBlow(Shot{GridPosition{"F8"}}) == HIT),"IMPACT not identified Correctly");
	assertTruePart3Test((testOwnGrid.takeBlow(Shot{GridPosition{"F9"}}) == SUNKEN),"IMPACT not identified Correctly");

	//Testing Opponent Grid
	OpponentGrid testOpponentGrid(10,10);
	map<GridPosition, Impact_t> testShotsAndImpact ;
	testShotsAndImpact.insert({GridPosition{"B2"},HIT });
	testShotsAndImpact.insert({GridPosition{"B4"}, HIT});
	testShotsAndImpact.insert({GridPosition{"B3"}, SUNKEN });
	testShotsAndImpact.insert({GridPosition{"F6"}, HIT });
	testShotsAndImpact.insert({GridPosition{"F7"}, HIT });
	testShotsAndImpact.insert({GridPosition{"F8"}, HIT });
	testShotsAndImpact.insert({GridPosition{"F9"}, SUNKEN });

	testOpponentGrid.shotResult(Shot{GridPosition{"B2"}}, HIT );
	testOpponentGrid.shotResult(Shot{GridPosition{"B4"}}, HIT );
	testOpponentGrid.shotResult(Shot{GridPosition{"B3"}}, SUNKEN);
	testOpponentGrid.shotResult(Shot{GridPosition{"F6"}}, HIT);
	testOpponentGrid.shotResult(Shot{GridPosition{"F7"}}, HIT);
	testOpponentGrid.shotResult(Shot{GridPosition{"F8"}}, HIT);
	testOpponentGrid.shotResult(Shot{GridPosition{"F9"}}, SUNKEN);

	// testing Sunken Ships of Opponent Grid
	vector<Ship> sunkenShips =testOpponentGrid.getShunkenShipsOfOpponent();
	set<GridPosition> sunkenShipsbowsSternSet;
	for(auto testIteratorShips : sunkenShips)
	{
		sunkenShipsbowsSternSet.insert(testIteratorShips.getBow());
		sunkenShipsbowsSternSet.insert(testIteratorShips.getStern());

	}
	assertTruePart3Test(sunkenShipsbowsSternSet == set<GridPosition>{GridPosition{"B2"},GridPosition{"B4"},GridPosition{"F6"},GridPosition{"F9"}},"Sunken ship not correct");

	// testing Map of Opponent Grid
	map<GridPosition, Impact_t> testOpponentGridMap = testOpponentGrid.getShotsAt();
	assertTruePart3Test(testOpponentGridMap == testShotsAndImpact,"Player Moves in his opponent Grid InCorrect");

}

