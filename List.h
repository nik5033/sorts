#include "Sequence.h"
#include "Node.h"
#include <cstdlib>
#include<iostream>

#ifndef List_H
#define List_H

template <typename T>
class List :public Sequence<T>
{
private:
	Node<T>* beginList;
	Node<T>* endList;
public:
	List()
	{
		this->IsEmpty = 0;
		this->length = 0;
		beginList = nullptr;
		endList = nullptr;
	}
	List(List<T>* other) :Sequence<T>()
	{
		for (int i = 0; i < other->length; i++)
			Append(other->Get(i));
	}
	void Append(T item);
	void Prepend(T item);
	T GetFirst();
	T GetLast();
	T Get(int index);
	void Remove(T item);
	List<T>* GetSubsequence(int startIndex, int endIndex);
	void InsertAt(int index, T item);
	void Swap(int first, int second);
	Node<T>* Get_beginList()
	{
		return this->beginList;
	}
	Node<T>* Get_endList()
	{
		return this->endList;
	}
};

template <typename T>
void List<T>::Append(T item) 
{
	if (this->IsEmpty == 0)
	{
		beginList = new Node<T>;
		beginList->SetData(item);
		endList = beginList;
		this->IsEmpty = 1;
	}
	else
	{
		Node<T>* NewNode = new Node<T>();
		NewNode->SetData(item);
		endList->SetNext(NewNode);
		NewNode->SetPrev(endList);
		endList = NewNode;
	}
	this->length++;
}

template <typename T>
void List<T>::Prepend(T item)
{
	if (this->IsEmpty == 0)
	{
		beginList = new Node<T>;
		beginList->SetData(item);
		endList = beginList;
		this->IsEmpty = 1;
	}
	else
	{
		Node<T>* NewNode = new Node<T>;
		NewNode->SetData(item);
		beginList->SetPrev(NewNode);
		NewNode->SetNext(beginList);
		beginList = NewNode;
	}
	this->length++;
}

template <typename T> 
T List<T>::GetFirst()
{
	if (this->IsEmpty == 0)
		throw std::length_error("List is empty");
	return beginList->GetData();
}

template <typename T>
T List<T>::GetLast()
{
	if (this->IsEmpty == 0)
		throw std::length_error("List is empty");
	return endList->GetData();
}

template <typename T>
T List<T>::Get(int index)
{
	if (this->IsEmpty == 0)
		throw std::length_error("List is empty");
	if (this->length <= index || index < 0)
		throw std::out_of_range("Index is incorrect");
	Node<T>* current = new Node<T>;
	current = beginList;
	for (int i = 0; i != index; i++)
		current = current->GetNext();
	return current->GetData();
}

template <typename T>
void List<T>:: Remove(T item)
{
	if (this->IsEmpty == 0)
		throw std::length_error("List is empty");
	Node <T>* current = beginList->GetNext();
	while (current->GetNext() != nullptr)
	{
		if (current->GetData() == item)
		{
			if (current->GetPrev() != nullptr && current->GetNext() != nullptr)
			{
				current->GetNext()->SetPrev(current->GetPrev());
				current->GetPrev()->SetNext(current->GetNext());
			}
			else if (current->GetPrev() != nullptr)
				current->GetPrev()->SetNext(nullptr);
			else if (current->GetNext() != nullptr)
				current->GetNext()->SetPrev(nullptr);
			delete current;
			this->length--;
			if (this->length == 0)
				this->IsEmpty = 0;
			break;
		}
		current = current->GetNext();
	}
}

template<typename T>
List<T>* List<T>:: GetSubsequence(int startIndex, int endIndex)
{
	if (this->IsEmpty == 0)
		throw std::length_error("List is empty");
	if (startIndex > endIndex || endIndex >= this->length|| startIndex < 0|| endIndex < 0)
		throw std::out_of_range("Indexes are incorrect");
	List<T>* SubSeq=new List<T>;
	Node <T>* current = beginList;
	for (int i = 0; i < startIndex; i++)
		current = current->GetNext();
	for (int i = startIndex; i <= endIndex; i++)
	{
		SubSeq->Append(current->GetData());
		current = current->GetNext();
	}
	return SubSeq;
}

template <typename T>
void List<T>::InsertAt(int index, T item)
{
	if (this->IsEmpty == 0 && index!=0)
		throw std::length_error("List is empty");
	if (index >= this->length||index<0)
		throw std::out_of_range("Index is incorrect");
	if (this->length == 0 && index == 0)
		Append(item);
	else
	{
		Node <T>* current = this->beginList->GetNext();
		for (int i = 1; i < index; i++)
			current = current->GetNext();
		Node<T>* NewNode=new Node<T>;
		NewNode->SetData(item);
		current->GetNext()->SetPrev(NewNode);
		current->SetNext(NewNode);
	}
}

template<typename T>
void List<T>::Swap(int first, int second)
{
	if (this->IsEmpty == 0)
		throw std::length_error("List is empty");
	if (first >= this->length || first < 0 || second < 0||second>=this->length)
		throw std::out_of_range("Indexes are incorrect");
	if (first < second)
	{
		Node <T>* current = this->beginList;
		for (int i = 0; i < first; i++)
			current = current->GetNext();
		T tmp = Get(first);
		current->SetData(Get(second));
		for (int i = first; i < second; i++)
			current = current->GetNext();
		current->SetData(tmp);
	}
	else if(second < first)
	{
		Node <T>* current = this->beginList;
		for (int i = 0; i < second ;i++)
			current = current->GetNext();
		T tmp = Get(second);
		current->SetData(Get(first));
		for (int i = second; i < first; i++)
			current = current->GetNext();
		current->SetData(tmp);
	}
}

#endif