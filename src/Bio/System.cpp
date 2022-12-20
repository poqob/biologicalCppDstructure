#include "../../include/Bio/System.hpp"

System::System(){};
System::System(Organ **organs, System *next)
{
    this->organs = organs;
    this->next = next;
};
System::~System(){};