#include "../../include/Controll/Controll.hpp"

Controll::Controll()
{
}

void Controll::send(int value)
{
    if (cell_counter == -1)
    {
        tmpTissue = new Tissue();
    }
    cell_counter++;
    tmpCell = new Cell(value);
    tmpTissue->add(*tmpCell);
}

void Controll::nextRow()
{
    createTissue();
}
void Controll::createTissue()
{
    cell_counter = -1;
    tmpTissue->sort();
    tissue_counter++; // starts with -1 increment makes it prev_val+1;
    tissues[tissue_counter] = tmpTissue;
    // debugPrinter("tissue_counter: ", tissue_counter);
    if (tissue_counter == 19) // the counter started with value -1, so 20 next value is 18.
        createOrgan();
}
void Controll::createOrgan()
{

    tmpOrgan = new Organ();
    for (int i = 0; i < tissue_counter; i++)
    {
        tmpOrgan->Add(*tissues[i]);
    }
    tissue_counter = -1;
    tmpOrgan->isTreeBalancedF();
    organs[organ_counter] = tmpOrgan;

    // debugPrinter("\n organ balance status: ", tmpOrgan->isTreeBalanced == 1 ? " true" : "false");
    Debug::debugPrinter("total organ count: ", organ_counter + 1);
    organ_counter++;
    if (organ_counter == 100)
        createSystem();
}
void Controll::createSystem()
{

    if (systems == NULL)
        systems = new System[totalSystemCount];
    tmpSystem = new System(*organs);
    systems[system_counter] = *tmpSystem;
    organ_counter = 0;
    tissue_counter = -1;
    system_counter++;
    // debugPrinter("current system count: ", system_counter);
    // debugPrinter("organs[0] balance status: ", systems[system_counter - 1]->organs[0].isTreeBalanced);
    organs = new Organ *[100];
}
void Controll::createOrganism()
{
    // organism = new Organism(*systems);
    // organism->photo();
}

Controll::~Controll()
{
}

void Controll::totalSystemCountSetter(int set)
{
    totalSystemCount = set / 2000;
    // debugPrinter("total system count: ", totalSystemCount);
}

// TODO: we can't access system's organs. check arrays if you wont have any idea turn systems to a propper data structure.<-- i reccomend that.