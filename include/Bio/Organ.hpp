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
    // status: organ can accept tissue data type from out.
    // adds datas to tissue tree according to tissue's median value.

    // TODO: max tissue limit will be codded. like max 20 organ can accept.
    // Callout: may controll class send tissues as block of 20s. ~(or)~
    // we collect tissues together in an seperate array as 20s then apply adding operation each of them ??
    // TODO: delete unneccesary methods.
    // TODO: don't forget mutation status.
private:
    Tissue *root;

private:
    void SearchAndAdd(Tissue *&subNode, const Tissue &newItem);
    bool SearchAndDelete(Tissue *&subNode, const Tissue &data);
    bool DeleteTissue(Tissue *&subNode);
    void inorder(Tissue *subNode);
    void preorder(Tissue *subNode);
    void postorder(Tissue *subNode);
    int Height(Tissue *subNode);
    void PrintLevel(Tissue *subNode, int level);
    bool Search(Tissue *subNode, const Tissue &item);

public:
    bool isTreeBalanced = true;

public:
    Organ();
    void balanceStatue(Tissue *);
    bool isEmpty() const;
    void Add(const Tissue &newItem);
    void Delete(const Tissue &data);
    void inorder();
    void preorder();
    void postorder();
    void levelorder();
    int Height();
    bool Search(const Tissue &item);
    void Clear();
    bool isTreeBalancedF();
    ~Organ();
};

#endif // ORGAN
