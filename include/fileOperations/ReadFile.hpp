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
    int count = 0;
    int totalRowNumber = 0;

public:
    ReadFile(int, Controll *);
    ReadFile(Controll *);
    void rowIntParser(string row, int firstSpaceLocc, int firstNumLocc);
    int fileRowCounter();
    Controll *controll;
    ~ReadFile();
};

#endif // READFILE
