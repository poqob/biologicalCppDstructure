#if !defined(DEBUG)
#define DEBUG

#include "iostream"
using namespace std;
class Debug
{

public:
    static bool debugMode;
    static void change_debug_status(bool); // change debug status with given parameter.
    static bool debug_status();            // returns current debug satatus.
    // to show debug message on console, set debug status=1 and function debug status to true.
    // every debugPrinter's last parameter is local debug status parameter. naturaly it's setted to 1.
    static void debugPrinter(string, string, bool = 1);
    static void debugPrinter(string, bool = 1);
    static void debugPrinter(string, int, bool = 1);
    static void debugPrinter(string, double, bool = 1);
    static void debugPrinter(string, void (*func)(), bool = 1);
};

#endif // DEBUG
