#if !defined(ORGAN)
#define ORGAN
#include "../BST/BST.hpp"
#include "Tissue.hpp"
class Organ
{
public:
    // fields
    Bst *bst;
    Organ *next;
    // methods
    Organ();
    Organ(Bst *);
    Organ(Bst *, Organ *);
    void mutation();
    ~Organ();
};
#endif // ORGAN
