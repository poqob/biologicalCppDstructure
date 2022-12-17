#if !defined(CONTROLL)
#define CONTROLL

#include "iostream"
#include "../Bio/Tissue.hpp"
class Controll
{
private:
    int counter = 0;

public:
    Controll();
    void send(int);
    void createCell();
    void createTissue();
    void createOrgan();
    void createSystem();
    void createOrganism();
    ~Controll();
};

#endif // CONTROLL
