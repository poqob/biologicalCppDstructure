#include "../../include/BST/BST.hpp"

// PRIVATE METHODS
void Bst::SearchAndAdd(Tissue *&sub, const Tissue &newItem)
{
    if (sub == NULL)
        sub = new Tissue(newItem);
    else if (newItem.median < sub->calculateMedian())
        SearchAndAdd(sub->left, newItem);
    else if (newItem.median > sub->median)
        SearchAndAdd(sub->right, newItem);
    else
        SearchAndAdd(sub->left, newItem);
}
bool Bst::SearchAndDelete(Tissue *&sub, const Tissue &data)
{
    if (sub == NULL)
        return false;
    if (sub->median == data.median)
        return DeleteTissue(sub);
    else if (data.median < sub->median)
        return SearchAndDelete(sub->left, data);
    else
        return SearchAndDelete(sub->right, data);
}
bool Bst::DeleteTissue(Tissue *&sub)
{
    Tissue *DelTissue = sub;

    if (sub->right == NULL)
        sub = sub->left;
    else if (sub->left == NULL)
        sub = sub->right;
    else
    {
        DelTissue = sub->left;
        Tissue *parent = sub;
        while (DelTissue->right != NULL)
        {
            parent = DelTissue;
            DelTissue = DelTissue->right;
        }
        sub->median = DelTissue->median;
        if (parent == sub)
            sub->left = DelTissue->left;
        else
            parent->right = DelTissue->left;
    }
    delete DelTissue;
    return true;
}
void Bst::inorder(Tissue *sub)
{
    if (sub != NULL)
    {

        inorder(sub->left);
        cout << sub->calculateMedian() << " ";
        inorder(sub->right);
    }
}
void Bst::preorder(Tissue *sub)
{
    if (sub != NULL)
    {
        cout << sub->calculateMedian() << " ";
        preorder(sub->left);
        preorder(sub->right);
    }
}
void Bst::postorder(Tissue *sub)
{
    if (sub != NULL)
    {
        postorder(sub->left);
        postorder(sub->right);
        cout << sub->calculateMedian() << " ";
        tissuesAfterMutation[++tissueCounter] = *sub;
    }
}

int Bst::Height(Tissue *sub)
{
    if (sub == NULL)
        return -1;
    return 1 + max(Height(sub->left), Height(sub->right));
}
void Bst::PrintLevel(Tissue *sub, int level)
{
    if (sub == NULL)
        return;
    if (level == 0)
        cout << sub->calculateMedian() << " ";
    else
    {
        PrintLevel(sub->left, level - 1);
        PrintLevel(sub->right, level - 1);
    }
}
bool Bst::Search(Tissue *sub, const Tissue &item)
{
    if (sub == NULL)
        return false;
    if (sub->calculateMedian() == item.median)
        return true;
    if (item.median < sub->calculateMedian())
        return Search(sub->left, item);
    else
        return Search(sub->right, item);
}

// PUBLIC METHODS
Bst::Bst()
{
    root = NULL;
}

bool Bst::isEmpty() const
{
    return root == NULL;
}
void Bst::Add(const Tissue &newItem)
{
    SearchAndAdd(root, newItem);
}
void Bst::Delete(const Tissue &data)
{
    if (SearchAndDelete(root, data) == false)
        throw "Item not found.";
}
void Bst::inorder()
{
    inorder(root);
}
void Bst::preorder()
{
    preorder(root);
}
void Bst::postorder()
{
    postorder(root);
}
void Bst::levelorder()
{
    int h = Height();
    for (int level = 0; level <= h; level++)
    {
        PrintLevel(root, level);
    }
}
int Bst::Height()
{
    return Height(root);
}
bool Bst::Search(const Tissue &item)
{
    return Search(root, item);
}
void Bst::Clear()
{
    while (!isEmpty())
        DeleteTissue(root);
}

void Bst::balanceStatue(Tissue *od)
{
    while (od != NULL)
    {
        if (abs(Height(od->left) - Height(od->right)) > 1)
        {
            isTreeBalanced = false;
            break;
        }
        else
        {
            balanceStatue(od->left);
            balanceStatue(od->right);
            break;
        }
    }
}

bool Bst::isTreeBalancedF()
{
    balanceStatue(root);
    return isTreeBalanced;
}

void Bst::mutation()
{
    // TODO: if mutation will became true...
    if (root->median % 50 == 0)
    {
    }
}

Bst::~Bst()
{
    Clear();
}