#include "sudoku.h"

Sudoku::Sudoku() 
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            mCells[i][j] = new Cell{0, 0, 0};
        }
    }
}
Sudoku::Sudoku(int * iCells[9][9]) 
{
    for (int row = 0; row < 9; row++)
    {
        for (int column = 0; column < 9; column++)
        {
            mCells[row][column] = new Cell{iCells[row][column], &row, &column};
        }
    }
    for (int i = 1; i <= 9; i++)
    {
        possibleValues[i] = new int{i};
    }
    randomizeValues();
    generateBoard(mCells[0][0], 0);
    coutBoard();
}

Sudoku::~Sudoku() {}

void Sudoku::coutBoard()
{
    for (int row = 0; row < 9; row++)
    {
        for (int column = 0; column < 9; column++)
        {
            mCells[row][column]->coutCellValue();
        }
        std::cout << std::endl;
    }
}

void Sudoku::randomizeValues()
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(std::begin(possibleValues), std::end(possibleValues), g);
}

Cell * Sudoku::getFistEmptyCell()
{
    for (int row = 0; row < 9; row++)
    {
        for (int column = 0; column < 9; column++)
        {
            if (*mCells[row][column]->getValue() == 0)
            {
                std::cout << "XY=" << mCells[row][column]->getRow() << mCells[row][column]->getColumn();
                return mCells[row][column];
            }
        }
    }
    Cell * emptyCell{0};
    return emptyCell;
}

// bool Sudoku::validBoard()
// {
// }

bool Sudoku::rowSafe(Cell * iCell, int * iValue)
{
    for (int column = 0; column < 9; column++)
    {
        if (*iValue == *mCells[*iCell->getRow()][column]->getValue() &&
            *iValue != 0)
        {
            return false;
        }
    }
    return true;
}

bool Sudoku::columnSafe(Cell * iCell, int * iValue)
{
    for (int row = 0; row < 9; row++)
    {
        if (*iValue == *mCells[row][*iCell->getColumn()]->getValue() &&
            *iValue != 0)
        {
            return false;
        }
    }
    return true;
}

bool Sudoku::boxSafe(Cell * iCell, int * iValue)
{
    int BoxStartX = *iCell->getRow() - *iCell->getRow() % 3;
    int BoxStartY = *iCell->getColumn() - *iCell->getColumn() % 3;
    for (int row = 0; row < 3; row++)
    {
        for (int column = 0; column < 3; column++)
        {
            if (*iValue == *mCells[BoxStartX + row][BoxStartY + column]->getValue() &&
                *iValue != 0)
            {
                return false;
            }
        }
    }
    return true;
}

bool Sudoku::safeToPlace(Cell * iCell, int * iValue)
{
    return (boxSafe(iCell, iValue) && rowSafe(iCell, iValue) && columnSafe(iCell, iValue));
}

// void Sudoku::fillCell(Cell * iCell)
// {
//     for (int i = 0; i < 9; i++)
//     {
//         if (safeToPlace(iCell, possibleValues[i]))
//         {
//             std::cout << std::endl <<"success" << *possibleValues[i];
//             iCell->setValue(possibleValues[i]);
//             break;
//         }
//     }
//     if (*iCell->getValue() == 0)
//     {
//         std::cout << "go back";
//         int previousCellX = *iCell->getRow();
//         int previousCellY = *iCell->getColumn();
//         if (previousCellX == 0)
//         {
//             previousCellX = 9;
//             previousCellY --;
//         }
//         previousCellX --;
//         mCells[previousCellX][previousCellY]->setValue(0);
//     }
// }

Cell * Sudoku::incrementCell(Cell * iCell)
{
    int outputCellRow = *iCell->getRow();
    int outputCellColumn = *iCell->getColumn();
    if (outputCellRow == 0)
    {
        outputCellRow = 7;
        outputCellColumn++;
    }
    outputCellRow++;
    return mCells[outputCellRow][outputCellColumn];
}

Cell * Sudoku::decrementCell(Cell * iCell)
{
    int outputCellRow = *iCell->getRow();
    int outputCellColumn = *iCell->getColumn();
    if (outputCellRow == 0)
    {
        outputCellRow = 9;
        outputCellColumn--;
    }
    outputCellRow--;
    return mCells[outputCellRow][outputCellColumn];
}

void Sudoku::generateBoard(Cell * iCell, int iValuePosition)
{
    randomizeValues();
    Cell * currentCell = getFistEmptyCell();
    int testingValuePosition = iValuePosition;
    iValuePosition++;
    generateBoard(currentCell, iValuePosition);
}