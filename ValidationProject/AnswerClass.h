//
// Created by joshsmith on 10/6/17.
//

#ifndef UNTITLED_ANSWERCLASS_H
#define UNTITLED_ANSWERCLASS_H

#include <list>
#include <vector>
#include "ErrorObject.h"

// Static helper class for finding the answers

class AnswerClass {
public:
    static std::list<ErrorObject> findAnswer(int** arr, std::list<ErrorObject> errorList);
    static int checkRowOrColumn(int version, int** arr, ErrorObject errorList); // Version 0 for row, Version 1 for Column
};


#endif //UNTITLED_ANSWERCLASS_H
