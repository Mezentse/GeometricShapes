#include "Complex.h"
#include <math.h>

using namespace std;

Complex::Complex()
{
	Im = 0;
	Re = 0;
}

Complex::Complex(double Re, double Im)
{
	this->Im = Im;
	this->Re = Re;
}

Complex::Complex(const Complex& other)
{
	Im = other.Im;
	Re = other.Re;
}

double Complex::GetRe()
{
	return Re;
}

void Complex::SetRe(double Re)
{
	this->Re = Re;
}

double Complex::GetIm()
{
	return Im;
}

void Complex::SetIm(double im)
{
	this->Im = Im;
}

Complex Complex::operator+(Complex b)
{
	return Complex(this->Re + b.Re, this->Im + b.Im);
}

Complex Complex::operator-(Complex b)
{
	return Complex(this->Re - b.Re, this->Im - b.Im);
}

Complex Complex::operator*(Complex b)
{
	return Complex((this->Re * b.Re) - (this->Im * b.Im), (this->Im * b.Re) + (this->Re * b.Im));
}

Complex Complex::operator/(Complex b)
{
	this->Re = (this->Re * b.Re + this->Im * b.Im) / (pow(b.Re, 2) + pow(b.Im, 2));
	this->Im = (this->Im * b.Re - this->Re * b.Im) / (pow(b.Re, 2) + pow(b.Im, 2));
	return Complex(this->Re, this->Im);
}

Complex& Complex::operator=(const Complex& b)
{
	this->Re = b.Re;
	this->Im = b.Im;
	return *this;
}

bool Complex::operator==(Complex b)
{
	if (this->Re == b.Re and this->Im == b.Im) return true;
	else return false;
}

ostream& operator<<(ostream& out, Complex b)
{
	out << b.Re << (b.Im >= 0 ? " + " : " - ") << abs(b.Im) << "i" << endl;
	return out;
}

istream& operator>>(istream& in, Complex& b)
{
	in >> b.Re;
	in >> b.Im;
	return in;
}

double Complex::Module()
{
	return sqrt(pow(this->Re, 2) + pow(this->Im, 2));
}

Complex Complex::IntPow(int m)
{
	double x = atan2(this->Im, this->Re);
	return Complex(pow(this->Module(), m) * cos(m * x), pow(this->Module(), m) * sin(m * x));
}

Complex Root(int n, Complex a)
{
	double x = atan2(a.GetIm(), a.GetRe());

	return Complex(pow(a.Module(), (double)1 / n) * cos((x + 2 * acos(-1)) / n), pow(a.Module(), (double)1 / n) * sin((x + 2 * acos(-1)) / n));
}

Complex Complex::DoublePow(int m, int n)
{
	return Root(n, this->IntPow(m));
}

void Complex::CoutTrigonom()
{
	double x = atan2(this->GetIm(), this->GetRe());
	cout << this->Module() << "(cos(" << x << ") + i*sin(" << x << ")" << endl;
}