/*
* file: proj3-BUAthlete.cpp
* author: Peter Tran
* course: CSI 1440
* assignment: project 3
* due date: 02/25/2018
*
* date modified: 02/25/2018
*/

#ifndef PROJECT_3_PROJ3_BUATHLETELIST_H
#define PROJECT_3_PROJ3_BUATHLETELIST_H

#include "proj3-BUAthlete.hpp"

class BUAthleteList
{
private:
    BUAthlete* list;
    int capacity;
    int size;
    void resizeArray();

public:

    /**
 * BUAthleteList()
 *
 * This is the copy constructor which allocates capacity memory
 *
 * Parameters:
 * none
 *
 * Output:
 * return: none
 * reference parameters: none
 * stream: none
 */
    BUAthleteList();

    /**
 * ~BUAthleteList()
 *
 * This is the destructor which deallocates list
 *
 * Parameters:
 * none
 *
 * Output:
 * return: none
 * reference parameters: none
 * stream: none
 */
    ~BUAthleteList();

    /**
 * operator[]
 *
 * This function overloads the [] operator
 *
 * Parameters:
 * int that represents the index
 *
 * Output:
 * return: BUAthlete
 * reference parameters: Yes
 * stream: none
 */
    BUAthlete& operator[](int ndx);

    /**
 * addNCAAAthlete
 *
 * This function sets the the ID, name, LOI, and school of the athlete
 *
 * Parameters:
 * int, string, string, string
 *
 * Output:
 * return: void
 * reference parameters: none
 * stream: none
 */
    void addNCAAAthlete(int ID, string name, string LOI, string school);

    /**
 * setBUInfo
 *
 * This function sets the evaluation and position of the athlete
 *
 * Parameters:
 * int that represents the eval score, position object, and index
 *
 * Output:
 * return: void
 * reference parameters: none
 * stream: none
 */
    void setBUInfo(int index, Position pos, int eval);

    /**
 * findBYId
 *
 * This function searches for the ID of an athlete
 *
 * Parameters:
 * int that represents the ID
 *
 * Output:
 * return: int
 * reference parameters: none
 * stream: none
 */
    int findBYId(int id);

    /**
 * sortByID
 *
 * This function bubble sorts ID from low to high
 *
 * Parameters:
 * none
 *
 * Output:
 * return: void
 * reference parameters: none
 * stream: none
 */
    void sortByID();

    /**
 * sortByPosition
 *
 * This function sorts by Position
 *
 * Parameters:
 * none
 *
 * Output:
 * return: void
 * reference parameters: none
 * stream: none
 */
    void sortByPosition();

    /**
 * sortBYEvaluation
 *
 * This function sorts by Evaluation
 *
 * Parameters:
 * none
 *
 * Output:
 * return: void
 * reference parameters: none
 * stream: none
 */
    void sortBYEvaluation();

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

#endif //PROJECT_3_PROJ3_BUATHLETELIST_H
