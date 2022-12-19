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
    Controll *controller = new Controll(1);
    ReadFile *rf = new ReadFile(101, controller); // debug
    timer.stop();
    cout << "\n time elapsed: "
         << timer.elapsedSeconds();

    return 0;
}
