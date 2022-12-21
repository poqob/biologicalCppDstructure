#include "../../include/Controll/Controll.hpp"

Controll::Controll()
{
    cell_counter = 0;
    tissue_counter = 0;
    organ_counter = 0;
    system_counter = 0;
    totalSystemCount = 0;
    tissues = new Tissue *[MAXTISSUE];
    organs = new Organ *[MAXORGAN];
    systems = new LinkedSystemList();
}

void Controll::send(int value)
{
    if (cell_counter == 0)
    {
        tmpTissue = new Tissue();
        tissue_counter++;
    }
    tmpCell = new Cell(value);
    tmpTissue->add(*tmpCell);
    cell_counter++;
}

void Controll::nextRow()
{
    createTissue();
}
void Controll::createTissue()
{
    cell_counter = 0;
    tmpTissue->sort();
    tissues[tissue_counter - 1] = tmpTissue;
    if (tissue_counter == MAXTISSUE)
        createOrgan();
}
void Controll::createOrgan()
{

    bst = new Bst();
    tmpOrgan = new Organ();
    for (int i = 0; i < tissue_counter; i++)
    {
        if (!tissues[i]->isEmpty())
            bst->Add(*tissues[i]);
        else
            Debug::debugPrinter("CREATED NULL", false);
    }
    tissue_counter = 0;
    cell_counter = 0;
    bst->isTreeBalancedF();
    tmpOrgan->bst = bst;
    organs[organ_counter] = tmpOrgan;
    organ_counter++;
    Debug::debugPrinter("ORGAN COUNTER:  ", organ_counter, false);
    if (organ_counter == MAXORGAN)
        createSystem();
}
void Controll::createSystem()
{
    tmpSystem = new System();
    tmpSystem->organs = organs;
    systems->add(*tmpSystem);
    organs = new Organ *[MAXORGAN];
    organ_counter = 0;
    tissue_counter = 0;
    cell_counter = 0;
    system_counter++;
}
void Controll::createOrganism()
{
    Debug::debugPrinter("CREATE ORGANISM CALLED", false);
    organism = new Organism(systems);
}
stringstream Controll::showCreature(string character)
{

    stringstream stream;

    string r;
    System *sysptr = this->systems->head;
    for (int i = 0; i < system_counter; i++)
    {
        sysptr = sysptr->next;
        for (int i = 0; i < MAXORGAN; i++)
        {
            r = sysptr->organs[i]->bst->isTreeBalanced == true ? " " : character;
            stream << r;
        }
        stream << endl;
    }
    return stream;
}
Controll::~Controll()
{
    delete organism;  // deletes all the organism with all sub classes.
    delete[] tissues; // deletes local array
    delete[] organs;  // deletes local array
    Debug::debugPrinter("deletion succesfull.");
}

void Controll::totalSystemCountSetter(int row)
{
    totalSystemCount = row / MAXORGAN * MAXTISSUE;
}
