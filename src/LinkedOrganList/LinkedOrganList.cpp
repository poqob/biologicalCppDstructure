#include "../../include/LinkedOrganList/LinkedList.hpp"

Organ *LinkedOrganList::FindPrevByPosition(int position)
{
    if (position < 0 || position > size())
        throw "Index out of range";
    int index = 0;
    Organ *itr = head;
    for (; itr != NULL; itr = itr->next, index++)
    {
        if (position == index)
            return itr;
    }
    return NULL;
}

LinkedOrganList::LinkedOrganList()
{
    head = new Organ();
}

bool LinkedOrganList::isEmpty() const
{
    return head->next == NULL;
}

int LinkedOrganList::size() const
{
    int length = 0;
    for (Organ *itr = head->next; itr != NULL; itr = itr->next)
    {
        length++;
    }
    return length;
}
Organ LinkedOrganList::first()
{
    if (isEmpty())
        throw "Empty list";
    return *head->next;
}
Organ LinkedOrganList::last()
{
    if (isEmpty())
        throw "Empty list";
    return *FindPrevByPosition(size());
}

void LinkedOrganList::add(const Organ &item)
{
    insert(size(), item);
}
void LinkedOrganList::insert(int index, const Organ &item)
{
    Organ *prev = FindPrevByPosition(index);
    prev->next = new Organ(item.bst, prev->next); // LOOK AFTER
}
void LinkedOrganList::remove(const Organ &item)
{
    int position = indexOf(item);
    removeAt(position);
}

void LinkedOrganList::removeAt(int index)
{
    if (isEmpty())
        throw "Empty list";
    Organ *del;
    Organ *prev = FindPrevByPosition(index);
    del = prev->next;
    prev->next = prev->next->next;

    delete del;
}
bool LinkedOrganList::find(const Organ &item) const
{
    for (Organ *itr = head->next; itr != NULL; itr = itr->next)
    {
        if (itr == &item)
            return true;
    }
    return false;
}
int LinkedOrganList::indexOf(const Organ &item)
{
    int index = 0;
    for (Organ *itr = head->next; itr != NULL; itr = itr->next, index++)
    {
        if (itr == &item)
            return index;
    }
    throw "Index out of range";
}
ostream &operator<<(ostream &screen, LinkedOrganList &right)
{
    if (right.isEmpty())
        screen << "Empty list";
    else
    {
        for (Organ *itr = right.head->next; itr != NULL; itr = itr->next)
        {
            screen << itr->bst->root->median << " ";
        }
    }
    return screen;
}
void LinkedOrganList::clear()
{
    while (!isEmpty())
        removeAt(0);
}
LinkedOrganList::~LinkedOrganList()
{
    clear();
    delete head;
}