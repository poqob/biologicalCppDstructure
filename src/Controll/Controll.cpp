#include "../../include/Controll/Controll.hpp"

Controll::Controll(bool debug = 0)
{
    debugMode = debug;
}

void Controll::send(int value)
{
    if (cell_counter == -1)
        tmpTissue = new Tissue();
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
    tissues[tissue_counter] = tmpTissue;
    tissue_counter++;
    // debugPrinter("tissue_counter: ", tissue_counter);
    if (tissue_counter == 19)
        createOrgan();
}
void Controll::createOrgan()
{

    // TODO: we are facing an error while creating organs.
    // quick example: 100 row data generates 100/20 organs but in our example 95-97 row data generates organs.

    tmpOrgan = new Organ();
    for (int i = 0; i < tissue_counter; i++)
    {
        tmpOrgan->Add(*tissues[i]);
    }
    tissue_counter = -1;
    tmpOrgan->isTreeBalancedF();
    organs[organ_counter] = tmpOrgan;
    organ_counter++;

    debugPrinter("\n organ balance status: ", tmpOrgan->isTreeBalanced == 1 ? " true" : "false");
    debugPrinter("total organ count: ", organ_counter);

    if (organ_counter == 99)
        createSystem();
}
void Controll::createSystem()
{
    organ_counter = -1;
    system_counter++;
    cout << "system counter: " << system_counter << " \n";
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
