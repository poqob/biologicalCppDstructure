#include <iostream>
#include "../include/util/Timer.hpp"
#include "../include/util/Debug.hpp"
#include "../include/fileOperations/ReadFile.hpp"
#include "../include/UI/UI.hpp"

using namespace std;

int main()
{
    Debug::change_debug_status(0); // 1 to debug mode, 0 to non debug mode.
    Timer timer;                   // debug mode feature. I measured time for every single debug, it's only curious.
    Ui ui = Ui();                  // UI, it's only related with visual output thats the reason i didn't new it on heap.
    timer.start();

    Controll *controller = new Controll();                               // controll class
    ReadFile *rf = new ReadFile(controller);                             // read file class
    ui.draw("ORGANIZMA", controller->showCreature());                    // drawing output to console with specified header
    controller->organism->mutation();                                    // mutate the organism
    ui.draw("ORGANIZMA (MUTASYONA UGRADI)", controller->showCreature()); // redraw the organism

    timer.stop();
    Debug::debugPrinter("\ntime elapsed: ", timer.elapsedSeconds()); // debeug mode printer

    delete rf;
    delete controller; // sub deletions in controller destructor
    return 0;
}
