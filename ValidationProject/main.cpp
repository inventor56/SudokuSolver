#include <iostream>
#include <fstream>
#include "GridCheck.h"

using namespace std;

int main(int argc, char** argv) {

    GridCheck gridCheckObj; //Object you will create later once values are known.
    //Create 2D array to store original grid in
    auto ** readInGrid = new int*[9];
    for (int i = 0; i < 9; i++) {
        readInGrid[i] = new int[9];
    }

    string fileName;
    //Get the user's file name
    cout << "Hello and welcome to the Sudoku Solver Application. Please enter in the filename of the 9x9 grid you would like to check" << endl;
    cin >> fileName;
    //Read in file
    ifstream myFile (fileName);
    if (myFile.is_open()) {
        //Set up array during file reading (9x9 2d array)
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                string tempString;
                getline(myFile, tempString, ','); // Use , as a delimiter
                readInGrid[i][j] = stoi(tempString); // Store value in array (use C++ 11's stoi to convert string type to int type)
            }
        }

        myFile.close();
    }
    else {
        // Error in file read, close
        cout << "Could not read file " << endl;
        return 0;
    }
    // Pass pointer into GridCheck (use Correct constructor)
    gridCheckObj = GridCheck(readInGrid, 1,1); // Create initial grid testing object (BE SURE TO CHANGE THE row and column FOR FULL THREADING)

    if (gridCheckObj.checkGrid()) {
        cout << "Errors found!" <<endl;
        list<ErrorObject> printList = gridCheckObj.getAnswers();
        for (auto &it : printList) {
            cout << "Error found at: Row: " << it.getRow() << ". Column: " << it.getColumn() << ". The right answer is:  "<< it.getAnswer() << endl;
        }
    }
    else {
        cout << "Well, looks like it you passed and there are no errors!" << endl;
    }

    return 0;
}