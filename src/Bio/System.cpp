#include "../../include/Bio/System.hpp"
Organ *System::FindPrevByPosition(int position)
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

System::System()
{
    head = new Organ();
}

bool System::isEmpty() const
{
    return head->next == NULL;
}

int System::size() const
{
    int length = 0;
    for (Organ *itr = head->next; itr != NULL; itr = itr->next)
    {
        length++;
    }
    return length;
}
Organ System::first()
{
    if (isEmpty())
        throw "Empty list";
    return *head->next;
}
Organ System::last()
{
    if (isEmpty())
        throw "Empty list";
    return *FindPrevByPosition(size());
}

void System::add(const Organ &item)
{
    insert(size(), item);
}
void System::insert(int index, const Organ &item)
{
    Organ *prev = FindPrevByPosition(index);
    prev->next = new Organ(item.root, prev->next);
}
void System::remove(const Organ &item)
{
    int position = indexOf(item);
    removeAt(position);
}

void System::removeAt(int index)
{
    if (isEmpty())
        throw "Empty list";
    Organ *del;
    Organ *prev = FindPrevByPosition(index);
    del = prev->next;
    prev->next = prev->next->next;

    delete del;
}
bool System::find(const Organ &item) const
{
    for (Organ *itr = head->next; itr != NULL; itr = itr->next)
    {
        if (itr == &item)
            return true;
    }
    return false;
}
int System::indexOf(const Organ &item)
{
    int index = 0;
    for (Organ *itr = head->next; itr != NULL; itr = itr->next, index++)
    {
        if (itr == &item)
            return index;
    }
    throw "Index out of range";
}
ostream &operator<<(ostream &screen, System &right)
{
    if (right.isEmpty())
        screen << "Empty list";
    else
    {
        for (Organ *itr = right.head->next; itr != NULL; itr = itr->next)
        {
            screen << itr->root->median << " ";
        }
    }
    return screen;
}
void System::clear()
{
    while (!isEmpty())
        removeAt(0);
}
System::~System()
{
    clear();
    delete head;
}