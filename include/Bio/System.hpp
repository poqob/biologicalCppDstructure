#if !defined(SYSTEM)
#define SYSTEM

#include "Organ.hpp"
class System
{
private:
    Organ *head;
    Organ *FindPrevByPosition(int position);

public:
    System();
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
    friend ostream &operator<<(ostream &screen, System &right);
    void clear();
    ~System();
};

#endif // SYSTEM
