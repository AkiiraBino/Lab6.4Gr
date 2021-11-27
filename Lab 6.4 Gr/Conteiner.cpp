#include "Conteiner.h"

Conteiner::Conteiner()
{
	size = 0;
	data[size] = 0;
}

void Conteiner::sort_data()
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

void Conteiner::add(int value, Conteiner conteiner)
{
	int i;
	if (size < MAX)
	{
		if (size != 0)
		{
			size++;
			data[size] = value;
		}
		else
		{
			data[size] = value;
			size++;
		}
	}

	conteiner.sort_data();
}

void Conteiner::del(int value)
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

void Conteiner::info()
{
	std::cout << data << "\n";
}

Conteiner::iterator::iterator()
{
	index = 0;
	pdata = NULL;
}

Conteiner::iterator::iterator(int i, Conteiner* p)
{
	index = i;
	pdata = p;
}

Conteiner::iterator Conteiner::iterator::operator++()
{
	index++;
	return *this;
}

Conteiner::iterator Conteiner::iterator::operator ++(int value)
{
	index++;
	return *this;
}

Conteiner::iterator Conteiner::iterator::operator--()
{
	index--;
	return *this;
}

Conteiner::iterator Conteiner::iterator::operator --(int value)
{
	index++;
	return *this;
}

bool Conteiner::iterator::operator ==(Conteiner::iterator value)
{
	return (index == value.index && pdata == value.pdata);
}

bool Conteiner::iterator::operator !=(Conteiner::iterator value)
{
	return (index != value.index || pdata != value.pdata);
}

int& Conteiner::iterator::operator *()
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

Conteiner::iterator Conteiner::begin()
{
	return iterator(0, this);
}

Conteiner::iterator Conteiner::end()
{
	return iterator(size, this);
}
