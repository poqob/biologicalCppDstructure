#include "../../include/Bio/Organism.hpp"

Organism::Organism(System *systems)
{
    this->systems = systems;
}
void Organism::mutation()
{
}

void Organism::photo()
{
    string s;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 80; j++)
        {
            s = systems[i].organs[j].isTreeBalanced == 1 ? " " : "#";
            cout << s;
        }
        cout << endl;
    }
}

Organism::~Organism()
{
}