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
#include "NCAAAthlete.hpp"
#include "proj3-BUAthleteList.hpp"

int main()
{
    Position bestfit;
    BUAthleteList bList;
    BUAthlete b;

    bList.addNCAAAthlete(2345, "Jaylen Ellis", "yes", "Baylor");
    bList.addNCAAAthlete(2343, "Dominick Blaylock", "yes", "Baylor");
    bList.addNCAAAthlete(2344, "Trejan Bridges", "yes", "Baylor");

    bList.sortByID();

    cout << bList[0].getID() << endl;
    cout << bList[1].getID() << endl;
    cout << bList[2].getID() << endl;

    fstream input("proj3-BUAthlete.csv", ios::in | ios::binary);

    if (!input) {

        cout << "Error. File Not Open" << endl;
    }

    input.close();

    bestfit = QB;

    bList.setBUInfo(0, bestfit, 7);
    bList.setBUInfo(2, bestfit, 9);
    bList.setBUInfo(1, bestfit, 7);

    cout << bList[0].getPosition() << endl;
    cout << bList[0].getEvaluation() << endl;
    cout << bList[1].getPosition() << endl;
    cout << bList[1].getEvaluation() << endl;
    cout << bList[2].getPosition() << endl;
    cout << bList[2].getEvaluation() << endl;

    bList.sortByPosition();
    bList.sortBYEvaluation();

    cout << bList[0].getPosition() << endl;
    cout << bList[0].getEvaluation() << endl;
    cout << bList[1].getPosition() << endl;
    cout << bList[1].getEvaluation() << endl;
    cout << bList[2].getPosition() << endl;
    cout << bList[2].getEvaluation() << endl;

    fstream file("proj3-NCAAAthlete.csv", ios::in | ios::binary);

    if (!file) {

        cout << "Error. File Not Open" << endl;
    }

    file.close();

    return 0;
}
