#if !defined(TISSUE)
#define TISSUE

#include "Cell.hpp"
#include "iostream"
#include "../radixsort/Radix.hpp"
using namespace std;
class Tissue
{
private:
    Cell *items;
    int capacity;
    void reserve(int newCapacity);

public:
    int length;
    Tissue(const Tissue &right);
    Tissue();
    bool isEmpty() const;
    int size() const;
    void insert(int i, const Cell &item);
    void add(const Cell &item);
    void clear();
    void tissueWriter();
    void sort();
    ~Tissue(); // TODO
};
#endif // TISSUE
