#include "../../include/LinkedSystemList/LinkedSystemList.hpp"

System *LinkedSystemList::FindPrevByPosition(int position)
{
    if (position < 0 || position > size())
        throw "Index out of range";
    int index = 0;
    System *itr = head;
    for (; itr != NULL; itr = itr->next, index++)
    {
        if (position == index)
            return itr;
    }
    return NULL;
}

LinkedSystemList::LinkedSystemList()
{
    head = new System();
}

bool LinkedSystemList::isEmpty() const
{
    return head->next == NULL;
}

int LinkedSystemList::size() const
{
    int length = 0;
    for (System *itr = head->next; itr != NULL; itr = itr->next)
    {
        length++;
    }
    return length;
}
System LinkedSystemList::first()
{
    if (isEmpty())
        throw "Empty list";
    return *head->next;
}
System LinkedSystemList::last()
{
    if (isEmpty())
        throw "Empty list";
    return *FindPrevByPosition(size());
}

void LinkedSystemList::add(const System &item)
{
    insert(size(), item);
}
void LinkedSystemList::insert(int index, const System &item)
{
    System *prev = FindPrevByPosition(index);
    prev->next = new System(item.organs, prev->next); // LOOK AFTER
}
void LinkedSystemList::remove(const System &item)
{
    int position = indexOf(item);
    removeAt(position);
}

void LinkedSystemList::removeAt(int index)
{
    if (isEmpty())
        throw "Empty list";
    System *del;
    System *prev = FindPrevByPosition(index);
    del = prev->next;
    prev->next = prev->next->next;

    delete del;
}
bool LinkedSystemList::find(const System &item) const
{
    for (System *itr = head->next; itr != NULL; itr = itr->next)
    {
        if (itr == &item)
            return true;
    }
    return false;
}
int LinkedSystemList::indexOf(const System &item)
{
    int index = 0;
    for (System *itr = head->next; itr != NULL; itr = itr->next, index++)
    {
        if (itr == &item)
            return index;
    }
    throw "Index out of range";
}
ostream &operator<<(ostream &screen, LinkedSystemList &right)
{
    if (right.isEmpty())
        screen << "Empty list";
    else
    {
        for (System *itr = right.head->next; itr != NULL; itr = itr->next)
        {
            screen << itr->organs[0]->bst->root->median << " ";
        }
    }
    return screen;
}
void LinkedSystemList::clear()
{
    while (!isEmpty())
        removeAt(0);
}
LinkedSystemList::~LinkedSystemList()
{
    clear();
    delete head;
}