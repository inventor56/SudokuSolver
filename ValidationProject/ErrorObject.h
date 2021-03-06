//
// Created by joshsmith on 9/24/17.
//

#ifndef UNTITLED_ERROROBJECT_H
#define UNTITLED_ERROROBJECT_H


class ErrorObject {
private:
    int _row;
    int _column;
    int _possibleAnswer;
public:
    ErrorObject(int row, int column, int answer);
    ErrorObject(int row, int column); // Set error position, but not answer
    void setRow(int row);
    int getRow();
    void setColumn(int column);
    int getColumn();
    void setAnswer(int answer);
    int getAnswer();
    int getRowOneBase(); // Return the one based answer
    int getColumnOneBase(); // Return the one based answer




};


#endif //UNTITLED_ERROROBJECT_H
