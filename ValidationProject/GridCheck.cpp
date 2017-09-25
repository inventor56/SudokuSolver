//
// Created by joshsmith on 9/24/17.
//

#include <vector>
#include <list>
#include "GridCheck.h"

using namespace std;

GridCheck::GridCheck() = default;

GridCheck::~GridCheck() = default;

GridCheck::GridCheck(int rowCenter, int columnCenter) {
    leftmostRowOfGrid = rowCenter; // Set the far left side of the array
    bottomColumnOfGrid = columnCenter; // Set the far bottom of the array

}

void GridCheck::CheckGrid() {
    vector <int> numberVector(9); // Create a vector of size 9 to store the numbers in.
    int total = 0; // Total of all 9 numbers in 3x3 grid
    int tempIterate = 0; // Use an iterator instead, possibly?
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int numAtIndex = originalArray[leftmostRowOfGrid+i][bottomColumnOfGrid+j];
            total += numAtIndex; //  Add the number to the total
            numberVector[tempIterate++] = numAtIndex; // Add the number to the vector

        }
    }
    /*
    if ( //!1-9 && total != 45) { // Break into main function checking loop!

    }
    else { // It's likely that the error is not within this grid, return NULL;

    } */

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
