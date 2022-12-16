#include "../../include/radixsort/Queue2.hpp"

void Queuetwo::clear()
{
    front = 0;
    back = -1;
    length = 0;
}

void Queuetwo::reserve(int newCapacity)
{
    Cell *temp = new Cell[newCapacity];
    for (int i = front, j = 0; j < length; j++)
    {
        temp[j].dnaLenght = items[i].dnaLenght;
        i = (i + 1) % capacity;
    }
    capacity = newCapacity;
    delete[] items;
    items = temp;
    front = 0;
    back = length - 1;
}

Queuetwo::Queuetwo()
{
    capacity = 1;
    front = 0;
    back = -1;
    length = 0;
    items = new Cell[capacity];
}

int Queuetwo::count() const
{
    return length;
}
bool Queuetwo::isEmpty() const
{
    if (length == 0)
        return true;
    return false;
}

const Cell &Queuetwo::peek()
{
    if (isEmpty())
        throw "Empty List";
    return items[front];
}

void Queuetwo::enqueue(const Cell &item)
{
    if (length == capacity)
        reserve(2 * capacity);
    back = (back + 1) % capacity;
    items[back] = item;
    length++;
}

void Queuetwo::dequeue()
{
    if (isEmpty())
        throw "Empty List";
    front = (front + 1) % capacity;
    length--;
}

Queuetwo::~Queuetwo()
{
    delete[] items;
}