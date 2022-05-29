#include "String.h"
#include <math.h>

using namespace std;

int TString::setLen(const char* _str) {
	int count = 0;
	for (int i = 0; _str[i] != '\0'; i++)
	{
		count++;
	}
	n = count;

	return n;
}

TString::TString()
{
	n = 0;
	mas = nullptr;
}

TString::TString(const char* _mas)
{
	if (mas != nullptr || mas != 0)
	{
		delete[] mas;
	}

	n = strlen(_mas);
	mas = new char[n + 1];
	mas[n] = '\0';
	for (int i = 0; i < n; i++)
	{
		mas[i] = _mas[i];

	}
}

TString::TString(const TString& other)
{
	n = other.n;
	mas = new char[n + 1];
	mas[n] = '\0';
	for (int i = 0; other.mas[i] != '\0'; i++)
	{
		mas[i] = other.mas[i];
	}
}

TString::~TString()
{
	n = 0;
	delete this->mas;
}

char* TString::GetStr()
{
	return this->mas;
}

TString TString::operator+(const TString& b)
{
	TString result;
	result.n = this->n + b.n;
	result.mas = new char[result.n + 1];
	result.mas[result.n] = '\0';
	for (int i = 0; i < this->n; i++)
	{
		result.mas[i] = this->mas[i];
	}
	for (int i = 0; i < b.n; i++)
	{
		result.mas[i + this->n] = b.mas[i];
	}
	return result;
}

TString& TString::operator=(const TString& b)
{
	if (b.mas != nullptr)
	{
		this->n = b.n;
		this->mas = new char[n + 1];
		mas[n] = '\0';
		for (int i = 0; b.mas[i] != '\0'; i++)
		{
			this->mas[i] = b.mas[i];
		}
	}
	return *this;
}

ostream& operator<<(ostream& out, const TString& a) {
	out << a.mas << endl;
	return out;
}

bool TString::operator==(const TString& b)
{
	int n1 = this->n;
	int n2 = b.n;
	int y = 0;
	if (n1 != n2) return false;
	else
	{
		for (int i = 0; i < n1; i++)
		{
			if (mas[i] != b.mas[i])
			{
				y = 1;
				break;
			}
		}
		if (y == 0) return true;
		else return false;
	}
}

bool TString::operator < (const TString& c)
{
	int len1 = 0;
	int len2 = 0;

	if (c.mas == nullptr && mas == nullptr) throw "Exception in operator <";
	else
	{
		len1 = strlen(mas);
		len2 = strlen(c.mas);

		if (len1 < len2) return true;
		else
		{
			if (len1 > len2) return false;
			else
			{
				for (int q = 0; q < len1; q++)
				{
					if (mas[q] > c.mas[q]) return false;
				}
			}
		}
	}

	return true;
}

bool TString::operator > (const TString& c)
{
	int len1 = 0;
	int len2 = 0;

	if (c.mas == nullptr && mas == nullptr) throw "Exception in operator <";
	else
	{
		len1 = strlen(mas);
		len2 = strlen(c.mas);

		if (len1 > len2) return true;
		else
		{
			if (len1 < len2) return false;
			else
			{

				for (int q = 0; q < len1; q++)
				{
					if (mas[q] < c.mas[q]) return false;
				}
			}
		}
	}

	return true;
}

char& TString::operator[](int i)
{
	char q = 3;

	if (n > 0 && mas != nullptr && (i >= 0 && i < n))
	{
		return mas[i];
	}
	else

		return q;
}

std::istream& operator>>(std::istream& in, TString& a) {

	char* tmp = new char[256];
	tmp[255] = '\0';
	in.getline(tmp, 255);

	a.mas = tmp;
	a.setLen(tmp);

	tmp = nullptr;
	delete[] tmp;

	return in;
}

int TString::findIdx(const char* _mas) {
	int tmplen = strlen(_mas);
	int y = 0;
	bool flag;
	for (int i = 0; i < this->n; i++)
	{
		flag = true;
		if (this->mas[i] == _mas[0])
		{
			y = i;
			for (int j = 0; j < tmplen; j++)
			{
				if (this->mas[j + i] != _mas[j]) {
					flag = false;
					break;
				}
				//return i;
			}
			if (flag == true) break;
		}

	}
	if (flag != true) return 0;
	else return y;
}

void TString::FindSub(char symbol)
{
	char* str_res = nullptr;
	int k = 1;
	for (int q = 0; q < strlen(mas); q++)
	{
		if (mas[q] != symbol)
		{
			cout << mas[q];
		}
		else
		{
			cout << " ->" << k << endl;
			k++;
		}

	}
	cout << " ->" << k << endl;
	delete[] str_res;
}

void TString::SetConstStr(const char* _str)
{
	int TemporaryLength = 0;
	if (_str == nullptr) throw "Error in SetStr func. Your str = 0";

	if (mas != nullptr) delete[] mas;
	mas = new char[strlen(_str) + 1];
	mas[strlen(_str)] = '\0';

	for (int q = 0; q < strlen(_str); q++)
	{
		mas[q] = _str[q];
	}
	n = (int)strlen(_str);
}