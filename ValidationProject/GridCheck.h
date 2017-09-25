//
// Created by joshsmith on 9/24/17.
//

#ifndef UNTITLED_GRIDCHECK_H
#define UNTITLED_GRIDCHECK_H

#include <list>
#include "ErrorObject.h"

using namespace std;


class GridCheck {
private:
    //struct ErrorResults; // List of Row Numbers and Column numbers where there are errors. Also
    int **originalGrid; // The original 2D array of the (potentially) incorrect grid
    int centerRowOfGrid; // Row value of grid center
    int centerColumnOfGrid; // Column value of grid center
    std::list<ErrorObject> answerList; // Object list of errors, including the row/column position, and correct answer. Must initialize
public:
    GridCheck(int rowCenter, int columnCenter); //Constructor
    ~GridCheck();
    void CheckGrid(); // Check 3x3 Grid to see if values are 1-9.
    void CheckNumInRow(int num); // Check Row To See if the selected number works within it.
    void CheckNumInColumn();
    int * getOriginalGrid();




};


#endif //UNTITLED_GRIDCHECK_H
