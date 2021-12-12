#ifndef STORE_H
#define STORE_H

#include<iostream>
#include "MyClass.h"
#include <typeinfo>

const int MAX = 1000;

template<typename T>
class Conteiner
{
private:
	T data[MAX];
	int size;

public:
	Conteiner()
	{
		size = 0;
	}
	void add(int value, Conteiner<T> conteiner)
	{
		if (size < MAX)
		{
			if (size != -1)
			{
				data[size] = value;
				size++;
			}
			conteiner.sort_data();
		}
		else
		{
			exit(EXIT_FAILURE);
		}
	}
	void del(int value)
	{
		int i;
		if (value <= size)
		{
			for (i = value; i < size; i++)
			{
				data[i] = data[i + 1];
			}
			size--;
		}
	}
	void info()
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << data[i] << " ";
		}
		std::cout << "\n";
	}
	void sort_data()
	{
		int i, j, value;
		for (i = 0; i < size; i++)
		{
			for (j = size; j != i; j--)
			{
				if (data[j] < data[i])
				{
					value = data[i];
					data[i] = data[j];
					data[j] = value;
				}
			}
		}
	}
	class iterator
	{
	private:
		int index;
		Conteiner<T>* pdata;

	public:
		iterator()
		{
			index = 0;
			pdata = NULL;
		}
		iterator(int i, Conteiner<T>* p)
		{
			index = i;
			pdata = p;
		}
		iterator operator++()
		{
			index++;
			if (index > pdata->size)
			{
				index = 0;
			}
			if (index - 1 != -1)
			{
				while (pdata->data[index] == pdata->data[index - 1])
				{
					index++;
				}
			}
			return *this;
		}
		iterator operator ++(int value)
		{
			index++;
			if (index > pdata->size)
			{
				index = 0;
			}
			if (index - 1 != -1)
			{
				while (pdata->data[index] == pdata->data[index - 1])
				{
					index++;
				}
			}
			return *this;
		}
		iterator operator--()
		{
			index--;
			if (index > pdata->size)
			{
				index = 0;
			}
			if (index - 1 != -1)
			{
				while (pdata->data[index] == pdata->data[index - 1])
				{
					index--;
				}
			}
			return *this;
		}
		iterator operator --(int value)
		{
			index--;
			if (index > pdata->size)
			{
				index = 0;
			}
			if (index - 1 != -1)
			{
				while (pdata->data[index] == pdata->data[index - 1])
				{
					index--;
				}
			}
			return *this;
		}
		bool operator !=(iterator value)
		{
			return (index != value.index || pdata != value.pdata);
		}
		bool operator <(int num)
		{
			return (index < num);
		}
		bool operator ==(iterator value)
		{
			return (index == value.index && pdata == value.pdata);
		}
		T& operator *()
		{
			int i;
			if (pdata)
			{
				pdata->sort_data();
				return pdata->data[index];
			}
			else
			{
				throw 0;
			}
		}

	};
	iterator begin()
	{
		return iterator(0, this);
	}
	iterator end()
	{
		return iterator(size, this);
	}
};

#endif STORE_H