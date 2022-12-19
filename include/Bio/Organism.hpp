#if !defined(ORGANISM)
#define ORGANISM

#include "System.hpp"
class Organism
{
private:
    System *systems;

public:
    Organism(System *);
    void mutation();
    void photo();
    ~Organism();
};

#endif // ORGANISM
