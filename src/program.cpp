#include <iostream>
#include "../include/util/Timer.hpp"
#include "../include/Bio/Cell.hpp"
#include "../include/Bio/Tissue.hpp"
#include "../include/radixsort/Queue2.hpp"
#include "../include/Bio/Organ.hpp"
#include "../include/radixsort/Radix2.hpp"
#include "../include/fileOperations/ReadFile.hpp"

using namespace std;

int main()
{
    Timer timer;
    timer.start();
    // cells will be created after row reading.
    Controll *controller = new Controll();
    Tissue *t = new Tissue();
    Organ *o = new Organ();
    Cell *c;
    // ReadFile *rf = new ReadFile(2, controller);

    timer.stop();
    cout << "\n"
         << timer.elapsedSeconds();

    return 0;
}
