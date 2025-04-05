#include <iostream>
#include <vector>

#include "Sudoku.h"

int main() {

    // int * CellsValues[81] =
    // {
    //     new int{5}, new int{3}, new int{0}, new int{6}, new int{0}, new int{0}, new int{0}, new int{9}, new int{8},
    //     new int{4}, new int{0}, new int{0}, new int{8}, new int{0}, new int{3}, new int{0}, new int{0}, new int{1},
    //     new int{7}, new int{0}, new int{0}, new int{0}, new int{2}, new int{0}, new int{0}, new int{0}, new int{6},
    //     new int{9}, new int{0}, new int{0}, new int{5}, new int{0}, new int{0}, new int{0}, new int{0}, new int{7},
    //     new int{0}, new int{0}, new int{6}, new int{0}, new int{0}, new int{0}, new int{2}, new int{0}, new int{0},
    //     new int{8}, new int{0}, new int{0}, new int{0}, new int{3}, new int{0}, new int{0}, new int{6}, new int{9},
    //     new int{2}, new int{0}, new int{0}, new int{7}, new int{0}, new int{0}, new int{6}, new int{0}, new int{0},
    //     new int{3}, new int{0}, new int{0}, new int{9}, new int{0}, new int{0}, new int{0}, new int{8}, new int{2},
    //     new int{0}, new int{5}, new int{0}, new int{0}, new int{6}, new int{8}, new int{0}, new int{7}, new int{4}
    // };

    // int CellsValues[81] =
    // {
    //     5,3,0,6,0,0,0,9,8,
    //     4,0,0,8,0,3,0,0,1,
    //     7,0,0,0,2,0,0,0,6,
    //     9,0,0,5,0,0,0,0,7,
    //     0,0,6,0,0,0,2,0,0,
    //     8,0,0,0,3,0,0,6,9,
    //     2,0,0,7,0,0,6,0,0,
    //     3,0,0,9,0,0,0,8,2,
    //     0,5,0,0,6,8,0,7,4
    // };
    
    int CellsValues[81] =
    {
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0
    };

    int * BoxValues[9][9] = {0};
    for (int row = 0; row < 9; row++)
    {
        for (int column = 0; column < 9; column++)
        {
            BoxValues[row][column] = &CellsValues[row * 9 + column];
        }
    }

    Sudoku sudokuBoard{BoxValues};

    // sudokuBoard.coutBoard();
    return 0;
}