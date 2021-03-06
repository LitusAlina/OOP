<<<<<<< HEAD
#include "MyStringClass.h"
using namespace std;

int MyStringClass::strlength(const char* str) {
	int len = 0;
	while (*str) {
		len++;
		str++;
	}
	return len;
}

MyStringClass::MyStringClass() {
	str = nullptr;
	len = 0;
}
//äëÿ ïåðåäà÷è ñòðîêè ïðè ñîçäàíèè îáúåêòà êëàññà
MyStringClass::MyStringClass(const char* string) {
	len = strlength(string);
	this->str = new char[len + 1];
	for (int i = 0; i < len; i++)
		this->str[i] = string[i];
	this->str[len] = '\0';
}
//äëÿ êîïèðîâàíèÿ â äðóãóþ îáëàñòü ïàìÿòè
MyStringClass::MyStringClass(const MyStringClass& value) {
	len = strlength(value.str);
	this->str = new char[len + 1];
	for (int i = 0; i < len; i++)
		this->str[i] = value.str[i];
	this->str[len] = '\0';
}
//äëÿ ïåðåìåùåíèÿ, ÷òîáû íå êîïèðîâàòü ïîýëåìåíòíî
MyStringClass::MyStringClass(MyStringClass&& value) {
	this->len = value.len;
	this->str = value.str;
	value.str = nullptr;
}

MyStringClass::~MyStringClass() {
	delete[] this->str;
}


MyStringClass& MyStringClass::operator =(const MyStringClass& other) {
	if (this != nullptr) delete[] str;
	len = strlength(other.str);
	this->str = new char[len + 1];
	for (int i = 0; i < len; i++)
		this->str[i] = other.str[i];
	this->str[len] = '\0';
	return *this;
}

MyStringClass MyStringClass::operator+(const MyStringClass& other) {
	MyStringClass newString;
	newString.len = strlength(this->str) + strlength(other.str);
	newString.str = new char[strlength(this->str) + strlength(other.str) + 1];
	int i;
	for (i = 0; i < strlength(this->str); i++)
		newString.str[i] = this->str[i];
	for (int j = 0; j < strlength(other.str); j++, i++)
		newString.str[i] = other.str[j];
	newString.str[strlength(this->str) + strlength(other.str)] = '\0';
	return newString;
}

bool MyStringClass::operator ==(const MyStringClass& other) {
	if (this->len == other.len) {
		for (int i = 0; i < this->len; i++) {
			if (this->str[i] != other.str[i]) return false;
		}
		return true;
	}
	return false;
}

bool MyStringClass::operator !=(const MyStringClass& other) {
	return !(this->operator==(other));
}

char& MyStringClass::operator [](int num) {
	return this->str[num];
}

std::ostream& operator <<(std::ostream& out, const MyStringClass& other)
{
	return out << other.str;
}

MyContainerClass::MyContainerClass() {
	this->clv_str++;
	this->text = new MyStringClass[this->clv_str];
}
//äëÿ ïåðåäà÷è ñòðîêè ïðè ñîçäàíèè îáúåêòà êëàññà
MyContainerClass::MyContainerClass(const MyStringClass* string) {
	this->text = new MyStringClass[this->clv_str];
	for (int i = 0; i < this->clv_str; i++)
		this->text[i] = string[i];
}
//äëÿ êîïèðîâàíèÿ â äðóãóþ îáëàñòü ïàìÿòè
MyContainerClass::MyContainerClass(const MyContainerClass& value) {
	this->text = new MyStringClass[this->clv_str];
	for (int i = 0; i < this->clv_str; i++)
		this->text[i] = value.text[i];
}
//äëÿ ïåðåìåùåíèÿ, ÷òîáû íå êîïèðîâàòü ïîýëåìåíòíî
MyContainerClass::MyContainerClass(MyContainerClass&& value) {
	this->text = value.text;
	this->clv_str = value.clv_str;
	value.text = nullptr;
}
MyContainerClass::~MyContainerClass() {
	delete[] this->text;
}
void MyContainerClass::Print() {
	for (int i = 0; i < this->clv_str; i++)
		cout << this->text[i] << endl;
}

MyContainerClass& MyContainerClass::add_string(MyStringClass str1, int position) {
	MyContainerClass newContainer;
	this->clv_str++;
	newContainer.text = new MyStringClass[this->clv_str];
	for (int i = 0; i < this->clv_str; i++) {
		if (i == position) newContainer.text[position] = str1;
		else if (i < position) newContainer.text[i] = this->text[i];
		else if (i > position) newContainer.text[i] = this->text[i - 1];
	}
	this->text = new MyStringClass[this->clv_str];
	for (int i = 0; i < this->clv_str; i++) {
		this->text[i] = newContainer.text[i];
	}
	return *this;
}
MyContainerClass& MyContainerClass::delete_string(int position) {
	MyContainerClass newContainer;
	if (clv_str != 1) {
		newContainer.text = new MyStringClass[this->clv_str - 1];
		for (int i = 0; i < this->clv_str - 1; i++) {
			if (i < position) newContainer.text[i] = this->text[i];
			else newContainer.text[i] = this->text[i + 1];
		}
		this->clv_str--;
		*(this->text) = *(newContainer.text);
		return *this;
	}
	else this->cleaner();
}
MyContainerClass& MyContainerClass::cleaner() {
	MyContainerClass newContainer;
	newContainer.text = new MyStringClass[1];
	newContainer.text[0] = "";
	this->clv_str = 0;
	*(this->text) = *(newContainer.text);
	return *this;
}
MyStringClass MyContainerClass::smallest() {
	if (clv_str > 0) {
		MyStringClass newString;
		int min_len = 32000;
		for (int i = 0; i < this->clv_str; i++) {
			if (text[i].len < min_len) {
				min_len = text[i].len;
				newString = text[i];
			}
		}
		return newString;
	}
	else return "no words";
}
MyStringClass MyContainerClass::acro() {
	if (clv_str > 0) {
		MyStringClass newString;
		newString.len = this->clv_str;
		newString.str = new char[this->clv_str + 1];
		for (int i = 0; i < this->clv_str; i++) {
			newString[i] = text[i][0];
		}
		newString[this->clv_str] = '\0';
		return newString;
	}
	else return "no words";
}
float MyContainerClass::frequence(char ch) {
	if (clv_str > 0) {
		float counter = 0,
			sum = 0;
		for (int i = 0; i < this->clv_str; i++) {
			for (int j = 0; j < text[i].len; j++) {
				if (text[i][j] == ch) counter++;
			}
			sum += text[i].len;
		}
		return counter / sum;
	}
	else return 0;
=======
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

>>>>>>> ab1774ab237622c1e05a98e906a61e039ea04f90
}
	
