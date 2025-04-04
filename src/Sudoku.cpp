#include "sudoku.h"

Sudoku::Sudoku() 
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            mCells[i][j] = new Cell{0};
        }
    }
}
Sudoku::Sudoku(int * iBoxes[9][9]) 
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            mCells[i][j] = new Cell{iBoxes[i][j]};
        }
    }
    for (int i = 0; i < 9; i++)
    {
        possibleValues[i] = new int{i + 1};
    }
    randomizeValues();
    std::cout << validBox(5) << std::endl;
    std::cout << validRow(5) << std::endl;
    std::cout << validColumn(5) << std::endl;
}

Sudoku::~Sudoku() {}

void Sudoku::coutBoard()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            mCells[i][j]->coutCellValue();
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
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (mCells[i][j]->getValue() == 0)
            {
                return mCells[i][j];
            }
        }
    }
    Cell * emptyCell{0};
    return emptyCell;
}

bool Sudoku::validBoard()
{
    return false;
}

bool Sudoku::validRow(int iRow)
{
    int * RowValues[9];
    for (int i = 0; i < 9; i++)
    {
        RowValues[i] = new int{*mCells[iRow - 1][i]->getValue()};
        for (int j = 0; j < i; j++)
        {
            if (*RowValues[j] == *mCells[iRow - 1][i]->getValue() &&
                *RowValues[j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

bool Sudoku::validColumn(int iColumn)
{
    int * ColumnValues[9];
    for (int i = 0; i < 9; i++)
    {
        ColumnValues[i] = new int{*mCells[i][iColumn - 1]->getValue()};
        for (int j = 0; j < i; j++)
        {
            if (*ColumnValues[j] == *mCells[i][iColumn - 1]->getValue() &&
                *ColumnValues[j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

bool Sudoku::validBox(int iBox)
{
    int * BoxValues[9];
    int BoxOffset = (iBox - 1) % 3 * 3;
    for (int i = 0; i < 9; i++)
    {
        BoxValues[i] = new int{*mCells[int(std::floor(i / 3)) + BoxOffset][i % 3 + BoxOffset]->getValue()};
        for (int j = 0; j < i; j++)
        {
            if (*BoxValues[j] == *mCells[int(std::floor(i / 3)) + BoxOffset][i % 3 + BoxOffset]->getValue() &&
                *BoxValues[j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

void Sudoku::generateBoard()
{
    randomizeValues();
    getFistEmptyCell()->setValue(possibleValues[0]);
}