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
    int **originalGrid; // The original 2D array of the (potentially) incorrect grid
    int centerRowOfGrid; // Row value of grid center
    int centerColumnOfGrid; // Column value of grid center
    std::list<ErrorObject> answerList; // Object list of errors, including the row/column position, and correct answer. Must initialize
public:
    GridCheck();
    GridCheck(int rowCenter, int columnCenter); //Constructor
    ~GridCheck(); // Destructor
    void CheckGrid(); // First check 3x3 to see if there are any noticeable errors (either !1-9 or total != 45). Then check each number to find the error/errors
    int CheckNumInRow(int row, int column, int number); // Check the row of a given number to see if the number fits. If so, return 0. Else 1 (error in row)
    int CheckNumInColumn(int row, int column, int number); // Check the column of a given number to see if the number fits. If so, return 0. Else 1 (error in column)
    int * getOriginalGrid();
    std::list<ErrorObject> getAnswers(); // Return any answers (errors and recommendations) you may have encountered.
    void addToAnswers(ErrorObject ansObj); // Possibly use this to add answers to the list (may be able to just insert)




};


#endif //UNTITLED_GRIDCHECK_H
