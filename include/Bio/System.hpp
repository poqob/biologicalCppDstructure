#if !defined(SYSTEM)
#define SYSTEM

#include "Organ.hpp"
using namespace std;
class System
{
public:
    // fields
    System *next;
    Organ **organs;
    // methods
    System(Organ **, System *);
    System();
    void mutation();
    ~System();
};

#endif // SYSTEM
