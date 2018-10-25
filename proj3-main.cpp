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

/*
 * Going to need a binary search function and a string to int function using sstream
 */

const int SIZE = 4;
const int ROLE = 11;

/**
 * displayTopTwo
 *
 * This function displays the top two athletes for each class
 *
 * Parameters:
 * BUAthlete list by REFERENCE!, ostream&, int, Position
 *
 * Output:
 * return: void
 * reference parameters: reference with BUAthlete and ostream
 * stream: none
 */

void displayTopTwo(BUAthleteList&, ostream&, int, Position);

int main() {

    //Create an object of the class
    //Since we are allowed only to create an object of this class
    //We must used the fact that this class is connected to the
    //two other classes
    BUAthleteList bList;
    int count = 0;
    int index = 0;
    string list[SIZE];
    int ID;
    int mastercount = 0;

    //open the , remember to add proj3 for all file
    fstream input("proj3-NCAAAthlete.csv", ios::in | ios::binary);

    //input validation
    if (input.fail()) {

        cout << "Error. File Not Found." << endl;
    }
    string id;
    string school;
    //store everything into an array of BUAthletes
    while (input) {



        //get the line, but stop at a comma
        if (count == 0 || count == 1 || count == 2) {

            getline(input, list[count], ',');
        }

        //last item of the row has a newline instead of a comma
        else {

            getline(input, list[count]);
        }

        //if we come to a position holding an ID, we need to change its current data type to an int
        if (count % 4 == 0) {

            //create a stringstream object
            stringstream ss(list[count]);

            //blow ID into the object for conversion to int
            ss >> ID;
        }

        //keep track of what item we are reading
        count++;

        //we have read the while line of items
        if (count == 4) {

            //send them off to the appropriate function
            bList.addNCAAAthlete(ID ,list[count - 3], list[count - 2], list[count - 1]);
            mastercount++;

            //reset count to 0
            count = 0;
        }
    }

    //close file
    input.close();

    //sort by ID
    bList.sortByID();

    //open the file for reading
    fstream file("proj3-BUAthlete.csv", ios::in | ios::binary);
    string rhule[3];
    Position b;
    int searchID;
    int returnID;
    int eval;

    while (file) {

        //we are reading ID
        if (index == 0) {

            getline(file, rhule[index], ',');

            //convert to an int
            stringstream s(rhule[index]);

            s >> searchID;
        }

        //we are reading enum data type
        else if (index == 1) {

            getline(file, rhule[index], ',');

            //set the enum data type
            if (rhule[index] == "OL") {

                b = OL;
            }

            else if (rhule[index] == "QB") {

                b = QB;
            }

            else if (rhule[index] == "RB") {

                b = RB;
            }

            else if (rhule[index] == "WR") {

                b = WR;
            }

            else if (rhule[index] == "TE") {

                b = TE;
            }

            else if (rhule[index] == "DL") {

                b = DL;
            }

            else if (rhule[index] == "DE") {

                b = DE;
            }

            else if (rhule[index] == "LB") {

                b = LB;
            }

            else if (rhule[index] == "CB") {

                b = CB;
            }

            else if (rhule[index] == "S") {

                b = S;
            }

            else if (rhule[index] == "K") {

                b = K;
            }
        }

        //we are reading eval
        else if (index == 2) {

            getline(file, rhule[index]);

            //convert to an int
            stringstream strm(rhule[index]);

            strm >> eval;
        }

        //increment index
        index++;

        //we have read one row
        if (index == 3) {

            //reset index
            index = 0;

            //binary search for ID in data stored in list from BUAthleteList class
            returnID = bList.findBYId(searchID);

            //if we found it
            if (returnID != -1) {

                //send the info just read
                bList.setBUInfo(returnID, b, eval);
            }
        }
    }

    //close file
    file.close();

    //first is last
    bList.sortBYEvaluation();
    bList.sortByPosition();

    for (int pos = 0; pos < ROLE; pos++) {

        switch (pos)
        {
            case 0: b = OL;
                break;
            case 1: b = QB;
                break;
            case 2: b = RB;
                break;
            case 3: b = WR;
                break;
            case 4: b = TE;
                break;
            case 5: b = DL;
                break;
            case 6: b = DE;
                break;
            case 7: b = LB;
                break;
            case 8: b = CB;
                break;
            case 9: b = S;
                break;
            case 10: b = K;
                break;
        }

        displayTopTwo(bList, cout, mastercount, b);
        //cout << mastercount << " ";
    }

    //test delete later, I need to actually cout a get function for it to print
    //cout << bList[0].getID();

    return 0;
}

void displayTopTwo(BUAthleteList& obj, ostream& out, int n, Position role) {

    //Buffer of Top Two athletes for every  role
    //BUAthlete TopTwoRole[22];
    int count = 0;
    string loi;
    string position;

    for (int i = 0; i < n; i++) {

        if (obj[i].getSchool() == "Baylor" && obj[i].getPosition() == role && count < 2) {

            if (count == 0) {

                if (obj[i].getPosition() == 0) {

                    position = "OL";
                }

                else if (obj[i].getPosition() == 1) {

                    position = "QB";
                }

                else if (obj[i].getPosition() == 2) {

                    position = "RB";
                }

                else if (obj[i].getPosition() == 3) {

                    position = "WR";
                }

                else if (obj[i].getPosition() == 4) {

                    position = "TE";
                }

                else if (obj[i].getPosition() == 5) {

                    position = "DL";
                }

                else if (obj[i].getPosition() == 6) {

                    position = "DE";
                }

                else if (obj[i].getPosition() == 7) {

                    position = "LB";
                }

                else if (obj[i].getPosition() == 8) {

                    position = "CB";
                }

                else if (obj[i].getPosition() == 9) {

                    position = "S";
                }

                else if (obj[i].getPosition() == 10) {

                    position = "K";
                }


                out << "Top 2 Athlete(s) in Position: " << position << endl;
            }

            out << "ID: " << obj[i].getID() << endl;
            out << "Name: " << obj[i].getName() << endl;

            if (obj[i].getLOI() == false) {

                out << "School: " << "available" << endl;
            }

            else {

                out << "School: " << obj[i].getSchool() << endl;
            }

            out << "Evaluation: " << obj[i].getEvaluation() << endl;
            out << "Position: " << position << endl;
            cout << endl;

            count++;
        }
    }
}
