#ifndef QUEUE2
#define QUEUE2
#include <iostream>
#include "../Bio/Cell.hpp"
using namespace std;
class Queuetwo
{
private:
	int front;
	int back;
	int capacity;
	int length;
	Cell *items;
	void reserve(int newCapacity);

public:
	Queuetwo();
	void clear();
	int count() const;
	bool isEmpty() const;
	const Cell &peek();
	void enqueue(const Cell &item);
	void dequeue();
	~Queuetwo();
};
#endif
