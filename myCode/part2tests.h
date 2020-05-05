/***************************************************************************
****************************************************************************
 * \file part2tests.h
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 30.11.2019
 *
 * \brief part2tests.h
 *
 *  Contains test cases for arrangement Rules on own grid
 *
****************************************************************************/

#ifndef PART2TESTS_H_
#define PART2TESTS_H_
#include <string>
#include <iostream>
#include <vector>
using namespace std;

/**
 * \brief Outputs the failedMessage on the console if condition is false.
 *
 * @param condition : the condition that has to be checked
 * @param failedMessage : error message
 */
void assertTruePart2Test(bool condition, string failedMessage);

/**
 * test cases for arrangement Rules on own grid
 */
void part2tests ();



#endif /* PART2TESTS_H_ */
