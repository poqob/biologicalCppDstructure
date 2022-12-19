#include "../../include/util/Debug.hpp"
bool Debug::debugMode = 0;
bool Debug::debug_status() { return debugMode; }
void Debug::change_debug_status(bool status) { debugMode = status; }
void Debug::debugPrinter(string message, string str2)
{
    if (debugMode)
    {
        cout << endl
             << message << str2 << endl;
    }
}
void Debug::debugPrinter(string message, int str2)
{
    if (debugMode)
    {
        // tissues[tissue_counter]->tissueWriter();
        cout << endl
             << message << str2 << endl;
    }
}

void Debug::debugPrinter(string message, void (*_func)())
{
    if (debugMode)
    {
        _func();
        cout << endl
             << message << endl;
    }
}
