//
// Created by joshsmith on 9/24/17.
//

#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include "GridCheck.h"

using namespace std;

GridCheck::GridCheck() = default;



GridCheck::~GridCheck() = default;

GridCheck::GridCheck(int** arr, int leftmost, int bottom) { // Something is wrong with the pointer going into here..
    originalArray = arr;
    leftmostRowOfGrid = leftmost-1;
    bottomColumnOfGrid = bottom-1;
}

bool GridCheck::checkGrid() {
    bool errorsFound = false; // This will be true in case there are any errors found (at all) during function runtime
    vector <int> numberVector(9); // Create a vector of size 9 to store the numbers in.
    gridArrayVector indexValues; // Pairs of index values. Very important
    //Should create a vector or the like to store the 9 array indices
    int tempIterate = 0; // Use an iterator instead, possibly?
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int tempLeft = leftmostRowOfGrid+i;
            int tempRight = bottomColumnOfGrid+j;
            indexValues.emplace_back(make_pair(tempLeft,tempRight)); //Try to optimize later perhaps?
            int numAtIndex = originalArray[tempLeft][tempRight]; //Try to optimize later perhaps?
            numberVector[tempIterate++] = numAtIndex; // Add the number to the vector

        }
    }


    //Make sure the 9 grid elements are the numbers 1-9
    if (!checkVectorOneNine(numberVector)) {
        cout << "\nThread:\nALERT! A 3x3 grid for a thread does not include the numbers 1-9" << endl;
        // Failed, turns out that the numbers in this grid are incorrect. Time for more digging
        // Check each number in the row, one by one. Check the column at the same time
        for (gridArrayVector::const_iterator it = indexValues.begin();
             it != indexValues.end(); it++) { // Iterate through indexValues
            // Set temporary vars to use for each grid value check
            int r = it->first;
            int c = it->second;
            if(checkNum(r, c)) {

                errorsFound = true; // Error or errors have been added to the answer list
            }
        }
    }

    // If errors are found, jump into this part (where solutions for each of the errors are entered into the error objects
    if (errorsFound) {

    }

    return errorsFound;

}

bool GridCheck::checkNum(int row, int column) { // Returns sum total if there is an error
    // For now, just check the whole row (problem is we will be duplicating work a ton :-/)
    // But possibly not, because you are checking for an individual number and spot!
    bool definiteError = false;
    vector<int> rowVector (9);
    vector<int> columnVector (9);

    // Set the row where the number is, and set the column as well
    for (int i = 0; i < 9; i++) {
        rowVector[i] = originalArray[row][i]; // Same row, but the column is different (so we check horizontally)
        columnVector[i] = originalArray[i][column];// Same column, but the row is different (so we check horizontally)
    }
    if (!checkVectorOneNine(rowVector) && !checkVectorOneNine(columnVector)) {
        cout << "-- We have now discovered an error for a value at row " << row+1 << ", column " << column+1 << endl;

        // Save the error area! (Row and Column)
        answerList.emplace_back(ErrorObject(row, column)); // Add Error Object to list, but don't look for the solution quite yet

        cout << "-- Adding an error object to a local list of errors!" << endl;
        definiteError = true;
    }

    return definiteError;
}


std::list<ErrorObject> GridCheck::getAnswers() {
    return answerList;
}

bool GridCheck::checkVectorOneNine(std::vector<int> stdVector) {

    // Sort the number vector, creating a list with values from 1-9 if all is good
    sort(stdVector.begin(),stdVector.end());
    for (int i = 1; i <= stdVector.size(); i++){
        // Error below
        if (stdVector.at(static_cast<unsigned long>(i)-1) != i) { //If a number is not following the order of 1-9
            return false;
        }
    }
    // Return true since the check has passed! It looks like the elements of the vector are definitely between 1-9
    return true;
}




