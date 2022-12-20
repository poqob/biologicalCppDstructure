#if !defined(SYSTEM)
#define SYSTEM

#include "Organ.hpp"
using namespace std;
class System
{
public:
    System *next;
    Organ **organs;
    System();
    System(Organ **, System *);
    ~System();
};

#endif // SYSTEM
