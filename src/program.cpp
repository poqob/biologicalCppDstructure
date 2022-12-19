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
    Debug::change_debug_status(0); // 1 to debug mode, 0 to non debug mode.

    Timer timer;
    timer.start();
    Controll *controller = new Controll();
    ReadFile *rf = new ReadFile(2000, controller);

    for (int i = 0; i < 100; i++)
    {
        cout << "organ " << i << ": " << endl;
        controller->organs[i]->inorder();
        cout << endl;
    }
    /*
    for (int i = 0; i < 100; i++)
    {
        string s = controller->organs[i]->isTreeBalanced == 1 ? " " : "*";
        cout << s;
    }*/

    timer.stop();
    cout << "\n time elapsed: "
         << timer.elapsedSeconds();

    return 0;
}
