#pragma once
#include <iostream>

using namespace std;

class TString
{
protected:
	int n;
	char* mas;
public:
	TString();
	TString(const char* _mas);
	TString(const TString& other);

	~TString();

	void SetConstStr(const char* _str);

	char* GetStr();
	int setLen(const char* _str);

	TString operator +(const TString& b);
	TString& operator =(const TString& b);

	bool operator ==(const TString& b);
	bool operator <(const TString& b);
	bool operator >(const TString& b);

	char& operator [](int x);

	friend ostream& operator<< (ostream& out, const TString& b);
	friend istream& operator>> (istream& in, TString& b);

	int findIdx(const char* _mas);
	void FindSub(char symbol);
};