/***************************************************************************
****************************************************************************
 * \file part3tests.h
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 30.11.2019
 *
 * \brief part3tests.h
 *
 *  Contains test cases for shots
 *
****************************************************************************/

#ifndef PART3TESTS_H_
#define PART3TESTS_H_

#include <string>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

/**
 * \brief Outputs the failedMessage on the console if condition is false.
 *
 * @param condition : the condition that has to be checked
 * @param failedMessage : error message
 */
void assertTruePart3Test(bool condition, string failedMessage);

/**
 * \brief test cases for shots section
 */
void part3tests ();




#endif /* PART3TESTS_H_ */
