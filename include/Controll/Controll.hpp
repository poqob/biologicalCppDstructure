#if !defined(CONTROLL)
#define CONTROLL

#include "iostream"

#include "../Bio/Organism.hpp"
using namespace std;
class Controll
{
private:
    bool debugMode = 0;
    int cell_counter = -1;
    int tissue_counter = -1;
    int organ_counter = 0;
    int system_counter = 0;
    int totalSystemCount = 0;
    Cell *tmpCell;
    Tissue *tmpTissue;
    Organ *tmpOrgan;
    System *tmpSystem;
    Tissue **tissues = new Tissue *[20];
    Organ **organs = new Organ *[100];
    System **systems;
    Organism *organism;

public:
    Controll(bool);
    void totalSystemCountSetter(int);
    void send(int);
    void nextRow();
    void createTissue();
    void createOrgan();
    void createSystem();
    void createOrganism();
    bool debug_status();
    void debugPrinter(string, string);
    void debugPrinter(string, int);
    void debugPrinter(string, void (*func)());
    void debugPrinterPhoto();
    ~Controll();
};

#endif // CONTROLL
