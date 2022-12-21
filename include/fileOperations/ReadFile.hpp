#if !defined(READFILE)
#define READFILE
#include "iostream"
#include <string>
#include "fstream"
#include "../Controll/Controll.hpp"
using namespace std;
class ReadFile_
{
private:
    int stopRow;
    int count;
    int totalRowNumber;

public:
    Controll *controll;

    ReadFile_(int, Controll *);
    ReadFile_(Controll *);
    void rowIntParser(string row, int firstSpaceLocc, int firstNumLocc);
    int fileRowCounter();
    ~ReadFile_();
};

#endif // READFILE
