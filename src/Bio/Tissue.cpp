#include "../../include/Bio/Tissue.hpp"

Tissue::Tissue()
{
    length = 0;
    capacity = 0;
    items = NULL;
}

Tissue::Tissue(const Tissue &right)
{
    length = 0;
    items = new Cell[right.length];
    for (int i = 0; i < right.size(); i++)
    {
        insert(i, right.items[i]);
    }
    capacity = length;
}
Tissue::~Tissue()
{
    if (items != NULL)
        delete[] items;
}

int Tissue::size() const
{
    return length;
}
bool Tissue::isEmpty() const
{
    return size() == 0;
}

void Tissue::insert(int i, const Cell &item)
{
    if (i < 0 || i > length)
        throw "Index Out Of Bound";
    if (length >= capacity)
        reserve(max(1, 2 * capacity));
    for (int j = length - 1; j >= i; j--)
        items[j + 1] = items[j];
    items[i] = item;
    length++;
}

void Tissue::add(const Cell &item)
{
    insert(length, item);
}

void Tissue::clear()
{
    length = 0;
}

void Tissue::reserve(int newCapacity)
{
    if (capacity >= newCapacity)
        return;
    Cell *tmp = new Cell[newCapacity];
    for (int j = 0; j < length; j++)
        tmp[j] = items[j];
    if (items != NULL)
        delete[] items;
    items = tmp;
    capacity = newCapacity;
}

void Tissue::tissueWriter()
{
    for (int i = 0; i < length; i++)
    {
        cout << items[i].dnaLenght << " ";
    }
}

void Tissue::sort()
{
    // Radix *radix = new Radix(items, length);
}