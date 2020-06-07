#include <iostream>

using namespace std;

int sum(int arr[3][4]);
void Print(int arr[3][4]);

int main()
{
	int result;
	//void printmass();
	int massive[3][4] = { {10,9,98,65},
						  {8,-9,-4,6},
						  {15,6,78,-8} 
	};
	void(*print)(int arr[3][4]);
	print = Print;
	print(massive);
	cout << endl;
	int(*summa)(int arr[3][4]);
	summa = sum;
	result = summa(massive);
	
	
}
int sum(int arr[3][4])
{
	const int a = 3;
	int summ[a] = { 0,0,0 };
	int i = 0;
	for (int q = 0; q < 3; q++)
	{
		for (int w = 0; w < 4; w++)
		{
			summ[i] += arr[q][w];
		}
		cout << summ[i] << endl;
		i++;
	}

	return 0;
}
void Print(int arr[3][4])
{
	for (int q = 0; q < 3; q++)
	{
		for (int w = 0; w < 4; w++)
		{
			cout << arr[q][w] << "\t";
		}
		cout << endl;
	}
}

