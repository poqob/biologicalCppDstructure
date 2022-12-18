#include "../../include/Controll/Controll.hpp"

Controll::Controll()
{
}

void Controll::send(int value)
{
    cells[++cell_counter] = new Cell(value); // cccc
}

void Controll::createCell(int value)
{
}
void Controll::createTissue()
{

    tissues[++tissue_counter] = new Tissue();
    for (int i = 0; i < cell_counter; i++)
    {
        tissues[tissue_counter]->add(*cells[i]);
    }
    tissues[tissue_counter]->sort();
    cell_counter = 0;

    if (tissue_counter % 20 == 0)
        createOrgan();
}
void Controll::createOrgan()
{
    organs[++organ_counter] = new Organ();
    for (int i = 0; i < tissue_counter; i++)
    {
        organs[organ_counter]->Add(*tissues[i]);
    }
    organs[organ_counter]->isTreeBalancedF();
    tissue_counter = 0;
    if (organ_counter % 100 == 0)
        createSystem();
}
void Controll::createSystem()
{
    systems[++system_counter] = new System();
    // TODO: create adding methods for System class.
}
void Controll::createOrganism()
{
    cout << "zort";
}

Controll::~Controll()
{
}
