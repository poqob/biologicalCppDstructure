#include "../../include/Controll/Controll.hpp"

Controll::Controll()
{
    cell_counter = 0;
    tissue_counter = 0;
    organ_counter = 0;
    system_counter = 0;
    totalSystemCount = 0;
    tissues = new Tissue *[20];
    organs = new Organ *[100];
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
    if (tissue_counter == 20)
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
    if (organ_counter == 100)
        createSystem();
}
void Controll::createSystem()
{
    tmpSystem = new System();
    tmpSystem->organs = organs;
    systems->add(*tmpSystem);
    organs = new Organ *[100];
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
void Controll::showCreature()
{
    // i used try catch the reason for that, i'm testing my code on linux as well.
    // linux bash use 'clear' instead 'cls'
    try
    {
        system("cls");
    }
    catch (const std::exception &e)
    {
    }

    string r;
    System *sysptr = this->systems->head;
    for (int i = 0; i < 25; i++)
    {
        sysptr = sysptr->next;
        for (int i = 0; i < 100; i++)
        {
            r = sysptr->organs[i]->bst->isTreeBalanced == true ? " " : "#";
            cout << r;
        }
        cout << endl;
    }
}
Controll::~Controll()
{
    delete organism;  // deletes all the organism with all sub classes.
    delete[] tissues; // deletes local array
    delete[] organs;  // deletes local array
    Debug::debugPrinter("deletion succesfull.");
    try
    {
        system("pause");
    }
    catch (const std::exception &e)
    {
    }
}

void Controll::totalSystemCountSetter(int set)
{
    totalSystemCount = set / 2000;
}
