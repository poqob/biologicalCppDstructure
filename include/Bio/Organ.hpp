#if !defined(ORGAN)
#define ORGAN
#include "../BST/BST.hpp"
#include "Tissue.hpp"
class Organ
{
public:
    Bst *bst;
    Organ *next;
    Organ(Bst *);
    Organ(Bst *, Organ *);
    Organ();
    ~Organ();
};
#endif // ORGAN
