#include <iostream>
#include <array>

class Cell{
    public:
    Cell();
    Cell(int * iValue, int * iXCoordinate, int * iYCoordinate);
    ~Cell();

    void setValue(int * iValue);
    int * getValue();
    void coutCellValue();
    std::array<int*, 2> getCoordinates();

    private:

    int * mValue;
    std::array<int*, 2> mCoordinates;
};