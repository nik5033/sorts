#include "ISorter.h"
#include <ctime>

template<typename T>
class ShellSort :public ISorter<T>
{
public:
	Sequence<T>* sort(Sequence<T>* seq, int(*cmp)(T, T));
};

template<typename T>
Sequence<T>* ShellSort<T>:: sort(Sequence<T>* seq, int (*cmp)(T, T))
{
	double start = clock();

	int Length = seq->Get_length();
	int step = Length / 2;
	while (step > 0)
	{
		for (int i = 0; i < Length - step; i++)
		{
			int j = i;
			while (j >= 0 && cmp(seq->Get(j),seq->Get(j+step))==1)
			{
				seq->Swap(j, j + step);
				j--;
			}
		}
		step = step / 2;
	}

	double end = clock();

	this->time = end - start;

	return seq;
}