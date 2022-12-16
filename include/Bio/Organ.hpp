#if !defined(ORGAN)
#define ORGAN

#include "../dataStructures/BST/include/BST.hpp"
#include "Tissue.hpp"
class Organ
{
private:
    Tissue *tissues = new Tissue[20];

    BST<Tissue> *bst = new BST<Tissue>(); // agaca gonderilen veriler dokunun orta degerine göre agacta konumlanacaktır.
    // clear the tree.
    // add mutatedtree's (which is an array) values to bst tree.

public:
    Organ();
    ~Organ();
};

#endif // ORGAN
