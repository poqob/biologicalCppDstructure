#if !defined(ORGANISM)
#define ORGANISM

#include "System.hpp"
#include "../LinkedSystemList/LinkedSystemList.hpp"
using namespace std;
class Organism
{

private:
    int systemCount;
    LinkedSystemList *systems;

public:
    Organism(LinkedSystemList *, int);
    Organism();
    void mutation();
    ~Organism();
};

#endif // ORGANISM
