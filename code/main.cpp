#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    ifstream dataFile("../data/data");
    istringstream dataLine;
    string stringLineData;
    int numrow;
    int numcol;
    int maxrow = 0;
    int maxcol = 0;

    cout << "starting" << endl;

    if (dataFile.is_open()) {
        while (!dataFile.eof()) {
            getline(dataFile, stringLineData);
            dataLine.str(stringLineData);
            dataLine >> numcol >>numrow;

            if (numcol > maxcol) {
                maxcol = numcol;
            }
            if (numrow > maxrow) {
                maxrow = numrow;
            }
            cout << maxcol << " " << maxrow << endl;
        }
        cout << numcol << endl << numrow;
    }else {
        cout << "file failed to open" << endl;
        return 0;
    }




    return 0;
}
