#if !defined(UI)
#define UI
#include "sstream"
#include "iostream"

using namespace std;
class Ui
{
private:
    stringstream output;

public:
    Ui();
    void draw(string, stringstream);
};

#endif // UI

// Purpose of Ui class: maybe soft writer methods can be coded here to gain visual pleasure.