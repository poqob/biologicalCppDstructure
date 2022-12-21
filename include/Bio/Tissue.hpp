#if !defined(TISSUE)
#define TISSUE

#include "Cell.hpp"
#include "../radixsort/Radix2.hpp"
#include "iostream"
using namespace std;
class Tissue
{
private:
    int capacity;
    void reserve(int newCapacity);
    void insert(int i, const Cell &item);

public:
    Tissue *right = NULL;
    Tissue *left = NULL;

    int length;
    int median;
    Cell *items;

public:
    Tissue();
    void mutation();
    Tissue(const Tissue &right);
    Tissue(Tissue *rightB, Tissue *leftB);
    Tissue(const Tissue &right, Tissue *rightB, Tissue *leftB);
    bool isEmpty() const;
    int size() const;
    void add(const Cell &item);
    void clear();
    void tissueWriter();
    void sort();
    int calculateMedian();
    ~Tissue();
};
#endif // TISSUE
