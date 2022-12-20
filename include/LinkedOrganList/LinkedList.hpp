#if !defined(LINKEDORGANLIST)
#define LINKEDORGANLIST
#include "iostream"
#include "../Bio/Organ.hpp"
class LinkedOrganList
{
private:
    Organ *head;
    Organ *FindPrevByPosition(int position);

public:
    LinkedOrganList();
    bool isEmpty() const;
    int size() const;
    Organ first();
    Organ last();
    void add(const Organ &item);
    void insert(int index, const Organ &item);
    void remove(const Organ &item);
    void removeAt(int index);
    bool find(const Organ &item) const;
    int indexOf(const Organ &item);
    friend ostream &operator<<(ostream &screen, LinkedOrganList &right);
    void clear();
    ~LinkedOrganList();
};

#endif // LINKEDORGANLIST
