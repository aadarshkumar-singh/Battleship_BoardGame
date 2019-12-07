/***************************************************************************
****************************************************************************
 * \file part1tests.h
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 30.11.2019
 *
 * \brief part1tests.h
 *
 *  Contains test cases for Grid position and ships
 *
****************************************************************************/

#ifndef PART1TESTS_H_
#define PART1TESTS_H_
#include <string>
#include <iostream>

using namespace std;

/**
 * \brief Outputs the failedMessage on the console if condition is false.
 *
 * @param condition : the condition that has to be checked
 * @param failedMessage : error message
 */
void assertTrue(bool condition, string failedMessage);

/**
 * \brief test cases for ships and GridPosition
 */
void part1tests ();



#endif /* PART1TESTS_H_ */
