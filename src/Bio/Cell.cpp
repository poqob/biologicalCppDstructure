#include "../../include/Bio/Cell.hpp"

Cell::Cell(int dna_value)
{
    dnaLenght = dna_value;
}
Cell::Cell()
{
    dnaLenght = 0;
}
void Cell::mutation()
{
    dnaLenght % 2 == 0 ? dnaLenght /= 2 : dnaLenght;
}