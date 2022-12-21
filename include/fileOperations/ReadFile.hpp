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
    int stopRow;
    int count;
    int totalRowNumber;

public:
    Controll *controll;

    ReadFile(int, Controll *);
    ReadFile(Controll *);
    void rowIntParser(string row, int firstSpaceLocc, int firstNumLocc);
    int fileRowCounter();
    ~ReadFile();
};

#endif // READFILE
