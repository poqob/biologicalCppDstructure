#if !defined(SYSTEM)
#define SYSTEM

#include "Organ.hpp"
class System
{
public:
    Organ *organs;

    int counter = 0; // it's provide us to manipulate same indexes simultaneousl organs and balances.
    // eger bir organ mutasyona ugramissa hemen akabinde denge kontrolu yapılsın.
    // agac dengesiz ise agacın denge durumu degistirilsin-bununla beraber agacın denge durumu ilgili agac indexindeki balances dengeler listesinde de degissin.
    // TODO: every biological form of bio foolder will have mutation function.
    // that function will call it's component's mutation function until it reaches to cell.

public:
    System(Organ *);
    void mutation(); // it will trigger sub biological form's mutation method.
    ~System();
};

#endif // SYSTEM
