#pragma once
#include<iostream>

class MyClass
{
protected:
	int height;
	int width;
	int area;

public:
	MyClass();
	void info();
	MyClass changeElement(int h, int w);
	int areaComp();
	friend bool operator <(MyClass value, MyClass value2);
	friend bool operator >(MyClass value, MyClass value2);
	friend bool operator ==(MyClass value, MyClass value2);
	friend std::ostream& operator << (std::ostream& out, MyClass value);
	MyClass operator =(int value)
	{
		return changeElement(value, value);
	}
	int operator =(MyClass value)
	{
		return value.area;
	}
	operator int() const
	{
		return area;
	}


};

