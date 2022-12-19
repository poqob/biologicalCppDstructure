#if !defined(ORGANISM)
#define ORGANISM

#include "System.hpp"
class Organism
{
private:
    System *head;
    System *FindPrevByPosition(int position);

public:
    Organism(System *);
    Organism();

private:
    int capacity;
    int length;
    void reserve(int newCapacity);
    void insert(int i, const System &item);

public:
    System *items;

public:
    void mutation();
    bool isEmpty() const;
    int size() const;
    void add(const System &item);
    void clear();
    ~Organism();
};

#endif // ORGANISM
