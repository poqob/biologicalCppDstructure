#if !defined(READFILE)
#define READFILE
#include "iostream"
#include <string>
#include "fstream"
#include "../Controll/Controll.hpp"
using namespace std;
class ReadFile
{
private:
public:
    ReadFile(int);
    void rowIntParser(string);
    void rowIntParser(string row, int firstSpaceLocc, int firstNumLocc);
    Controll *controll = new Controll(); // TODO: Don't forget destructor.
    ~ReadFile();
};

#endif // READFILE
