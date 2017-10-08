//
// Created by joshsmith on 10/6/17.
//

#include "AnswerClass.h"
#include <algorithm>
#include <iostream>

using namespace std;

list<ErrorObject> AnswerClass::findAnswer(int **arr, list<ErrorObject> errorList) {
    // Find the answers.
    // Check each object against the others.

    if (errorList.size() == 1) { // Only one object
        errorList.front().setAnswer(checkRowOrColumn(0, arr, errorList.front()));
        return errorList;

    }

    for (auto &objectToLookAt : errorList) {
        bool avoidRow = false;
        bool avoidColumn = false;

        // If the object shares the same row or column, take a note of that.

        for (auto &objectsToCheckAgainst : errorList) {
            if (&objectToLookAt !=
                &objectsToCheckAgainst) { // May be an issue here! You need to be sure you are comparing the objects correctly
                if (objectToLookAt.getRow() == objectsToCheckAgainst.getRow()) {
                    avoidRow = true;
                }
                if (objectToLookAt.getColumn() == objectsToCheckAgainst.getColumn()) {
                    avoidColumn = true;
                }
            }
        }


        // Then hop into whichever check doesn't share a spot with the others
        // Check is complete, see if you have the opportunity to check another row or column for the correct solution
        // Check either the row, column, or grid, depending on where the other objects lie, set the error object
        if (!avoidRow && avoidColumn) {
            objectToLookAt.setAnswer(checkRowOrColumn(0, arr, objectToLookAt));
        }
        else if (!avoidColumn && avoidRow) {
            objectToLookAt.setAnswer(checkRowOrColumn(1, arr, objectToLookAt));
        }
        else if (!avoidColumn && !avoidRow) {
            objectToLookAt.setAnswer(checkRowOrColumn(0, arr, objectToLookAt));
        }
        else {
            // Set answer to impossible to difficult to solve in current grid state
            objectToLookAt.setAnswer(-1); // Make sure -1 will work
        }





    }





    return std::list<ErrorObject>();
}

int AnswerClass::checkRowOrColumn(int version, int** array, ErrorObject errorObj) {

    vector<int> areaVector (9); // Set this to be either the row or column vector (set to size nine to avoid errors)
    for (int i = 0; i < 9; i++) {
        if(version == 0) {
            areaVector[i] = array[errorObj.getRow()][i]; // Same row, but the column is different (so we check horizontally)
        }
        else if (version == 1) {
            areaVector[i] = array[i][errorObj.getColumn()];// Same column, but the row is different (so we check horizontally)
        }
    }

    // Make a vector of the correct numbers
    vector<int> numbersToCheckAgainst (9);
    for (int a = 1; a <= numbersToCheckAgainst.size(); a++) {
        numbersToCheckAgainst.push_back(a);
    }

    // Go through vector and remove the error, previous checks will show that there are 9 numbers, with only 1 error

    bool isFound = false;
    for (auto it = areaVector.begin(); it != areaVector.end(); ++it) {

        if (*it == array[errorObj.getRow()][errorObj.getColumn()] && !isFound) {
            //Erase the wrong number from this temp checking vector
            //areaVector.erase(it);
            isFound = true;
        }
        else {
            numbersToCheckAgainst.erase(it);
        }
    }

    for (int &it : areaVector)
        cout << it << endl;

    return 1;
    /* no longer need to sort, replace with just a new vector to compare in the underneath loop
    // Now sort and solve for the correct answer
    sort(areaVector.begin(),areaVector.end());
    for (auto it = areaVector.begin(); it != areaVector.end(); ++it)
        cout << *it << endl;
    */
    /*
    // Make a vector of the correct numbers
    vector<int> numbersToCheckAgainst (9);
    for (int a = 1; a <= numbersToCheckAgainst.size(); a++) {
        numbersToCheckAgainst.push_back(a);
    }

    // possibly the main bug lies within this bottom function
    for (auto it : areaVector){
        if (*it ) {
            //cout << "Here is the answer in object" << errorObj.getAnswer() << endl;
            return i;
        }
    } */
    // Return true since the check has passed! It looks like the elements of the vector are definitely between 1-9
    //return true
}

