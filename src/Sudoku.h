#include <iostream>
#include <algorithm>
#include <random>
#include <cmath>

#include "Cell.h"

class Sudoku {
    public:
    Sudoku();
    Sudoku(int * iCells[9][9]);
    ~Sudoku();

    void solveBoard();
    void generateBoard();
    void coutBoard();

    void randomizeValues();
    Cell * getFistEmptyCell();

    bool rowSafe(Cell * iCell, int * iValue);
    bool columnSafe(Cell * iCell, int * iValue);
    bool boxSafe(Cell * iCell, int * iValue);
    bool safeToPlace(Cell * iCell, int * iValue);

    private:

    Cell * mCells[9][9];

    int * possibleValues[9];
};