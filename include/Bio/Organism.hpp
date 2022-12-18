#if !defined(ORGANISM)
#define ORGANISM

#include "System.hpp"
class Organism
{
private:
    System **systems;

public:
    Organism();
    void addSystem();
    void mutation();
    ~Organism();
};

#endif // ORGANISM
