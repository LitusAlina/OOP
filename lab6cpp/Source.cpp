#include "Header.h"
#include <windows.h>
#include <string>
ofstream fout("Log_file.txt");
using namespace std;

int main()
{
	SYSTEMTIME st;
	GetSystemTime(&st);
	string s = to_string(st.wDay) + "."
		+ to_string(st.wMonth) + "."
		+ to_string(st.wYear);
	Expression* o = new Expression[3];
	try {
		o[0] = Expression(1, 0, 1, 2);
		o[1] = Expression(1, 0, 0, 3);
		o[2] = Expression();
		o[2].SetValue('a', 1);
		o[2].SetValue('b', 0);
		o[2].SetValue('c', 7);
		o[2].SetValue('d', 1);

		for (int i = 0; i < 4; i++) 
		{
			if (i > 2) throw out_of_range("Matching item not found");
			try { cout << o[i].CalculateExpression() << endl; }
			catch (underflow_error except) { fout << except.what() << " " << s << endl; }
			catch (runtime_error except) { fout << except.what() << " " << s << endl; }
		}

	}
	catch (out_of_range except) { fout << except.what() << " " << s << endl; }
	cout << "All items are processed. Program completed" << endl; 
}