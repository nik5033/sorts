#include "Array.h"
#include "List.h"
#include "InsertionSort.h"
#include "ShellSort.h"
#include "ISorter.h"
#include <iostream>

using namespace std;

/*
	bef=1: sequence has already been sorted in ascending order
	bef=0: sequence has already been sorted in descending order
	bef=-1: sequence is not sorted

	order=1: sort in ascending order
	order=0: sort in descending order

	sort=1: Shellsort
	sort=0: Insertion sort
*/
bool test_(int bef,int order,int sort)
{
	srand(time(NULL));
	Sequence<double>* seq = new Array<double>;
	seq = new Array<double>;
	ISorter<double>* sorter;
	if(bef==1)
		for (int i = 1; i <= 20000; i++)
			seq->Append(i / 1.0);
	else if(bef==0)
		for (int i = 20000; i > 0; i--)
			seq->Append(i / 1.0);
	else
		for (int i = 20000; i > 0; i--)
			seq->Append((rand()%1000+1)/1.0);
	if (sort==1)
		sorter = new ShellSort<double>;
	else
		sorter = new Insertionsort<double>;
	if (order == 1)
	{
		seq=sorter->sort(seq, [](double first, double second)
		{
			if (first < second)
				return 0;
			else if (first > second)
				return 1;
			else
				return -1;
		});
		return sorter->sort_is_suc_asc(seq);
	}
	else
	{
		seq = sorter->sort(seq, [](double first, double second)
		{
			if (first < second)
				return 1;
			else if (first > second)
				return 0;
			else
				return -1;
		});
		return sorter->sort_is_suc_des(seq);
	}
}

void all_test()
{
	cout << "Program tests\n";

	cout << "The ascending sequence will be sorted in ascending order by Shellsort\n";
	if (test_(1, 1, 1))
		cout << "Test passed successfully\n";
	cout << "The ascending sequence will be sorted in ascending order by Insertion sort\n";
	if (test_(1, 1, 0))
		cout << "Test passed successfully\n";
	cout << "The ascending sequence will be sorted in descending order by Insertion sort\n";
	if (test_(1, 0, 0))
		cout << "Test passed successfully\n";
	cout << "The ascending sequence will be sorted in descending order by Shellsort\n";
	if (test_(1, 0, 1))
		cout << "Test passed successfully\n";


	cout << "The descending sequence will be sorted in ascending order by Shellsort\n";
	if (test_(0, 1, 1))
		cout << "Test passed successfully\n";
	cout << "The descending sequence will be sorted in ascending order by Insertion sort\n";
	if (test_(0, 1, 0))
		cout << "Test passed successfully\n";
	cout << "The descending sequence will be sorted in descending order by Insertion sort\n";
	if (test_(0, 0, 0))
		cout << "Test passed successfully\n";
	cout << "The descending sequence will be sorted in descending order by Shellsort\n";
	if (test_(0, 0, 1))
		cout << "Test passed successfully\n";


	cout << "The random sequence will be sorted in ascending order by Insertion sort\n";
	if (test_(-1, 1, 1))
		cout << "Test passed successfully\n";
	cout << "The random sequence will be sorted in ascending order by Insertion sort\n";
	if (test_(-1, 1, 0))
		cout << "Test passed successfully\n";
	cout << "The random sequence will be sorted in descending order by Insertion sort\n";
	if (test_(-1, 0, 0))
		cout << "Test passed successfully\n";
	cout << "The random sequence will be sorted in descending order by Shellsort\n";
	if (test_(-1, 0, 1))
		cout << "Test passed successfully\n";
}