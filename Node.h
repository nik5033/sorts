#ifndef Node_H
#define Node_H

template <typename T>
class Node
{
private:
	Node<T>* prev;
	Node<T>* next;
	T value;
public:
	Node()
	{
		prev = nullptr;
		next = nullptr;
	}
	void SetPrev(Node<T>* prev)
	{
		this->prev = prev;
	}
	void SetNext(Node<T>* next)
	{
		this->next = next;
	}
	Node<T>* GetPrev()
	{
		return this->prev;
	}
	Node<T>* GetNext()
	{
		return this->next;
	}
	T GetData()
	{
		return this->value;
	}
	void SetData(T value)
	{
		this->value = value;
	}
};

#endif
