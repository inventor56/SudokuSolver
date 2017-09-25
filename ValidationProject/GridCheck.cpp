//
// Created by joshsmith on 9/24/17.
//

#include "GridCheck.h"

GridCheck::GridCheck() = default;

GridCheck::~GridCheck() = default;

GridCheck::GridCheck(int rowCenter, int columnCenter) {

}

void GridCheck::CheckGrid() {

}

int GridCheck::CheckNumInRow(int row, int column, int number) {
    return 0;
}

int GridCheck::CheckNumInColumn(int row, int column, int number) {
    return 0;
}

int *GridCheck::getOriginalGrid() {
    return nullptr;
}

std::list<ErrorObject> GridCheck::getAnswers() {
    return list<ErrorObject>();
}

void GridCheck::addToAnswers(ErrorObject ansObj) {

}
