#include <iostream>

class Cell{
    public:
    Cell();
    Cell(int * iValue);
    ~Cell();

    void setValue(int * iValue);
    int* getValue();
    void coutCellValue();

    private:

    int * mValue;
};