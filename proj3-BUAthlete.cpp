/*
* file: proj3-BUAthlete.cpp
* author: Peter Tran
* course: CSI 1440
* assignment: project 3
* due date: 02/25/2018
*
* date modified: 02/25/2018
*/

#include "proj3-BUAthlete.hpp"

void BUAthlete::setEvaluation(int eval) {

    this->evaluation = eval;
    //cout << "Eval: " << eval << endl;
}

void BUAthlete::setPosition(Position pos) {

    this->bestfit = pos;
    //cout << "Pos: " << pos << endl;
}

int BUAthlete::getEvaluation() {

    return this->evaluation;
}

Position BUAthlete::getPosition() {

    return this->bestfit;
}

//convert athlete ID to a string?
string BUAthlete::toString() {

    ostringstream out;

    out << this->athleteID;

    return out.str();
}


