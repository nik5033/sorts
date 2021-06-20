#include "Sequence.h"

#ifndef ISorter_H
#define ISorter_H

template <typename T>
class ISorter
{
protected:
	double time;
public:
	ISorter()
	{
		this->time = 0.0;
	}
	virtual Sequence<T>* sort(Sequence<T>* seq, int(*cmp)(T, T)) = 0;
	bool sort_is_suc_asc(Sequence<T>* seq);
	bool sort_is_suc_des(Sequence<T>* seq);
	double Get_time()
	{
		return this->time;
	}
};

template<typename T>
bool ISorter<T>::sort_is_suc_asc(Sequence<T>* seq)
{
	for (int i = 1; i < seq->Get_length(); i++)
		if (seq->Get(i - 1) > seq->Get(i))
			return false;
	return true;
}

template<typename T>
bool ISorter<T>::sort_is_suc_des(Sequence<T>* seq)
{
	for (int i = 1; i < seq->Get_length(); i++)
		if (seq->Get(i - 1) < seq->Get(i))
			return false;
	return true;
}

#endif 
