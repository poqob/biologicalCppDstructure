#if !defined(SYSTEM)
#define SYSTEM

#include "Organ.hpp"
class System
{
private:
    Organ *organ = new Organ[100];

public:
    System();
    ~System();
};

#endif // SYSTEM
