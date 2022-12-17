#include <iostream>
#include "../include/util/Timer.hpp"
#include "../include/Bio/Cell.hpp"
#include "../include/Bio/Tissue.hpp"
#include "../include/radixsort/Queue2.hpp"
#include "../include/radixsort/Radix2.hpp"
#include "../include/fileOperations/ReadFile.hpp"

using namespace std;

int main()
{
    Timer timer;
    timer.start();
    // cells will be created after row reading.
    Cell *cell = new Cell[20];
    Tissue *t = new Tissue();
    ReadFile *rf = new ReadFile(t, 2);
    /*
    for (size_t i = 0; i < 20; i++)
    {
        cell[i] = i;
        t->add(cell[i]);
    }
    t->add(Cell(5));
    t->add(Cell(3));
    */
    t = rf->tissue;
    cout << t->size() << endl
         << " tissue: ";
    t->tissueWriter();

    Radix2 *r = new Radix2(t->items, t->size());
    Cell *sirali = r->Sort();

    cout << endl
         << "ordered tissue(" << t->size() << "): ";
    for (int i = 0; i < t->size(); i++)
    {
        cout << sirali[i].dnaLenght << " ";
    }

    timer.stop();
    cout << "\n"
         << timer.elapsedSeconds();

    return 0;
}
