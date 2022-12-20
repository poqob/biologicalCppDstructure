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
Organ::~Organ()
{
}