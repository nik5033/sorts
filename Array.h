#include "Sequence.h"
#include <cstdlib>
#include<iostream>


#ifndef Array_H
#define Array_H

template <typename T> 
class Array :public Sequence<T>
{
private:
	T* items;
public:
	Array() : Sequence<T>()
	{ };
	Array(Array<T>* other) :Sequence<T>()
	{
		for (int i = 0; i < other->length; i++)
			Append(other->Get(i));
	};
	void Append(T item);
	void Prepend(T item);
	T GetFirst();
	T GetLast();
	T Get(int index);
	void Remove(T item);
	Array<T>* GetSubsequence(int startIndex, int endIndex);
	void InsertAt(int index, T item);
	T* Get_items()
	{
		return this->items;
	}
	void Swap(int first, int second);
};

template <typename T>
void Array<T>:: Append(T item)
{
	this->length++;
	this->items = (T*)realloc(this->items, this->length * sizeof(T));
	if (this->IsEmpty == 0)
	{
		this->items[0] = item;
		this->IsEmpty = 1;
	}
	else
		this->items[this->length - 1] = item;
}

template <typename T>
void Array<T>::Prepend(T item)
{
	this->length++;
	if (this->IsEmpty == 0)
	{
		this->items = (T*)realloc(this->items, sizeof(T));
		this->items[0] = item;
		this->length++;
		this->IsEmpty = 1;
	}
	else
	{
		for (int i = 0; i < this->length-1; i++)
		{
			T term;
			term = item;
			item = this->items[i];
			this->items[i] = term;
		}
		this->items = (T*)realloc(this->items, this->length * sizeof(T));
		this->items[this->length - 1] = item;
	}
}

template <typename T>
T Array<T>::GetFirst()
{
	if (this->IsEmpty == 0)
		throw std::length_error("Array is empty");
	return this->items[0];
}

template <typename T>
T Array<T>::GetLast()
{
	if (this->IsEmpty == 0)
		throw std::length_error("Array is empty");
	return this->items[this->length-1];
}

template <typename T>
T Array<T>::Get(int index)
{
	if (this->IsEmpty == 0)
		throw std::length_error("Array is empty");
	if (index >= this->length|| index < 0)
		throw std::out_of_range("Index is incorrect");
	return this->items[index];
}

template <typename T>
void Array<T>::Remove(T item)
{
	if (this->IsEmpty == 0)
		throw std::length_error("Array is empty");
	int i = 0;
	while (i< this->length)
	{
		if (this->items[i] == item)
		{
			for (int j = i; j < this->length - 1; j++)
				this->items[j] = this->items[j + 1];
			this->length--;
			this->items = (T*)realloc(this->items, this->length * sizeof(T));
			break;
		}
	}
}

template <typename T>
Array<T>* Array<T>::GetSubsequence(int startIndex, int endIndex)
{
	if (this->IsEmpty == 0)
		throw std::length_error("Array is empty");
	if (startIndex > endIndex || endIndex >= this->length || startIndex < 0 || endIndex < 0)
		throw std::out_of_range("Indexes are incorrect");;
	Array<T>* Subseq = new Array<T>;
	for (int i = startIndex; i <= endIndex; i++)
		Subseq->Append(this->items[i]);
	return Subseq;
}

template <typename T>
void Array<T>::InsertAt(int index, T item)
{
	if (this->IsEmpty == 0 && index != 0)
		throw std::length_error("Array is empty");
	if (index >= this->length || index < 0)
		throw std::out_of_range("Index is incorrect");
	if (this->IsEmpty == 0 && index == 0)
		Append(item);
	for (int i = index; i < this->length; i++)
	{
		T term;
		term = item;
		item = this->items[i];
		this->items[i] = term;
	}
	this->length++;
	this->items = (T*)realloc(this->items, this->length * sizeof(T));
	this->items[this->length - 1] = item;
}

template<typename T>
void Array<T>::Swap(int first, int second)
{
	if (this->IsEmpty == 0)
		throw std::length_error("List is empty");
	if (first >= this->length || first < 0 || second < 0 || second >= this->length)
		throw std::out_of_range("Indexes are incorrect");
	T tmp = this->items[first];
	this->items[first] = this->items[second];
	this->items[second] = tmp;
}

#endif 