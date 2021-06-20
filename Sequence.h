#include<iostream>


#ifndef SEQUENCE_H
#define SEQUENCE_H

template <typename T>
class Sequence
{
protected:
	int length;
	int IsEmpty;
public:
	Sequence()
	{
		length = 0;
		IsEmpty = 0;
	}

	int Get_length()
	{
		return this->length;
	}
	int GetIsEmpty()
	{
		return this->IsEmpty;
	}
	
	virtual T Get(int index) = 0;
	virtual T GetFirst() = 0;
	virtual T GetLast() = 0;
	virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) = 0;
	virtual void Append(T item) = 0;
	virtual void Prepend(T item) = 0;
	virtual void InsertAt(int index, T item)=0;
	virtual void Remove(T item) = 0;
	virtual void Swap(int first, int second) = 0;
	void Input()
	{
		int size;
		while (true)
		{
			std::cout << "What size of sequence should be:";
			std::cin >> size;
			if (!std::cin)
			{
				std::cout << "Please,try again\n";
				std::cin.clear();
				while (std::cin.get() != '\n');
			}
			else
				break;
		}
		T item;
		for (int i = 0; i < size; i++)
		{
			while (true)
			{
				std::cout << "Enter item:";
				std::cin >> item;
				if (!std::cin)
				{
					std::cout << "Please,try again\n";
					std::cin.clear();
					while (std::cin.get() != '\n');
				}
				else
					break;
			}
			Append(item);
		}
	}
	void Output()
	{
		for (int i = 0; i < this->length; i++)
			std::cout << i + 1 << " item:" << Get(i) <<std::endl;
		std::cout << std::endl;
	}
};


#endif 
