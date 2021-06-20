#include <string>
#include <ctime>
#include <random>
#include "test.h"

using namespace std;

template<typename T>
class Interface
{
public:
	void consol();
	int _cin(int data)
	{
		while (true)
		{
			cin >> data;
			if (!cin)
				cout << "Please, try input!!\n";
			else
				break;
		}
		return data;
	}
	
	void Analysis(Sequence<T>* seq, Sequence<T>* (*inp)(Sequence<T>*))
	{
		ISorter<T>* sorter = new ShellSort<T>;
		seq=(*inp)(seq);
		seq = sorter->sort(seq, [](T first, T second)
		{
			if (first < second)
				return 0;
			else if (first > second)
				return 1;
			else
				return -1;
		});
		double time_shell = sorter->Get_time();
		sorter = new Insertionsort<T>;
		seq= (*inp)(seq);
		seq = sorter->sort(seq, [](T first, T second)
		{
			if (first < second)
				return 0;
			else if (first > second)
				return 1;
			else
				return -1;
		});
		double time_ins = sorter->Get_time();

		cout << "Shellsort's time:" << time_shell << endl;
		cout << "Insertion sort's time:" << time_ins << endl;
	}
};

template<typename T>
void Interface<T>::consol()
{
	ISorter<double>* sorter = NULL;
	srand((unsigned)time(NULL));
	Sequence<T>* seq=NULL;
	cout << "Write \"help\" to see the list of commands\n";
	while (true)
	{
		string command;
		bool exict_com = false;
		cout << "Your command:";
		getline(cin, command);
		if (command == "exit")
			break;
		if (command == "input seq array")
		{
			exict_com = true;
			seq = new Array<T>;
			seq->Input();
		}
		if (command == "analysis")
		{
			exict_com = true;
			cout << "Sequence is sorted in ascending:\n";
			Analysis(seq, [](Sequence<T>* seq)
			{
				seq = new Array<T>;
				for (int i = 0; i < 10000; i++)
					seq->Append(i);
				return seq;
			});
			cout << "Sequence is sorted in descending:\n";
			Analysis(seq, [](Sequence<T>* seq)
			{
				seq = new Array<T>;
				for (int i = 10000; i > 0; i--)
					seq->Append(i);
				return seq;
			});
			cout << "Sequence is not sorted:\n";
			Analysis(seq, [](Sequence<T>* seq)
			{
				seq = new Array<T>;
				for (int i = 0; i < 10000; i++)
					seq->Append((rand() % 10000) / 1.0 + 1.0);
				return seq;
			});
		}
		if (command == "input seq list")
		{
			exict_com = true;
			seq = new List<T>;
			seq->Input();
		}
		if (command == "auto input seq array")
		{
			exict_com = true;
			seq = new Array<T>;
			std::cout << "What size:";
			int size=0;
			size=_cin(size);
			for (int i = 0; i <size; i++)
				seq->Append((rand() % 10000)/1.0+ 1.0);
		}

		if (command == "auto input seq list")
		{
			exict_com = true;
			seq = new List<T>;
			std::cout << "What size:";
			int size = 0;
			size = _cin(size);
			for (int i = 0; i < size; i++)
				seq->Append((rand() % 10000) / 1.0 + 1.0);
		}

		if (command == "sort shell asc")
		{
			exict_com = true;
			if (seq->Get_length() == 0)
			{
				cout << "Sequence is empty or sequence not found\n";
				continue;
			}
			sorter =new ShellSort<T>;
			seq=sorter->sort(seq, [](T first, T second)
			{
				if (first < second)
					return 0;
				else if (first > second)
					return 1;
				else
					return -1;
			});
		}
		if (command == "sort shell des")
		{
			exict_com = true;
			if (seq == NULL)
			{
				cout << "Sequence is empty or sequence not found\n";
				continue;
			}
			sorter = new ShellSort<T>;
			seq = sorter->sort(seq, [](T first, T second)
			{
				if (first < second)
					return 1;
				else if (first > second)
					return 0;
				else
					return -1;
			});
		}
		if (command == "sort ins asc")
		{
			exict_com = true;
			if (seq == NULL)
			{
				cout << "Sequence is empty or sequence not found\n";
				continue;
			}
			sorter = new Insertionsort<T>;
			seq = sorter->sort(seq, [](T first, T second)
			{
				if (first < second)
					return 0;
				else if (first > second)
					return 1;
				else
					return -1;
			});
		}
		if (command == "sort ins des")
		{
			exict_com = true;
			if (seq == NULL)
			{
				cout << "Sequence is empty or sequence not found\n";
				continue;
			}
			sorter = new Insertionsort<T>;
			seq = sorter->sort(seq, [](T first, T second)
			{
				if (first < second)
					return 1;
				else if (first > second)
					return 0;
				else
					return -1;
			});
		}
		if (command == "output seq")
		{ 
			exict_com = true;
			if (seq == NULL)
			{
				cout << "Sequence is empty or sequence not found\n";
				continue;
			}
			seq->Output();
		}

		if (command == "test")
		{
			exict_com = true;
			all_test();
		}

		if (command == "help")
		{
			exict_com = true;
			cout << "exit-shut down the program\n";
			cout << "input seq array-input the sequence like array\n";
			cout << "input seq list-input the sequence like list\n";
			cout << "auto input seq array-automatic input the sequence like array\n";
			cout << "auto input seq list-automatic input the sequence like list\n";
			cout << "sort shell asc-sort in ascending order the sequence by shellsort\n";
			cout << "sort shell des-sort in descending order the sequence by shellsort\n";
			cout << "sort ins asc-sort in ascending order the sequence by insertion sort\n";
			cout << "sort ins des-sort in descending order the sequence by insertion sort\n";
			cout << "output seq-output the sequence\n";
			cout << "test-test of program\n";
			cout << "analysis-analysis of sort algorithms\n";
		}
		if (command == "check sort")
		{
			exict_com = true;
			if (sorter->sort_is_suc_asc(seq))
				cout << "Sequence is sorted\n";
			else
				cout << "Sequence is not sorted\n";
		}
		if (!exict_com)
			cout << "Wrong command! Please, rewrite command\n";
	}
}
