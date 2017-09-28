//
// Created by joshsmith on 9/24/17.
//

#ifndef UNTITLED_GRIDCHECK_H
#define UNTITLED_GRIDCHECK_H

#include <list>
#include "ErrorObject.h"


class GridCheck {
private:
    int ** originalArray; // The original 9x9 array
    int leftmostRowOfGrid; // Row value of grid center
    int bottomColumnOfGrid; // Column value of grid center
    std::list<ErrorObject> answerList; // Object list of errors, including the row/column position, and correct answer. Must initialize
public:
    GridCheck();
    GridCheck(int rowCenter, int columnCenter); //Constructor
    ~GridCheck(); // Destructor
    bool CheckGrid(); // First check 3x3 to see if there are any noticeable errors (either !1-9 or total != 45). Then check each number to find the error/errors
    void setOriginalArray(int ** arr);
    int CheckNumInRow(int row, int column, int number); // Check the row of a given number to see if the number fits. If so, return 0. Else 1 (error in row)
    int CheckNumInColumn(int row, int column, int number); // Check the column of a given number to see if the number fits. If so, return 0. Else 1 (error in column)
    bool CheckVectorOneNine(std::vector stdVector); // Check if a given vector (of size 9) has the elements one through nine within it O(N) runtime
    std::list<ErrorObject> getAnswers(); // Return any answers (errors and recommendations) you may have encountered.
    void addToAnswers(ErrorObject ansObj); // Possibly use this to add answers to the list (may be able to just insert).




};


#endif //UNTITLED_GRIDCHECK_H
