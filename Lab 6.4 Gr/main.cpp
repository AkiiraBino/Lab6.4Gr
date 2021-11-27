#include<iostream>
#include "Conteiner.h"
#include<ctime>

using std::cout;

int main()
{
	srand(time(NULL));
	Conteiner conteiner = Conteiner();
	Conteiner::iterator it;
	int i;
	for (i = 0; i < 10; i++)
	{
		conteiner.add(i, conteiner);
	}

	for (it = conteiner.begin(); it != conteiner.end(); it++)
	{
		*it = rand() % 10;
	}

	for (it = conteiner.begin(); it != conteiner.end(); it++)
	{
		cout << *it << "\n";
	}


	return 0;
}