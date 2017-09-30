//
// Created by joshsmith on 9/24/17.
//

#include "ErrorObject.h"

ErrorObject::ErrorObject(int row, int column, int answer) {
    _row = row;
    _column = column;
    _possibleAnswer = answer;

}

void ErrorObject::setRow(int row) {
    _row = row;
}

int ErrorObject::getRow() {
    return _row;
}

void ErrorObject::setColumn(int column) {
    _column = column;
}

int ErrorObject::getColumn() {
    return _column;
}

void ErrorObject::setAnswer(int answer) {
    _possibleAnswer = answer;
}

int ErrorObject::getAnswer() {
    return _possibleAnswer;
}
