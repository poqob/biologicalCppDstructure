#include "../../include/util/Debug.hpp"
bool Debug::debugMode = 0;
bool Debug::debug_status() { return debugMode; }
void Debug::change_debug_status(bool status) { debugMode = status; }
void Debug::debugPrinter(string message, string str2, bool run)
{
    if (debugMode && run)
    {
        cout << endl
             << message << str2 << endl;
    }
}
void Debug::debugPrinter(string message, int int2, bool run)
{
    if (debugMode && run)
    {
        cout << endl
             << message << int2 << endl;
    }
}
void Debug::debugPrinter(string message, bool run)
{
    if (debugMode && run == 1)
    {
        cout << endl
             << message << endl;
    }
}

void Debug::debugPrinter(string message, double double2, bool run)
{
    if (debugMode && run)
    {
        cout << endl
             << message << double2 << endl;
    }
}

void Debug::debugPrinter(string message, void (*_func)(), bool run)
{
    if (debugMode && run)
    {
        _func();
        cout << endl
             << message << endl;
    }
}
