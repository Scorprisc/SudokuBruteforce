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
            mCells[row][column] = new Cell{iCells[row][column], row, column};
        }
    }
    for (int i = 1; i <= 9; i++)
    {
        possibleValues[i] = new int{i};
    }
    randomizeValues();
    generateBoard(mCells[0][0], 0, 0);
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
                // std::cout << "XY=" << mCells[row][column]->getRow() << ":" << mCells[row][column]->getColumn() << "|";
                mCells[row][column]->coutCoordinates();
                return mCells[row][column];
            }
        }
    }
    Cell * emptyCell = new Cell{0, 0, 0};
    return emptyCell;
}

bool Sudoku::rowSafe(Cell * iCell, int * iValue)
{
    for (int column = 0; column < 9; column++)
    {
        if (*iValue == *mCells[iCell->getRow()][column]->getValue() &&
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
        if (*iValue == *mCells[row][iCell->getColumn()]->getValue() &&
            *iValue != 0)
        {
            return false;
        }
    }
    return true;
}

bool Sudoku::boxSafe(Cell * iCell, int * iValue)
{
    int BoxStartX = iCell->getRow() - iCell->getRow() % 3;
    int BoxStartY = iCell->getColumn() - iCell->getColumn() % 3;
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

Cell * Sudoku::incrementCell(Cell * iCell)
{
    int outputCellRow = iCell->getRow();
    int outputCellColumn = iCell->getColumn();
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
    int outputCellRow = iCell->getRow();
    int outputCellColumn = iCell->getColumn();
    if (outputCellRow == 0)
    {
        outputCellRow = 9;
        outputCellColumn--;
    }
    outputCellRow--;
    return mCells[outputCellRow][outputCellColumn];
}

void Sudoku::generateBoard(Cell * iCell, int iValuePosition, int iCurrentLoop)
{
    // int CurrentLoop = iCurrentLoop + 1;
    // if (CurrentLoop < 1000)
    // {
    //     Cell * currentCell = getFistEmptyCell();
    //     // std::cout << currentCell->getRow() << ":" << currentCell->getColumn() << "|";
    //     int testingValuePosition = iValuePosition;
    //     if (safeToPlace(currentCell, possibleValues[testingValuePosition]))
    //     {
    //         currentCell->setValue(possibleValues[0]);
    //         randomizeValues();
    //         generateBoard(incrementCell(currentCell), 0, CurrentLoop);
    //     }
    //     else if (testingValuePosition == 0)
    //     {

    //     }
    //     testingValuePosition++;
    // }
}