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
System::~System()
{
    delete next;
    delete[] organs;
};