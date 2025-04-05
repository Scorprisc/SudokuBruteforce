#include <iostream>
#include <array>

class Cell{
    public:
    Cell();
    Cell(int * iValue, int * iRow, int * iColumn);
    ~Cell();

    void setValue(int * iValue);
    int * getValue();
    void coutCellValue();
    int * getRow();
    int * getColumn();

    private:

    int * mValue;
    int * mRow;
    int * mColumn;
};