#if !defined(LINKEDSYSTEMLIST)
#define LINKEDSYSTEMLIST
#include "iostream"
#include "../Bio/System.hpp"
using namespace std;
class LinkedSystemList
{
private:
    System *FindPrevByPosition(int position);

public:
    System *head;
    LinkedSystemList();
    bool isEmpty() const;
    int size() const;
    System first();
    System last();
    void add(const System &item);
    void insert(int index, const System &item);
    void remove(const System &item);
    void removeAt(int index);
    bool find(const System &item) const;
    int indexOf(const System &item);
    friend ostream &operator<<(ostream &screen, LinkedSystemList &right);
    void clear();
    ~LinkedSystemList();
};

#endif // LINKEDSYSTEMLIST
