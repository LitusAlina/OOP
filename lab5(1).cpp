#include <iostream>
#include <cmath>

using namespace std;

class Figures
{
protected:
	int* x = new int[4];
	int* y = new int[4];

public:
	Figures() {};
	Figures(int* x1, int* y1)
	{
		for (int i = 0; i < 4; i++)
		{
			x[i] = x1[i];
			y[i] = y1[i];
		}
	}
	
	int Perimeter() { return 0; };
	int Square() { return 0; };
};

class Rectangles : public Figures
{
public:

	int length_side(int* x, int* y)
	{

		int x1 = abs(x[0] - x[1]);
		int y1 = abs(y[0] - y[1]);
		int a = sqrt(x1 * x1 + y1 * y1);

		int x2 = abs(x[1] - x[2]);
		int y2 = abs(y[1] - y[2]);
		int b = sqrt(x2 * x2 + y2 * y2);
		
		return a,b;
		
	}
	Rectangles(int* x1, int* y1)
	{ 
		for (int i = 0; i < 4; i++)
		{
			x[i] = x1[i];
			y[i] = y1[i];
		}
	};

	int Square()
	{
		int s = this->length_side(x, y) * this->length_side(x, y);
		cout << "square:\t" << s << endl;
		return s;
	}
	int Perimeter()
	{
		int p = (this->length_side(x, y) + this->length_side(x, y)) * 2;
		cout << "perimeter:\t" << p << endl << endl;
		return p;
	}
	int** Get_Info()
	{
		int** coords = new int* [2];
		for (int i = 0; i < 2; i++) {
			coords[i] = new int[2];
		}
		return coords;
	}
	void Print()
	{
		cout << "Rectangle\n" ;
		cout << endl;
	}
};

class Circle : public Figures
{
private: int r;
public:
	float pi = 3.14;
	Circle(int radius)
	{ 
		r = radius;
	};

	int Square()
	{
		float s = pi * this->r * this->r;
		cout << "square:\t" << s << endl;
		return s;
	}
	int Perimeter()
	{
		float p = 2 * pi * this->r;
		cout << "perimeter:\t" << p << endl;
		return p;
	}
	int** Get_Info()
	{
		int** coords = new int* [2];
		for (int i = 0; i < 2; i++) {
			coords[i] = new int[2];
		}
		return coords;
	}
	void Print()
	{
		cout << "Circle\n";
		cout << endl;
	}
};

int main()
{
	int* x = new int[4] { 0, 0, 2, 2 };
	int* y = new int[4] { 0, 1, 1, 0 };
	Figures f1(x, y);
	Rectangles r1(x, y);
	r1.length_side(x, y);
	r1.Print();
	int s = r1.Square();
	int p = r1.Perimeter();
	int* x1 = new int[4];
	int* y1 = new int[4];
	int** coords = new int* [2];
	for (int i = 0; i < 2; i++) 
	{
		coords[i] = new int[2];
	}
	coords = r1.Get_Info();
	Circle o(3);
	o.Print();
	o.Perimeter();
	o.Square();
	
}
