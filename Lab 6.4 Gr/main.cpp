#include<iostream>
#include "Conteiner.h"
#include "MyClass.h"
#include<ctime>

using std::cout;

int MAXIMUM = 10;

int funcRand()
{
	int value;
	value = rand() % 5;
	return value;
}

void usefloat()
{
	cout << "___________________________________________" << "\n";
	cout << "Это тип данных float" << "\n";
	cout << "___________________________________________" << "\n";
	Conteiner<float> conteiner;
	Conteiner<float>::iterator it;
	int i;
	for (i = 0; i < MAXIMUM; i++)
	{
		conteiner.add(i, conteiner);
	}

	for (it = conteiner.begin(); it != conteiner.end(); it++)
	{
		*it = (float)rand() / 10;
	}

	conteiner.info();

	for (it = conteiner.begin(); it < MAXIMUM; it++)
	{
		cout << *it << "\n";
	}

}

void useint()
{
	cout << "___________________________________________" << "\n";
	cout << "Это тип данных int" << "\n";
	cout << "___________________________________________" << "\n";
	Conteiner<int> conteiner;
	Conteiner<int>::iterator it;
	int i;
	for (i = 0; i < MAXIMUM; i++)
	{
		conteiner.add(i, conteiner);
	}

	for (it = conteiner.begin(); it != conteiner.end(); it++)
	{
		*it = rand() % 10;
	}

	conteiner.info();

	for (it = conteiner.begin(); it < MAXIMUM; it++)
	{
		cout << *it << "\n";
	}
}

void useMyClass()
{
	cout << "___________________________________________" << "\n";
	cout << "Это мой класс" << "\n";
	cout << "___________________________________________" << "\n";
	Conteiner<MyClass> conteiner;
	Conteiner<MyClass>::iterator it;
	int i;
	for (i = 0; i < MAXIMUM; i++)
	{
		conteiner.add(funcRand(), conteiner);
	}
	conteiner.info();

	for (it = conteiner.begin(); it != conteiner.end(); it++)
	{
		*it = funcRand();
	}

	for (it = conteiner.begin(); it < MAXIMUM; it++)
	{
		cout << *it << "\n";
	}
	
}

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	usefloat();
	useint();
	useMyClass();
	return 0;
}