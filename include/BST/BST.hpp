#if !defined(BST)
#define BST
#include "../Bio/Tissue.hpp"
class Bst
{
private:
    int tissueCounter = 0;
    Tissue *tissuesAfterMutation;
    int counter = 0;

public:
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
    void balanceStatue(Tissue *);

public:
    bool isTreeBalanced = true;

public:
    Bst();
    void mutation();
    bool isEmpty() const;
    void Add(const Tissue &newItem);
    void Delete(const Tissue &data);
    void inorderMutate();
    void preorder();
    void postorderTreeToArray();
    void levelorder();
    int Height();
    bool Search(const Tissue &item);
    void Clear();
    bool isTreeBalancedF();
    ~Bst();
};

#endif // BST
