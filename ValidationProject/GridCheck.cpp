//
// Created by joshsmith on 9/24/17.
//

#include <vector>
#include <list>
#include <algorithm>
#include "GridCheck.h"

using namespace std;

GridCheck::GridCheck() = default;

GridCheck::~GridCheck() = default;

GridCheck::GridCheck(int rowCenter, int columnCenter) {
    leftmostRowOfGrid = rowCenter; // Set the far left side of the array
    bottomColumnOfGrid = columnCenter; // Set the far bottom of the array

}

bool GridCheck::checkGrid() {
    vector <int> numberVector(9); // Create a vector of size 9 to store the numbers in.
    gridArrayVector indexValues; // Pairs of index values. Very important
    //Should create a vector or the like to store the 9 array indices
    int tempIterate = 0; // Use an iterator instead, possibly?
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            indexValues.emplace_back(make_pair(leftmostRowOfGrid+i,bottomColumnOfGrid+j)); //Try to optimize later perhaps?
            int numAtIndex = originalArray[leftmostRowOfGrid+i][bottomColumnOfGrid+j]; //Try to optimize later perhaps?
            numberVector[tempIterate++] = numAtIndex; // Add the number to the vector

        }
    }
    //Make sure the 9 grid elements are the numbers 1-9
    if (!checkVectorOneNine(numberVector)) {
        // Failed, turns out that the numbers in this grid are incorrect. Time for more digging
        // Check each number in the row, one by one. Check the column at the same time
        // 1. Iterate through indexValues
        for (gridArrayVector::const_iterator it = indexValues.begin();
             it != indexValues.end(); it++) { // Iterate through indexValues
            // Set temporary vars to use for each grid value check
            int r = it->first;
            int c = it->second;
            if (checkNumInRow(r, c) && checkNumInColumn(r, c)) {
                // There were errors both in the whole column, and in the whole row.
                // This means there was an error in the grid, for this specific value in this row, and for this specific value in this column
                // Probable Error! Add to your list
                answerList.emplace_back(new ErrorObject(r, c, originalArray[r][c])); // BEWARE OF MEMORY LEAKS HERE!!!

            }
            else {
                return NULL;
            }

        }
    }
        // Break into the function checking group
    else { // It's likely that the error is not within this grid, return NULL;
        return NULL;
    }

}

int GridCheck::checkNumInRow(int row, int column) { // Returns 1 if there is an error
    // For now, just check the whole row (problem is we will be duplicating work a ton :-/)
    // But possibly not, because you are checking for an individual number and spot!

    return 0;
}

int GridCheck::checkNumInColumn(int row, int column) { // Returns 1 if there is an error
    return 0;
}

std::list<ErrorObject> GridCheck::getAnswers() {

}

void GridCheck::addToAnswers(ErrorObject ansObj) {

}

void GridCheck::setOriginalArray(int **arr) {
    originalArray = arr; // set the pointer to the matrix passed in as an argument
}

bool GridCheck::checkVectorOneNine(std::vector stdVector) {
    // Sort the number vector, creating a list with values from 1-9 if all is good
    sort(stdVector.begin(),stdVector.end());
    for (int i = 1; i <= stdVector.size(); i++){
        // We need to make sure each element is
        if (stdVector.at(i) != i) { //If a number is not following the order of 1-9
            return false;
        }
    }
    // Return true since the check has passed! It looks like the elements of the vector are definitely between 1-9
    return true;
}


