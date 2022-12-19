#if !defined(DEBUG)
#define DEBUG

#include "iostream"
using namespace std;
class Debug
{

public:
    static bool debugMode;
    static void change_debug_status(bool);
    static bool debug_status();
    static void debugPrinter(string, string);
    static void debugPrinter(string, int);
    static void debugPrinter(string, void (*func)());
};

#endif // DEBUG
