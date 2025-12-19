#include <algorithm>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ifstream dataFile("../data/data");
    istringstream dataLine;
    string stringLineData;
    int numrow;
    int numcol;
    string currentChar;
    int maxrow = 0;
    int maxcol = 0;

    cout << "starting" << endl;

    int counter = 0;
        //finds the amount of rows and colums
    if (dataFile.is_open()) {
        while (!dataFile.eof()) {
            dataFile >> numcol;
            dataFile >> currentChar;
            dataFile >> numrow;

            if (numcol > maxcol) {
                maxcol = numcol;
            }
            if (numrow > maxrow) {
                maxrow = numrow;
            }

            // cout << maxcol << " " << maxrow << " " << counter++ << endl;
        }
    }else {
        cout << "file failed to open" << endl;
        return 0;
    }

        //create a 2d vector to put in the characters
    string** characterArray = new string*[maxrow + 1];
    for (int i = 0; i < maxrow + 1; ++i) {
        characterArray[i] = new string[maxcol + 1];
    }

        //fill aray with spaces

        for(int i = 0; i < maxrow + 1; i++){
                   for (int j = 0; j < maxcol + 1; j++) {
                       characterArray[i][j] = " ";
                   }
               }



        //populate the vector with value from my data
        dataFile.clear();
        dataFile.seekg(0, ios::beg);

        while (!dataFile.eof()) {
            dataFile >> numcol;
            dataFile >> currentChar;
            dataFile >> numrow;

            characterArray[numrow][numcol] = currentChar;

        }

            //print array
        for(int i = 0; i < maxrow + 1; i++){
            for (int j = 0; j < maxcol + 1; j++) {
                cout << characterArray[i][j];
            }
            cout << endl;
        }


            //delete memory for dynamically created arrays

        for (int i = 0; i < maxrow + 1; ++i) {
            delete[] characterArray[i];
        }
        delete[] characterArray;

    return 0;
}
