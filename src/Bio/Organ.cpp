#include "../../include/Bio/Organ.hpp"

Organ::Organ()
{
}

Organ::Organ(Bst *bst)
{
    this->bst = bst;
}

Organ::Organ(Bst *bst, Organ *next)
{
    this->bst = bst;
    this->next = next;
}
void Organ::mutation()
{
    if (bst->root->median % 50 == 0)
    {
        bst->mutation();
    }
}
Organ::~Organ()
{
    delete bst;
}