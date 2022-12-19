#include "../../include/Bio/Organism.hpp"

Organism::Organism()
{
    length = 0;
    capacity = 0;
    items = NULL;
}

Organism::~Organism()
{
    if (items != NULL)
        delete[] items;
}

int Organism::size() const
{
    return length;
}
bool Organism::isEmpty() const
{
    return size() == 0;
}

void Organism::insert(int i, const System &item)
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

void Organism::add(const System &item)
{
    insert(length, item);
}

void Organism::clear()
{
    length = 0;
}

void Organism::reserve(int newCapacity)
{
    if (capacity >= newCapacity)
        return;
    System *tmp = new System[newCapacity];
    for (int j = 0; j < length; j++)
        tmp[j] = items[j];
    if (items != NULL)
        delete[] items;
    items = tmp;
    capacity = newCapacity;
}