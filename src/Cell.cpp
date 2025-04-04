#include "Cell.h"

Cell::Cell() {mValue = new int{0}; mCoordinates[0] = new int{9}; mCoordinates[1] = new int{9};}

Cell::Cell(int * iValue, int * iXCoordinate, int * iYCoordinate)
{
    if (iValue != nullptr)
    {
        mValue = iValue;
    }
    else
    {
        mValue = new int{0};
    }
    mCoordinates[0] = iXCoordinate;
    mCoordinates[1] = iYCoordinate;
}

Cell::~Cell() {}

void Cell::setValue(int * iValue)
{
    mValue = iValue;
}

int* Cell::getValue()
{
    return mValue;
}

void Cell::coutCellValue()
{
    std::cout << *mValue << ", ";
}

std::array<int*, 2> Cell::getCoordinates()
{
    return mCoordinates;
}