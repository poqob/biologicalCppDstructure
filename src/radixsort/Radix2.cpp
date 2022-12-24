#include "../../include/radixsort/Radix2.hpp"

int Radix2::MaxStepNumber()
{
	int max = 0;
	for (int i = 0; i < length; i++)
	{
		if (StepCount(cells[i].dnaLenght) > max)
			max = StepCount(cells[i].dnaLenght);
	}
	return max;
}
int Radix2::StepCount(int number)
{
	number = abs(number);
	int basamak = 0;
	while (number > 0)
	{
		basamak++;
		number /= 10;
	}
	return basamak;
}
Radix2::Radix2(Cell *cells, int length)
{
	this->cells = new Cell[length];
	this->length = length;
	for (int i = 0; i < length; i++)
	{
		this->cells[i] = cells[i];
	}
	queues = new Queuetwo *[10];
	for (int j = 0; j < 10; j++)
	{
		queues[j] = new Queuetwo();
	}
	maxStep = MaxStepNumber();
}
int *Radix2::QueueCurrentLengths()
{
	int *lengths = new int[10];
	for (int i = 0; i < 10; i++)
	{
		lengths[i] = queues[i]->count();
	}
	return lengths;
}

int Radix2::power(int e)
{
	int result = 1;
	for (int i = 0; i < e; i++)
		result *= 10;
	return result;
}

Cell *Radix2::Sort()
{
	int numberIndex = 0;
	// read from array once and add to queues
	for (; numberIndex < length; numberIndex++)
	{
		int stepValue = cells[numberIndex].dnaLenght % 10;
		Cell cell = cells[numberIndex];
		queues[stepValue]->enqueue(cell);
	}

	// i starting from 1 because of first digit processed
	for (int i = 1; i < maxStep; i++)
	{
		// get the current length in all queues
		int *qlengths = QueueCurrentLengths();
		for (int index = 0; index < 10; index++)
		{
			int len = qlengths[index];
			for (; len > 0; len--)
			{
				int number = queues[index]->peek().dnaLenght;
				queues[index]->dequeue();
				int stepValue = (number / power(i)) % 10;
				queues[stepValue]->enqueue(number);
			}
		}
		delete[] qlengths;
	}
	Cell *ordered = new Cell[length];
	numberIndex = 0;
	for (int index = 0; index < 10; index++)
	{
		while (!queues[index]->isEmpty())
		{
			int number = queues[index]->peek().dnaLenght;
			ordered[numberIndex++].dnaLenght = number;
			queues[index]->dequeue();
		}
	}

	return ordered;
}

int Radix2::len()
{
	return length;
}
Radix2::~Radix2()
{
	delete[] cells;
	for (int i = 0; i < 10; i++)
		delete queues[i];
	delete[] queues;
}
