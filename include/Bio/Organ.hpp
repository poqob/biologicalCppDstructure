#if !defined(ORGAN)
#define ORGAN

#include "../dataStructures/BST/include/BST.hpp"
#include "Tissue.hpp"

/*
organ looks like to have tree structure.
to gain that structure tissue ought to have node properities.

*/
class Organ
{
private:
    // Tissue *tissues = new Tissue[20]; //@ that line will come as parameter.

public:
    Organ();
    ~Organ();
};

#endif // ORGAN
