#include "Cell.h"

Cell::Cell() {mValue = new int{0};}

Cell::Cell(int * iValue)
{
    if (iValue != 0 && iValue != nullptr)
    {
        mValue = iValue;
    }
    else
    {
        mValue = new int{0};
    }
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