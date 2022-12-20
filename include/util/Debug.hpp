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
    static void debugPrinter(string, string, bool = 1);
    static void debugPrinter(string, bool = 1);
    static void debugPrinter(string, int, bool = 1);
    static void debugPrinter(string, double, bool = 1);
    static void debugPrinter(string, void (*func)(), bool = 1);
};

#endif // DEBUG
