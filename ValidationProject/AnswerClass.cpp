//
// Created by joshsmith on 10/6/17.
//

#include "AnswerClass.h"
#include <algorithm>

using namespace std;

list<ErrorObject> AnswerClass::findAnswer(int **arr, list<ErrorObject> errorList) {
    // Find the answers.
    // Check each object against the others.
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
        if (!avoidRow) {
            objectToLookAt.setAnswer(checkRowOrColumn(0, arr, objectToLookAt));
        }
        if (!avoidColumn) { // This may be double checking :-/
            objectToLookAt.setAnswer(checkRowOrColumn(1, arr, objectToLookAt));
        }
        if (avoidColumn || avoidRow) {
            // Set answer to impossible to difficult to solve in current grid state
            objectToLookAt.setAnswer(-1); // Make sure -1 will work
        }





    }





    return std::list<ErrorObject>();
}

int AnswerClass::checkRowOrColumn(int version, int** array, ErrorObject errorObj) {

    vector<int> areaVector; // Set this to be either the row or column vector

    for (int i = 0; i < 9; i++) {
        if(version == 0) {
            areaVector[i] = array[errorObj.getRow()][i]; // Same row, but the column is different (so we check horizontally)
        }
        else if (version == 1) {
            areaVector[i] = array[i][errorObj.getColumn()];// Same column, but the row is different (so we check horizontally)
        }
    }
    // Go through vector and remove the error, previous checks will show that there are 9 numbers, with only 1 error
    for (auto it = areaVector.begin(); it != areaVector.end(); ++it) {
        if (*it == array[errorObj.getRow()][errorObj.getColumn()]) {
            //Erase the wrong number from this temp checking vector
            areaVector.erase(it);
            break;
        }
    }

    // Now sort and solve for the correct answer
    sort(areaVector.begin(),areaVector.end());
    for (int i = 1; i <= areaVector.size(); i++){
        if (areaVector.at(static_cast<unsigned long>(i)-1) != i) {
            // This is the correct answer, because we could not find it in the sorted list, it's the missing link
            return i;
        }
    }
    // Return true since the check has passed! It looks like the elements of the vector are definitely between 1-9
    //return true
}

