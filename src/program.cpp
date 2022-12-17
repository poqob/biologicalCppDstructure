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
    Tissue *t = new Tissue();
    Cell *c;
    ReadFile *rf = new ReadFile(2);

    for (size_t i = 0; i < 20; i++)
    {
        c = new Cell(i);
        t->add(*c);
    }
    c = new Cell(5);
    t->add(*c);
    c = new Cell(3);
    t->add(*c);

    t->tissueWriter();
    cout << endl
         << "median: " << t->median << endl;
    t->sort();
    cout << endl;
    t->tissueWriter();
    cout << endl
         << "median: " << t->median << endl;
    timer.stop();
    cout << "\n"
         << timer.elapsedSeconds();

    return 0;
}
