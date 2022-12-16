#if !defined(ORGANISM)
#define ORGANISM

#include "System.hpp"
class Organism
{
private:
    System *system;

public:
    Organism();
    ~Organism();
};

#endif // ORGANISM
