#include <iostream>
#include <algorithm>
#include <random>
#include <cmath>

#include "Cell.h"

class Sudoku {
    public:
    Sudoku();
    Sudoku(int * iBoxes[9][9]);
    ~Sudoku();

    void solveBoard();
    void generateBoard();
    void coutBoard();

    void randomizeValues();
    Cell * getFistEmptyCell();

    bool validBoard();
    bool validRow(int iRow);
    bool validColumn(int iColumn);
    bool validBox(int iBox);

    private:

    Cell * mCells[9][9];

    int * possibleValues[9];
};