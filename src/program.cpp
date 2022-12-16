#include <iostream>
#include "../include/util/Timer.hpp"
#include "../include/Bio/Cell.hpp"
#include "../include/Bio/Tissue.hpp"
#include "../include/radixsort/Queue2.hpp"
#include "../include/radixsort/Radix2.hpp"

using namespace std;

int main()
{
    Timer timer;
    timer.start();
    Cell *cell = new Cell[20];
    Tissue *t = new Tissue();
    for (size_t i = 0; i < 20; i++)
    {
        cell[i] = i;
        t->add(cell[i]);
    }
    t->add(Cell(5));
    t->add(Cell(3));
    cout << t->size() << endl
         << " tissue: ";
    t->tissueWriter();

    Radix2 *r = new Radix2(t->items, t->size());
    Cell *sirali = r->Sort();

    cout << endl
         << "sirali: ";
    for (int i = 0; i < t->size(); i++)
    {
        cout << sirali[i].dnaLenght << " ";
    }

    timer.stop();
    cout << "\n"
         << timer.elapsedSeconds();

    return 0;
}
