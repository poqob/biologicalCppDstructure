#include "../include/printthefile.hpp"
#include <iostream>
#include "../include/Timer.hpp"
using namespace std;

int main()
{
    Timer timer;
    timer.start();
    printthefile *p = new printthefile();
    delete p;
    timer.stop();
    cout << "\n"
         << timer.elapsedSeconds();

    return 0;
}
