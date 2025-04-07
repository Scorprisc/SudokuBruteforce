#include <iostream>
#include <array>

class Cell{
    public:
    Cell();
    Cell(int * iValue, int iRow, int iColumn);
    ~Cell();

    void setValue(int * iValue);
    int * getValue();
    int getRow();
    int getColumn();

    void coutCellValue();
    void coutCoordinates();

    private:

    int * mValue;
    int mRow;
    int mColumn;
};