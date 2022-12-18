#if !defined(CONTROLL)
#define CONTROLL

#include "iostream"
#include "../Bio/Organism.hpp"
class Controll
{
private:
    int cell_counter = -1;
    int tissue_counter = -1;
    int organ_counter = -1;
    int system_counter = -1;
    Cell **cells;
    Tissue **tissues;
    Organ **organs;
    System **systems;

public:
    Controll();
    void send(int);
    void createCell(int);
    void createTissue();
    void createOrgan();
    void createSystem();
    void createOrganism();
    ~Controll();
};

#endif // CONTROLL
