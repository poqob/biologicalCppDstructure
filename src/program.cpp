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
    // Debug::change_debug_status(1); // 1 to debug mode, 0 to non debug mode.

    Timer timer;
    timer.start();
    Controll *controller = new Controll();
    ReadFile *rf = new ReadFile(2001, controller);

    // Debug::debugPrinter("system size ", controller->systems[0].size());

    // cout << "oraganism size: " << controller->organism->size() << endl;

    timer.stop();
    cout << "\n time elapsed: "
         << timer.elapsedSeconds();

    return 0;
}
