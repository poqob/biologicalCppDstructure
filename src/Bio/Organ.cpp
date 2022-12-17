#include "../../include/Bio/Organ.hpp"

// PRIVATE METHODS
void Organ::SearchAndAdd(Tissue *&sub, const Tissue &newItem)
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
bool Organ::SearchAndDelete(Tissue *&sub, const Tissue &data)
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
bool Organ::DeleteTissue(Tissue *&sub)
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
void Organ::inorder(Tissue *sub)
{
    if (sub != NULL)
    {

        inorder(sub->left);
        cout << sub->calculateMedian() << " ";
        inorder(sub->right);
    }
}
void Organ::preorder(Tissue *sub)
{
    if (sub != NULL)
    {
        cout << sub->calculateMedian() << " ";
        preorder(sub->left);
        preorder(sub->right);
    }
}
void Organ::postorder(Tissue *sub)
{
    if (sub != NULL)
    {
        postorder(sub->left);
        postorder(sub->right);
        cout << sub->calculateMedian() << " ";
    }
}

int Organ::Height(Tissue *sub)
{
    if (sub == NULL)
        return -1;
    return 1 + max(Height(sub->left), Height(sub->right));
}
void Organ::PrintLevel(Tissue *sub, int level)
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
bool Organ::Search(Tissue *sub, const Tissue &item)
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
Organ::Organ()
{
    root = NULL;
}
bool Organ::isEmpty() const
{
    return root == NULL;
}
void Organ::Add(const Tissue &newItem)
{
    SearchAndAdd(root, newItem);
}
void Organ::Delete(const Tissue &data)
{
    if (SearchAndDelete(root, data) == false)
        throw "Item not found.";
}
void Organ::inorder()
{
    inorder(root);
}
void Organ::preorder()
{
    preorder(root);
}
void Organ::postorder()
{
    postorder(root);
}
void Organ::levelorder()
{
    int h = Height();
    for (int level = 0; level <= h; level++)
    {
        PrintLevel(root, level);
    }
}
int Organ::Height()
{
    return Height(root);
}
bool Organ::Search(const Tissue &item)
{
    return Search(root, item);
}
void Organ::Clear()
{
    while (!isEmpty())
        DeleteTissue(root);
}

void Organ::balanceStatue(Tissue *od)
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

bool Organ::isTreeBalancedF()
{
    balanceStatue(root);
    return isTreeBalanced;
}

Organ::~Organ()
{
    Clear();
}