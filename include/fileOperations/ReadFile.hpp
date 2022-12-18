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
    int stopRow = -1;

public:
    ReadFile(int, Controll *);
    void rowIntParser(string row, int firstSpaceLocc, int firstNumLocc);
    Controll *controll;
    ~ReadFile();
};

#endif // READFILE
