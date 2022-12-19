#include "../../include/Controll/Controll.hpp"

Controll::Controll(bool debug = 0)
{
    debugMode = debug;
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
    debugPrinter("total organ count: ", organ_counter + 1);
    organ_counter++;
    if (organ_counter == 100)
        createSystem();
}
void Controll::createSystem()
{
    organ_counter = 0;
    tissue_counter = -1;
    system_counter++;
    debugPrinter("system count: ", system_counter);
}
void Controll::createOrganism()
{
    cout << "zort";
}

Controll::~Controll()
{
}
bool Controll::debug_status() { return debugMode; }
void Controll::debugPrinter(string message, string str2)
{
    if (debugMode)
    {
        cout << endl
             << message << str2 << endl;
    }
}
void Controll::debugPrinter(string message, int str2)
{
    if (debugMode)
    {
        // tissues[tissue_counter]->tissueWriter();
        cout << endl
             << message << str2 << endl;
    }
}

void Controll::debugPrinter(string message, void (*_func)())
{
    if (debugMode)
    {
        _func();
        cout << endl
             << message << endl;
    }
}
