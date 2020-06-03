#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>

using namespace std;

class myClass 
{
private: 
	int rows = 4;
	int cols = 4;

	int** arr = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}

	/*static const int n = 4;
	int arr[n][n] = {
		{2, 8, 4, 6},
		{5, 3, 1, 7},
		{9, 6, 3, 1},
		{8, 7, 2, 4}
	};*/

public:
	/*int* data;
	myClass(int size,int size1) {
		this->Size = size;
		this->Size1 = size1;
		this->data = new int arr[size];

		for (int i = 0; i < size; i++)
		{
			for (int k = 0; k < size1; k++) 
			{
				data[i][k] = i + k;
			}
		}
	}*/
		
	/*void Print() 
	{
		for (int q = 0; q < n; q++)
		{
			for (int w = 0; w < n; w++)
			{
				cout << arr[q][w] << "\t";
			}
			cout << endl;
		}
	}*/
	
};

int main() 
{
	setlocale(LC_ALL, "Russian");
	
	
	

	return 0;
}