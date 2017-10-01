#include <iostream>
#include <fstream>
#include "GridCheck.h"

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
        totalErrors.splice(totalErrors.end(),gridCheckObj.getAnswers()); // Try this one out to see if works. If not, check bookmark
        //may need to manage access to list here (you don't know if another thread will be accessing it at the same time)
    }
    // maybe use a Mutex, make sure you can insert answers into your own answers list here
    // Exit!
    pthread_exit(nullptr);


}


int main(int argc, char** argv) {

    // Set up threads
    pthread_t threads[NUM_THREADS]; // The 9 threads

    //Create 2D array to store original grid in
    auto ** readInGrid = new int*[9];
    for (int i = 0; i < 9; i++) {
        readInGrid[i] = new int[9];
    }


    middleValues nineMiddleValues[9]; // Array of nine middle values. Set the 9x9 grid pointer below
    //Set the array pointer into your struct (to pass into each thread)
    for (int i = 0; i < 9; i++) {
        nineMiddleValues[i].arr = readInGrid;
    }
    // Set the row/column values (Need to find a better way to do this. This looks very messy
    nineMiddleValues[0].row = 1;
    nineMiddleValues[0].column = 1;
    nineMiddleValues[1].row = 1;
    nineMiddleValues[1].column = 4;
    nineMiddleValues[2].row = 1;
    nineMiddleValues[2].column = 7;
    nineMiddleValues[3].row = 4;
    nineMiddleValues[3].column = 1;
    nineMiddleValues[4].row = 4;
    nineMiddleValues[4].column = 4;
    nineMiddleValues[5].row = 4;
    nineMiddleValues[5].column = 7;
    nineMiddleValues[6].row = 7;
    nineMiddleValues[6].column = 1;
    nineMiddleValues[7].row = 7;
    nineMiddleValues[7].column = 4;
    nineMiddleValues[8].row = 7;
    nineMiddleValues[8].column = 7;


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
                readInGrid[i][j] = stoi(
                        tempString); // Store value in array (use C++ 11's stoi to convert string type to int type)
            }
        }

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
        tid = pthread_create(&threads[i], nullptr, check_grid_3x3, (void *) &nineMiddleValues[i]);

        if (tid) {
            cout << "Error: Problem creating thread," << tid << endl;
            exit(-1);
        }
    }

    // Join all threads: Making sure that all have completed before continuing onwards

    pthread_join(threads[0], nullptr);
    pthread_join(threads[1], nullptr);
    pthread_join(threads[2], nullptr);
    pthread_join(threads[3], nullptr);
    pthread_join(threads[4], nullptr);
    pthread_join(threads[5], nullptr);
    pthread_join(threads[6], nullptr);
    pthread_join(threads[7], nullptr);
    pthread_join(threads[8], nullptr);

    // All threads are complete

    if (!totalErrors.empty()) {
        for (auto &it : totalErrors) {
            cout << "Error found at: Row: " << it.getRow() << ". Column: " << it.getColumn() << ". The right answer is:  "<< it.getAnswer() << endl;
        }
    }
    else {
        cout << "Well, looks like it you passed and there are no errors!" << endl;
    }

    return 0;
}