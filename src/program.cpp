#include <iostream>
#include "../include/util/Timer.hpp"
#include "../include/Bio/Cell.hpp"
#include "../include/Bio/Tissue.hpp"

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
    cout << t->size() << endl;
    t->tissueWriter();

    timer.stop();
    cout << "\n"
         << timer.elapsedSeconds();

    return 0;
}
