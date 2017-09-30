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
    typedef std::pair<int, int> gridArrayPair; //Pair of row and column values;
    typedef std::vector<gridArrayPair> gridArrayVector; // Vector storing the relative grid array values (for instance, [3,2])
    std::list<ErrorObject> answerList; // Object list of errors, including the row/column position, and correct answer. Must initialize
public:
    GridCheck();
    GridCheck(int rowCenter, int columnCenter); //Constructor
    ~GridCheck(); // Destructor
    bool checkGrid(); // First check 3x3 to see if there are any noticeable errors (either !1-9 or total != 45). Then check each number to find the error/errors
    void setOriginalArray(int ** arr);
    int checkNumInRow(int row, int column); // Check the row of a given number to see if the number fits. If so, return 0. Else 1 (error in row)
    int checkNumInColumn(int row, int column); // Check the column of a given number to see if the number fits. If so, return 0. Else 1 (error in column)
    bool checkVectorOneNine(std::vector stdVector); // Check if a given vector (of size 9) has the elements one through nine within it O(N) runtime
    std::vector<int>  getNumbersInRowOrColumn; // Return a vector listing the 9 numbers within a row or column.
    std::list<ErrorObject> getAnswers(); // Return any answers (errors and recommendations) you may have encountered.
    void addToAnswers(ErrorObject ansObj); // Possibly use this to add answers to the list (may be able to just insert).




};


#endif //UNTITLED_GRIDCHECK_H
