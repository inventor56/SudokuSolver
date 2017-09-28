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

bool GridCheck::CheckGrid() {
    vector <int> numberVector(9); // Create a vector of size 9 to store the numbers in.
    typedef pair<int, int> gridArrayPair; //Pair of row and column values;
    typedef vector<gridArrayPair> gridArrayVector; // Vector storing the relative grid array values (for instance, [3,2])
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
    if (!CheckVectorOneNine(numberVector));
         // Failed, turns out that the numbers in this grid are incorrect. Time for more digging
        // Check each number in the row, one by one. Check the column at the same time

        // Break into the function checking group
    else { // It's likely that the error is not within this grid, return NULL;
        return NULL;
    }

}

int GridCheck::CheckNumInRow(int row, int column, int number) {

}

int GridCheck::CheckNumInColumn(int row, int column, int number) {

}

std::list<ErrorObject> GridCheck::getAnswers() {

}

void GridCheck::addToAnswers(ErrorObject ansObj) {

}

void GridCheck::setOriginalArray(int **arr) {
    originalArray = arr; // set the pointer to the matrix passed in as an argument
}

bool GridCheck::CheckVectorOneNine(std::vector stdVector) {
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
