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
#include "proj3-BUAthleteList.hpp"

//this class is able to use the functions in the BUAthlete class
void BUAthleteList::resizeArray() {

    if (this->size == this->capacity) {

        //increase capacity by 2 more BUAthlete spaces
        this->capacity += 2;

        //create a temp pointer to hold the new capacity
        BUAthlete *temp = new BUAthlete[this->capacity];

        //copy over the original data into the larger pointer
        for (int i = 0; i < this->size; i++) {

            *(temp + i) = this->list[i];
        }

        //delete the address of the original
        delete [] this->list;

        //instead make the original point to the new pointer
        this->list = temp;
    }
}

void BUAthleteList::addNCAAAthlete(int ID, string name, string LOI, string school) {
//cout << this->size << " ";
    //first time around, we need to allocate memory for list
    //remember, pointers do not come with memory unlike arrays
/*
    if (size == 0) {

        this->capacity = 2;
        this->list = new BUAthlete[this->capacity];
    }
*/
    //cout << ID << " " << name << " " << LOI << " " << school << endl;
    //cout << this->size << endl;

    //if our array is at max capacity, then we need to increase its size
    if (this->size == this->capacity) {
//cout << "here" << " ";
        this->resizeArray();
    }

    //list is an pointer to an object of BUAthletes
    //list is initially unfilled with athletes, but as we add athletes
    //we need to add them at size element
    this->list[this->size].setID(ID);
    this->list[this->size].setName(name);
    this->list[this->size].setLOI(LOI);
    this->list[this->size].setSchool(school);
    //cout << this->list[this->size].getSchool();

    //increment size, so we can add the next athlete to the next element
    //and not overwrite our current data
    this->size++;
}

void BUAthleteList::setBUInfo(int index, Position pos, int eval) {

    //set position and evaluation
    this->list[index].setPosition(pos);
    this->list[index].setEvaluation(eval);
}

int BUAthleteList::findBYId(int id) {

    int first = 0;
    int last = this->size - 1;
    int middle;
    int position = -1;
    bool found = false;

    while (first <= last && !found) {

        middle = (first + last) / 2;

        if (this->list[middle].getID() == id) {

            position = middle;
            found = true;
        }

        else if (this->list[middle].getID() > id) {

            last = middle - 1;
        }

        else {

            first = middle + 1;
        }
    }

    return position;
}
//this works phew
void BUAthleteList::sortByID() {
    //cout << this->list[0].getID() << " ";
    for (int pass = 0; pass < this->size - 1; pass++) {

        for (int scan = 0; scan < this->size - 1 - pass; scan++) {

            if (this->list[scan].getID() > this->list[scan + 1].getID()) {

                swap(this->list[scan], this->list[scan + 1]);
            }
        }
    }

    //cout << this->list[0].getID();
}

void BUAthleteList::sortByPosition() {

    for (int pass = 0; pass < this->size - 1; pass++) {

        for (int scan = 0; scan < this->size - 1 - pass; scan++) {

            if (this->list[scan].getPosition() > this->list[scan + 1].getPosition()) {

                swap(this->list[scan], this->list[scan + 1]);
            }
        }
    }
}

void BUAthleteList::sortBYEvaluation() {

    for (int pass = 0; pass < this->size - 1; pass++) {

        for (int scan = 0; scan < this->size - 1 - pass; scan++) {

            if (this->list[scan].getEvaluation() < this->list[scan + 1].getEvaluation()) {

                swap(this->list[scan], this->list[scan + 1]);
            }
        }
    }
}

string BUAthleteList::toString() {

    ostringstream out;

    //current ID for the array of lists
    out << this->list[this->size].getID() << " ";

    out << endl;

    return out.str();
}

BUAthlete& BUAthleteList::operator[](int ndx) {

    return this->list[ndx];
}

BUAthleteList::BUAthleteList() {

    this->size = 0;

    this->capacity = 2;

    this->list = new BUAthlete[this->capacity];
}


BUAthleteList::~BUAthleteList() {

    if (list != nullptr) {

        //delete [] list;
        list = nullptr;
    }
}