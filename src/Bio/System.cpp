#include "../../include/Bio/System.hpp"

System::System()
{
    this->next = NULL;
    this->organs = NULL;
};
System::System(Organ **organs, System *next)
{
    this->organs = organs;
    this->next = next;
};

void System::mutation()
{
    for (int i = 0; i < 99; i++)
        organs[i]->mutation();
}
System::~System()
{
    delete[] organs;
};