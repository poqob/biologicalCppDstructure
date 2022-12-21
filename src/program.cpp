#include <iostream>
#include "../include/util/Timer.hpp"
#include "../include/util/Debug.hpp"
#include "../include/Bio/Cell.hpp"
#include "../include/Bio/Tissue.hpp"
#include "../include/radixsort/Queue2.hpp"
#include "../include/Bio/Organ.hpp"
#include "../include/radixsort/Radix2.hpp"
#include "../include/fileOperations/ReadFile.hpp"

using namespace std;

int main()
{
    Debug::change_debug_status(1); // 1 to debug mode, 0 to non debug mode.
    Timer timer;
    timer.start();
    Controll *controller = new Controll();
    ReadFile *rf = new ReadFile(controller);

    controller->showCreature();
    char a;
    cin >> a;
    controller->organism->mutation();
    controller->showCreature();

    timer.stop();
    Debug::debugPrinter("\ntime elapsed: ", timer.elapsedSeconds());

    delete rf;
    delete controller;
    return 0;
}
