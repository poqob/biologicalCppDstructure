#include "../../include/Bio/System.hpp"

System::System(Organ *organs)
{
    this->organs = organs;
}

void System::mutation()
{
    for (int i = 0; i < 100; i++)
    {
        organs[i].mutation();
    }
}
System::~System()
{
    delete[] organs;
}
