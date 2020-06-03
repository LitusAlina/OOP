#include "MyStringClass.h"
#include <stdio.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");

	MyStringClass str("I am student of KPI");
	//MyStringClass str2("World");
	//cout << str;

	MyContainerClass t;
	t.text[0] = "student";
	cout << endl;
	t.Print();
	cout << endl;
	MyContainerClass t1;
	t.add_string("of ", 1);
	t.add_string("KPI", 2);
	cout << "___" << endl;
	t.Print();
	cout << "___" << endl;
	
	t.delete_string(2);
	cout << "___" << endl;
	t.Print();
	cout << "___" << endl;
	
	MyStringClass s;
	s = t.smallest();
	cout << s;
	cout << endl;
	
	s = t.acro();
	cout << s;
	cout << endl;
	float x = t.frequence('t');
	cout << x;

	cout << endl;
	t.cleaner();
	cout << "_________" << endl;
	t.Print();
	cout << "_________" << endl;
	cout << endl;

	return 0;
}