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

    string r;
    System *sysptr = controller->systems->head;
    for (int i = 0; i < 25; i++)
    {
        sysptr = sysptr->next;
        for (int i = 0; i < 100; i++)
        {
            r = sysptr->organs[i]->bst->isTreeBalanced == true ? " " : "#";
            cout << r;
        }
        cout << endl;
    }

    Debug::debugPrinter("system list size: ", controller->systems->size());

    timer.stop();
    Debug::debugPrinter("\ntime elapsed: ", timer.elapsedSeconds());

    return 0;
}
