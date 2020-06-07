#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class String
{
public:
	char your_str[9];
	int YourString(char your_string[]) 
	{
		for (int i = 0; i < 9; i++) 
		{
			your_str[i] = your_string[i];
		}
	}
	int str_len() 
	{
		return 0; 
	}
	int char_replace()
	{ 
		return 0;
	}
};

class Characters : public String
{
private:
	string s;

public:
	
	int strlength(string str) {
		int len = str.length();
		
		return len;
	}

	int str_len()
	{
		return strlength(s);
	}

	Characters(string s1)
	{
		s = s1;
	}

	string char_replace()
	{
		char* arr = new char[strlength(s)];
		for (int i = 0, j = 0; i < strlength(s); i++, j++)
		{
			if (s[i] != '#')  arr[j] = s[i];
			else
			{
				arr[j] = '!';
				arr[j+1] = '!';
				j++;
			}
		}
		s = arr;
		return s;
	}
	void Print()
	{
		cout << s;
		cout << endl;
		cout << strlength(s);
		
	}
	};

int main()
{
	Characters c("a#ghd21#i");
	c.Print();
	c.str_len();
	c.char_replace();
	c.str_len();
	c.Print();
}