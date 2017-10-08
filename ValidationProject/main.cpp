#include <iostream>
#include <fstream>
#include "GridCheck.h"
#include "AnswerClass.h"

using namespace std;

#define NUM_THREADS 9 // You will be running 9 threads within this program. One thread per each 3x3 grid section (9 total)

// Set up struct that will be stored in a array (size 9)
// Struct: Middle values on the graph (row/column)
struct middleValues {
    int ** arr;
    int row;
    int column;
};

// List of all the errors you collect through your threading
list<ErrorObject> totalErrors;

// Threading function that will run 9 times
void *check_grid_3x3(void * param) {
    // Make new Grid Check Object
    struct middleValues *passedInStruct;
    passedInStruct = (middleValues*) param;
    GridCheck gridCheckObj = GridCheck(passedInStruct->arr, passedInStruct->row,passedInStruct->column);
    // Check Grid
    if(gridCheckObj.checkGrid()) {
        //insert at end of main list
        totalErrors.splice(totalErrors.end(),gridCheckObj.getAnswers());
    }

    // Exit!
    pthread_exit(nullptr);


}


int main(int argc, char** argv) {
    cout << "-- Thread 1 Created (i.e. main method)" << endl;
    // Set up threads
    pthread_t threads[NUM_THREADS]; // The 9 threads

    //Create 2D array to store original grid in
    auto ** readInGrid = new int*[9];
    for (int i = 0; i < 9; i++) {
        readInGrid[i] = new int[9];
    }

    cout << "-- Empty 9x9 grid created" << endl;


    middleValues midVals[9]; // Array of nine middle values. Set the 9x9 grid pointer below
    //Set the array pointer into your struct (to pass into each thread)
    for (auto &midVal : midVals) {
        midVal.arr = readInGrid;
    }

    // Set the row/column values
    midVals[0].row = midVals[0].column = midVals[1].row = midVals[2].row = midVals[3].column = midVals[6].column = 1;
    midVals[1].column = midVals[3].row = midVals[4].row = midVals[4].column = midVals[5].row = midVals[7].column = 4;
    midVals[2].column = midVals[5].column = midVals[6].row = midVals[7].row = midVals[8].row = midVals[8].column = 7;

    cout << "-- Center of each 3x3 grid (of 9) initialized" << endl;


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //                                      Read in Grid

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
        cout << "-- File successfully read in by the program" << endl;

        myFile.close();
    }
    else {
        // Error in file read, close
        cout << "Could not read file " << endl;
        return 0;
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //                                      Main functionality below

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    int tid;

    for (int i = 0; i < NUM_THREADS; i++) {
        tid = pthread_create(&threads[i], nullptr, check_grid_3x3, (void *) &midVals[i]);
        cout <<  "-- Thread " << i+2 << " Created" << endl;

        // Check for threading errors
        if (tid) {
            cout << "Error: Problem creating thread," << tid << endl;
            exit(-1);
        }
    }

    // Join all threads: Making sure that all have completed before continuing onwards

    for (unsigned long thread : threads) {
        pthread_join(thread, nullptr); // Join threads
    }
    // All threads are complete
    cout << "\nAll threads have completed execution and have joined with the main thread" << endl;

    if (!totalErrors.empty()) {
        // Run the static class to find the correct answers
        cout << "\nNow we will run a method to check each error section (row/column) and determine the correct answer" << endl;
        totalErrors = AnswerClass::findAnswer(readInGrid, totalErrors); // Change your total error list to have the correct answers
        cout << "\nHere are the final results:" << endl;
        // Iterate through the new list and
        for (auto &it : totalErrors) {
            cout << "Error found at: Row: " << it.getRowOneBase() << ". Column: " << it.getColumnOneBase() << ". The right answer is: "<< it.getAnswer() << endl;
        }
    }
    else {
        cout << "Well, the Sudoku puzzle has passed and there are no errors!" << endl;
    }

    return 0;
}