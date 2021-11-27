#ifndef STORE_H
#define STORE_H

#include<iostream>

const int MAX = 1000;

class Conteiner
{
private:
	int data[MAX];
	int size;

public:
	Conteiner();
	void add(int value, Conteiner conteiner);
	void del(int value);
	void info();
	void sort_data();
	class iterator
	{
	private:
		int index;
		Conteiner* pdata;

	public:
		iterator();
		iterator(int i, Conteiner* p);
		Conteiner::iterator operator ++();
		Conteiner::iterator operator ++(int value);
		Conteiner::iterator operator --();
		Conteiner::iterator operator --(int value);
		bool operator !=(Conteiner::iterator value);
		bool operator ==(Conteiner::iterator value);
		int& operator*();
	};
	Conteiner::iterator begin();
	Conteiner::iterator end();
};

#endif STORE_H