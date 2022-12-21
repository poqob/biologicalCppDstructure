#include <iostream>
#include "../include/util/Timer.hpp"
#include "../include/util/Debug.hpp"
#include "../include/Bio/Cell.hpp"
#include "../include/Bio/Tissue.hpp"
#include "../include/radixsort/Queue2.hpp"
#include "../include/Bio/Organ.hpp"
#include "../include/radixsort/Radix2.hpp"
#include "../include/fileOperations/ReadFile.hpp"
#include "../include/UI/UI.hpp"

using namespace std;

int main()
{
    Debug::change_debug_status(0); // 1 to debug mode, 0 to non debug mode.
    Timer timer;
    char s;
    Ui ui = Ui();
    timer.start();

    Controll *controller = new Controll();
    ReadFile *rf = new ReadFile(controller);
    ui.draw("ORGANIZMA", controller->showCreature());
    controller->organism->mutation();
    ui.draw("ORGANIZMA (MUTASYONA UGRADI)", controller->showCreature());

    timer.stop();
    Debug::debugPrinter("\ntime elapsed: ", timer.elapsedSeconds());

    delete rf;
    delete controller;
    return 0;
}
