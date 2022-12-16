#if !defined(TISSUE)
#define TISSUE

#include "Cell.hpp"
#include "iostream"
using namespace std;
class Tissue
{
private:
    int capacity;
    void reserve(int newCapacity);

public:
    Cell *items;
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
