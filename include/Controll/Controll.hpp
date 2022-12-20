#if !defined(CONTROLL)
#define CONTROLL

#include "iostream"
#include "../util/Debug.hpp"
#include "../Bio/Organism.hpp"
#include "../LinkedSystemList/LinkedSystemList.hpp"
using namespace std;
class Controll
{
public:
    int cell_counter;
    int tissue_counter;
    int organ_counter;
    int system_counter;
    int totalSystemCount;

public:
    Cell *tmpCell;
    Tissue *tmpTissue;
    Organ *tmpOrgan;
    System *tmpSystem;
    Tissue **tissues;
    Organ **organs;
    LinkedSystemList *systems;
    Bst *bst;
    Organism *organism;

public:
    Controll();
    void totalSystemCountSetter(int);
    void send(int);
    void nextRow();
    void createTissue();
    void createOrgan();
    void createSystem();
    void createOrganism();

    ~Controll();
};

#endif // CONTROLL
