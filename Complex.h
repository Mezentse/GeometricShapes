#pragma once
#include <iostream>

using namespace std;

class Complex
{
public:
	Complex();
	Complex(double Re, double Im);
	Complex(const Complex& other);

	double GetRe();
	void SetRe(double Re);
	double GetIm();
	void SetIm(double Im);

	Complex operator +(Complex b);
	Complex operator -(Complex b);
	Complex operator *(Complex b);
	Complex operator /(Complex b);
	Complex& operator =(const Complex& b);

	bool operator ==(Complex b);

	friend ostream& operator<< (ostream& out, Complex b);
	friend istream& operator>> (istream& in, Complex& b);

	double Module();
	Complex IntPow(int m);
	Complex DoublePow(int m, int n);
	void CoutTrigonom();

protected:
	double Re;
	double Im;
};