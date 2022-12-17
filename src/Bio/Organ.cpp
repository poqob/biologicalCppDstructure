#include "../../include/Bio/Organ.hpp"

// PRIVATE METHODS
void Organ::SearchAndAdd(Tissue *&subNode, const Tissue &newItem)
{
    if (subNode == NULL)
        subNode = new Tissue(newItem);
    else if (newItem.median < subNode->calculateMedian())
        SearchAndAdd(subNode->left, newItem);
    else if (newItem.median > subNode->median)
        SearchAndAdd(subNode->right, newItem);
    else
        SearchAndAdd(subNode->left, newItem);
}
bool Organ::SearchAndDelete(Tissue *&subNode, const Tissue &data)
{
    if (subNode == NULL)
        return false;
    if (subNode->median == data.median)
        return DeleteNode(subNode);
    else if (data.median < subNode->median)
        return SearchAndDelete(subNode->left, data);
    else
        return SearchAndDelete(subNode->right, data);
}
bool Organ::DeleteNode(Tissue *&subNode)
{
    Tissue *DelNode = subNode;

    if (subNode->right == NULL)
        subNode = subNode->left;
    else if (subNode->left == NULL)
        subNode = subNode->right;
    else
    {
        DelNode = subNode->left;
        Tissue *parent = subNode;
        while (DelNode->right != NULL)
        {
            parent = DelNode;
            DelNode = DelNode->right;
        }
        subNode->median = DelNode->median;
        if (parent == subNode)
            subNode->left = DelNode->left;
        else
            parent->right = DelNode->left;
    }
    delete DelNode;
    return true;
}
void Organ::inorder(Tissue *subNode)
{
    if (subNode != NULL)
    {

        inorder(subNode->left);
        cout << subNode->calculateMedian() << " ";
        inorder(subNode->right);
    }
}
void Organ::preorder(Tissue *subNode)
{
    if (subNode != NULL)
    {
        cout << subNode->calculateMedian() << " ";
        preorder(subNode->left);
        preorder(subNode->right);
    }
}
void Organ::postorder(Tissue *subNode)
{
    if (subNode != NULL)
    {
        postorder(subNode->left);
        postorder(subNode->right);
        cout << subNode->calculateMedian() << " ";
    }
}

int Organ::Height(Tissue *subNode)
{
    if (subNode == NULL)
        return -1;
    return 1 + max(Height(subNode->left), Height(subNode->right));
}
void Organ::PrintLevel(Tissue *subNode, int level)
{
    if (subNode == NULL)
        return;
    if (level == 0)
        cout << subNode->calculateMedian() << " ";
    else
    {
        PrintLevel(subNode->left, level - 1);
        PrintLevel(subNode->right, level - 1);
    }
}
bool Organ::Search(Tissue *subNode, const Tissue &item)
{
    if (subNode == NULL)
        return false;
    if (subNode->calculateMedian() == item.median)
        return true;
    if (item.median < subNode->calculateMedian())
        return Search(subNode->left, item);
    else
        return Search(subNode->right, item);
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
        DeleteNode(root);
}
Organ::~Organ()
{
    Clear();
}