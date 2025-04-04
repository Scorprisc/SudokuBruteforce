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
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            mCells[i][j] = new Cell{iCells[i][j], &i, &j};
        }
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            std::cout << *mCells[i][8]->getCoordinates()[0] << *mCells[8][i]->getCoordinates()[1] << " ";
        }
    }
    std::cout << "hi";
    for (int i = 0; i < 9; i++)
    {
        possibleValues[i] = new int{i + 1};
    }
    randomizeValues();
    // std::cout << columnSafe(mCells[3][4], new int{1}) << std::endl;
    // // std::cout << boxSafe(mCells[3][4], new int{2}) << std::endl;
    // // std::cout << safeToPlace(mCells[4][4], new int{2}) << std::endl;
    // std::cout << rowSafe(mCells[3][4], new int{2}) << std::endl;
    // // std::cout << (boxSafe(mCells[3][4], new int{2}) || rowSafe(mCells[4][4], new int{2}) || columnSafe(mCells[4][4], new int{2}));
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
            if (*mCells[i][j]->getValue() == 0)
            {
                return mCells[i][j];
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
    for (int i = 0; i < 9; i++)
    {
        std::cout << *mCells[4][i]->getCoordinates()[0] << *mCells[4][i]->getCoordinates()[1] << " ";
        if (*iValue == *mCells[*iCell->getCoordinates()[0]][i]->getValue() &&
            *iValue != 0)
        {
            return false;
        }
    }
    return true;
}

bool Sudoku::columnSafe(Cell * iCell, int * iValue)
{
    for (int i = 0; i < 9; i++)
    {
        std::cout << *mCells[i][4]->getCoordinates()[0] << *mCells[i][4]->getCoordinates()[1] << " ";
        if (*iValue == *mCells[i][*iCell->getCoordinates()[1]]->getValue() &&
            *iValue != 0)
        {
            return false;
        }
    }
    return true;
}

bool Sudoku::boxSafe(Cell * iCell, int * iValue)
{
    int BoxStart[2] = {(*iCell->getCoordinates()[0] % 3) * 3,(*iCell->getCoordinates()[1] % 3) * 3};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (*iValue == *mCells[BoxStart[0] + i][BoxStart[1] + j]->getValue() &&
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
    return (boxSafe(iCell, iValue) || rowSafe(iCell, iValue) || columnSafe(iCell, iValue));
}

void Sudoku::generateBoard()
{
    randomizeValues();
    bool BuildingBoard;
    while (BuildingBoard)
    {
        getFistEmptyCell()->setValue(possibleValues[0]);

    }
}