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

GridCheck::GridCheck(int **pointer, int leftmost, int bottom) {
    originalArray = pointer;
    leftmostRowOfGrid = leftmost;
    bottomColumnOfGrid = bottom;
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
            if (checkNum(r, c)) {
                // There were errors both in the whole column, and in the whole row.
                // This means there was an error in the grid, for this specific value in this row, and for this specific value in this column
                // Probable Error! Add to your list
                answerList.emplace_back(ErrorObject(r, c, originalArray[r][c])); // BEWARE OF MEMORY LEAKS HERE!!!

            }
            else {
                return true;
            }

        }
    }
        // Break into the function checking group
    else { // It's likely that the error is not within this grid, return NULL;
        return true;
    }

    return false; // You definitely have encountered errors!

}

int GridCheck::checkNum(int row, int column) { // Returns 1 if there is an error
    // For now, just check the whole row (problem is we will be duplicating work a ton :-/)
    // But possibly not, because you are checking for an individual number and spot!
    vector<int> rowVector (9);
    vector<int> columnVector (9);

    for (int i = 0; i < 9; i++) {
        rowVector[i] = originalArray[row][i]; // Same row, but the column is different (so we check horizontally)
        columnVector[i] = originalArray[i][column];// Same column, but the row is different (so we check horizontally)
    }
    if (!checkVectorOneNine(rowVector) && !checkVectorOneNine(columnVector)) {
        return 1; // Looks like there was an error for both row and column, probable that there is an error
    }
    else{
        return 0; // Looks like there was either 1 error in either the row or column, or none at all. Unlikely there is an error
    }
}


std::list<ErrorObject> GridCheck::getAnswers() {

}

void GridCheck::setOriginalArray(int **arr) {
    originalArray = arr; // set the pointer to the matrix passed in as an argument
}

bool GridCheck::checkVectorOneNine(std::vector<int> stdVector) {
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


