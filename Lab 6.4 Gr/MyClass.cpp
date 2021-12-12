#include "MyClass.h"
#include"iostream"

using std::cout;


void MyClass::info()
{
	cout << "Высота: " << height << " Ширина: " << width << " Площадь: " << area << "\n";
}

int MyClass::areaComp()
{
	area = width * height;
	return area;
}

MyClass MyClass::changeElement(int h, int w)
{
	height = h;
	width = w + 5;
	area = areaComp();
	return *this;
}

MyClass::MyClass()
{
	height = 0;
	width = 0;
	area = areaComp();
};

bool operator <(MyClass value, MyClass value2)
{
	if (value.area < value2.area)
	{
		return true;
	}
	else return false;
}

bool operator ==(MyClass value, MyClass value2)
{
	if (value.area == value2.area)
	{
		return true;
	}
	else return false;
}

std::ostream& operator << (std::ostream & out, MyClass value)
{
	out << "Высота: " << value.height << " Ширина: " << value.width << " Площадь: " << value.area << "\n";
	return out;
}