#if !defined(CONTROLL)
#define CONTROLL
#define MAXORGAN 100
#define MAXTISSUE 20

#include "iostream"
#include "sstream"
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
    Tissue **tissues;
    Organ **organs;
    LinkedSystemList *systems;
    Bst *bst;
    Cell *tmpCell;

public:
    Tissue *tmpTissue;
    Organ *tmpOrgan;
    System *tmpSystem;
    Organism *organism;

public:
    Controll();
    void totalSystemCountSetter(int);
    void send(int);
    void nextRow();
    stringstream showCreature(string character = "#");
    void createTissue();
    void createOrgan();
    void createSystem();
    void createOrganism();

    ~Controll();
};

#endif // CONTROLL
