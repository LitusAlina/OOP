#include "Header.h"
Expression::Expression() {
	a = 0;
	b = 0;
	c = 0;
	d = 0;
}
Expression::Expression(float a1, float b1, float c1, float d1) {
	a = a1;
	b = b1;
	c = c1;
	d = d1;
}
Expression::Expression(const Expression& other) {
	this->a = other.a;
	this->b = other.b;
	this->c = other.c;
	this->d = other.d;
}

float Expression::CalculateExpression() {
	if (4*b-c <= 0) throw underflow_error("Logarithm is not exist");
	if (b+c/d-1 == 0) throw runtime_error("Division by 0");
	if (d == 0) throw runtime_error("Division by 0");
	return (log10f(4*b-c)*a/(b+c/d-1));
}
void Expression::SetValue(char ch, float value)
{
	switch (ch)
	{
	case 'a': a = value;
	case 'b': b = value;
	case 'c': c = value;
	case 'd': d = value;
	default: break;
	}
}
float Expression::GetValue(char ch)
{
	switch (ch)
	{
	case 'a': return a;
	case 'b': return b;
	case 'c': return c;
	case 'd': return d;
	default: return 0;
	}
}