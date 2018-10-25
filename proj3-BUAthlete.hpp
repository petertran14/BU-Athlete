/*
* file: proj3-BUAthlete.cpp
* author: Peter Tran
* course: CSI 1440
* assignment: project 3
* due date: 02/25/2018
*
* date modified: 02/25/2018
*/

#ifndef PROJECT_3_PROJ3_BUATHLETE_H
#define PROJECT_3_PROJ3_BUATHLETE_H

#include "NCAAAthlete.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>

using namespace std;

enum Position {OL, QB, RB, WR, TE, DL, DE, LB, CB, S, K};

class BUAthlete : public NCAAAthlete
{
private:
    int evaluation;
    Position bestfit;

public:
    /**
 * setEvaluation
 *
 * This function sets the evaluation of the athlete
 *
 * Parameters:
 * int that represents the eval score
 *
 * Output:
 * return: void
 * reference parameters: none
 * stream: none
 */
    void setEvaluation(int);

    /**
  * setPosition
  *
  * This function sets the position of the athlete
  *
  * Parameters:
  * Position obj that represents the position
  *
  * Output:
  * return: void
  * reference parameters: none
  * stream: none
  */
    void setPosition(Position);

    /**
 * getEvaluation
 *
 * This function gets the evaluation of the athlete
 *
 * Parameters:
 * none
 *
 * Output:
 * return: int
 * reference parameters: none
 * stream: none
 */
    int getEvaluation();

/**
 * getPosition
 *
 * This function gets the position of the athlete
 *
 * Parameters:
 * none
 *
 * Output:
 * return: Position
 * reference parameters: none
 * stream: none
 */
    Position getPosition();

    /**
 * toString
 *
 * This function converts an int to a string
 *
 * Parameters:
 * none
 *
 * Output:
 * return: string
 * reference parameters: none
 * stream: none
 */
    string toString();
};

#endif //PROJECT_3_PROJ3_BUATHLETE_H
