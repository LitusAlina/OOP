#include <iostream>
#include <ctime>
#include <stdio.h>
#include <bitset>
using namespace std;
void func1(int* num);
int func2(int y, int z);

int main()
{
	srand(time(NULL));
	int num = rand() % 100 + 1; // 128. -24. 13
	func1(&num);
	cout << endl;
	cout << "num " << num << endl;
	cout << bitset<4>(num) << endl << endl;
	int y = -25;
	int z = -20;
	cout << "y = " << y << endl;
	cout << bitset<4>(y)<< endl;
	cout << "z = " << z << endl;
	cout << bitset<4>(z)<< endl;
	cout << func2(y, z);
}

void func1(int* num) {
	int num1 = *num;
	cout << *num << endl;
	cout << bitset<4>(*num) << endl << endl;
	for (int i = 0; i < sizeof(*num)*8; i++) {
		*num = *num ^ (1 << i);
		if ((num1 & (1 << i)) != 0) break;
	}
}

int func2(int y, int z) {

	int a = sizeof(int) * 4;
	if ((y ^ z) == 0) {
		return 0;
	}
	for (int i = a; i >= 0; i--)
	{
		int Ay = y & (1 << i);
		int Az = z & (1 << i);
	
		 if (i == a && (y ^ z) < 0) {
			if ((Ay != 0) && (Az == 0)) {
				return 1;
			}
			if ((Az != 0) && (Ay == 0)) {
				return -1;
			}
		 }
		else if ((y ^ z) > 0) {
			if ((Ay != 0) && (Az == 0)) {
				return -1;
			}
			if ((Az != 0) && (Ay == 0)) {
				return 1;
			}
		}
	}

}