#pragma once
#include <iostream>
#include <math.h>
#include <stdexcept>
#include <fstream>
using namespace std;

class Expression
{
private:
	float a, b, c, d;

public:
	Expression();
	Expression(float, float, float, float);
	Expression(const Expression&);

	float CalculateExpression();
	void SetValue(char, float);
	float GetValue(char);
};