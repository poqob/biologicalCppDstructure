#if !defined(CONTROLL)
#define CONTROLL

#include "iostream"
#include "../util/Debug.hpp"
#include "../Bio/Organism.hpp"
using namespace std;
class Controll
{
private:
    int cell_counter = -1;
    int tissue_counter = -1;
    int organ_counter = 0;
    int system_counter = 0;
    int totalSystemCount = 0;

public:
    Cell *tmpCell;
    Tissue *tmpTissue;
    Organ *tmpOrgan;
    System *tmpSystem;
    Tissue **tissues = new Tissue *[20];
    Organ **organs = new Organ *[100];
    System *systems = NULL;
    Organism *organism = NULL;

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
