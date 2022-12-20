#include "../../include/Bio/Organism.hpp"

Organism::Organism(LinkedSystemList *systems, int lenght)
{
    this->systems = systems;
    this->systemCount = lenght;
}
Organism::Organism() {}
void Organism::mutation(){};
Organism::~Organism(){};