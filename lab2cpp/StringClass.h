#pragma once
#include <iostream>

class MyStringClass {
public:
	char* str;
	int len;
	int strlength(const char*);

	MyStringClass();
	MyStringClass(const char*);
	MyStringClass(const MyStringClass&);
	MyStringClass(MyStringClass&&);
	~MyStringClass();

	MyStringClass& operator =(const MyStringClass&);
	MyStringClass operator+(const MyStringClass&);

	bool operator ==(const MyStringClass&);
	bool operator !=(const MyStringClass&);
	char& operator [](int);
	friend std::ostream& operator <<(std::ostream&, const MyStringClass&);
};

class MyContainerClass : public MyStringClass {

public:
	MyStringClass* text;
	int clv_str = 0;

	MyContainerClass();
	MyContainerClass(const MyStringClass*);
	MyContainerClass(const MyContainerClass&);
	MyContainerClass(MyContainerClass&&);
	~MyContainerClass();
	void Print();

	MyContainerClass& add_string(MyStringClass, int);
	MyContainerClass& delete_string(int position);
	MyContainerClass& cleaner();
	MyStringClass smallest();
	MyStringClass acro();
	float frequence(char);

};

std::ostream& operator <<(std::ostream& out, const MyStringClass& other);