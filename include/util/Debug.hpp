#if !defined(DEBUG)
#define DEBUG

#include "iostream"
using namespace std;
class Debug
{

public:
    bool debugMode = 0;
    void change_debug_status(bool);
    bool debug_status();
    void debugPrinter(string, string);
    void debugPrinter(string, int);
    void debugPrinter(string, void (*func)());
};

#endif // DEBUG
