#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>

using namespace std;

class Section 
{
private: 
	int begX, endX, begY, endY;
	int x, y;

public:
	Section() 
	{
		begX = 0;
		endX = 0;
		x = 0;
		begY = 0;
		endY = 0;
		y = 0;
	}

	Section(int valuebegX, int valueendX, int valuebegY, int valueendY)
	{
		begX = valuebegX;
		endX = valueendX;
		begY = valuebegY;
		endY = valueendY;
		x = endX - begX;
		y = endY - begY;
	}
	int GetbegX() 
	{
		return begX;
	}
	int GetendX()
	{
		return endX;
	}
	int GetbegY()
	{
		return begY;
	}
	int GetendY()
	{
		return endY;
	}
	int Getx() 
	{
		return x;
	}
	int Gety()
	{
		return y;
	}

	Section(const Section & other) 
	{
		//конструктор копирования
		this->x = other.x;
		this->y = other.y;
	}

	Section & operator = (const Section & other) 
	{
		this->x = other.x;
		this->y = other.y;
		this->endX = other.endX;
		this->begX = other.begX;
	}
	Section  operator - (const Section & other)
	{
		Section temp1;
		temp1.x = this->endX - other.begX;
		temp1.y = this->endY - other.begY;
		return temp1;
	}
	Section  operator + (const Section & other)
	{
		Section temp2;
		temp2.x = this->x + other.x;
		temp2.y = this->y + other.y;
		return temp2;
	}
	Section  operator * (int a)
	{
		Section temp3;
		temp3.x = this->x * a;
		temp3.y = this->y * a;
		return temp3;
	}
	int Length() 
	{
		float result;
		result = sqrt(x*x +y*y);
		cout << result<< endl;
		return result;
	}
	void Print()
	{
		cout << "L\t" << x << "\t" << y;
		cout << endl;
	}
	
};
int main() 
{
	Section L2(3, 8, 4, 16);
	Section L3(1, 4, 5, 9);
	Section L1 = L2 + L3;
	L1.Print();
	L2.Print();
	L3.Print();
	L1.Length();
	L2.Length();
	L3.Length();

	Section L4 = L3 * 2;
	L4.Print();
	L4.Length();
	
	return 0;
}