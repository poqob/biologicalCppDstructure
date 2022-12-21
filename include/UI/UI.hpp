#if !defined(UI)
#define UI
#include "sstream"
#include "iostream"
#include <Windows.h>
using namespace std;
class Ui
{
private:
    stringstream output;
    bool check = 0;
    HANDLE hConsole;

public:
    Ui();
    void set_visual(bool);
    void draw(string, stringstream, bool isMutated = 0);
};

#endif // UI

// Purpose of Ui class: maybe soft writer methods can be coded here to gain visual pleasure.