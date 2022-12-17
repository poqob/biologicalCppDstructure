#ifndef RADIX2
#define RADIX2

#include "Queue2.hpp"
#include "../Bio/Tissue.hpp"

#include <cmath>

class Radix2
{
private:
	Cell *cells;
	int length;
	Queuetwo **queues;
	int maxStep;

	int MaxStepNumber();
	int StepCount(int);
	int *QueueCurrentLengths();

public:
	Radix2(Cell *, int);
	int len();
	Cell *Sort();
	~Radix2();
};

#endif
