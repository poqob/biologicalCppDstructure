#if !defined(READFILE)
#define READFILE
#include "iostream"
#include <string>
#include "fstream"
#include "../Bio/Tissue.hpp"
using namespace std;
class ReadFile
{
private:
public:
    ReadFile(Tissue *, int);
    void rowIntParser(string);
    void rowIntParser(string row, int firstSpaceLocc, int firstNumLocc);
    int intcounter = 0;
    Tissue *tissue;
    ~ReadFile();
};

#endif // READFILE
