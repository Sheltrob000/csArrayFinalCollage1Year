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

            cout << maxcol << " " << maxrow << " " << counter++ << endl;
        }
    }else {
        cout << "file failed to open" << endl;
        return 0;
    }

        //create a 2d vector to put in the characters
        vector<vector<string>> characterMap;
        characterMap.resize(maxrow, vector<string>(maxcol, " "));



    return 0;
}
