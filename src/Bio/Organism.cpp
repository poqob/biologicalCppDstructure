#include "../../include/Bio/Organism.hpp"

Organism::Organism(LinkedSystemList *systems)
{
    this->systems = systems;
    this->systemCount = systems->size();
}
Organism::Organism() {}
bool Organism::mutation()
{
    System *sysptr = systems->head;
    for (int i = 0; i < systemCount - 1; i++)
    {
        sysptr = sysptr->next;
        sysptr->mutation();
    }
    return true;
};
Organism::~Organism()
{
    delete systems;
};