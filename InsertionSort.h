#include "ISorter.h"
#include <ctime>

template<typename T>
class Insertionsort :public ISorter<T>
{
public:
	Sequence<T>* sort(Sequence<T>* seq, int(*cmp)(T, T));
};

template<typename T>
Sequence<T>* Insertionsort<T>:: sort(Sequence<T>* seq, int(*cmp)(T, T))
{
	double start = clock();

	int Length = seq->Get_length();
	for (int i = 1; i < Length; i++)
	{
		int j = i;
		while (j > 0 && cmp(seq->Get(j - 1), seq->Get(j)) == 1)
		{
			seq->Swap(j, j - 1);
			j--;
		}
	}

	double end = clock();

	this->time = end - start;

	return seq;
}