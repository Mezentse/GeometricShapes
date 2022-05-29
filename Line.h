#pragma once
#include"Object.h"
#include"Vector.h"
#include"Point.h"

using namespace std;

template<class Type>
class TLine : public TObject<Type>
{
protected:
	int dim;
	TVector<Type> FirstPoint, SecondPoint;
	TString name;
public:
	TDrawing<Type> printer;
	TLine();
	~TLine();
	TLine(const TLine& _line);
	virtual void Print();
	virtual void Plot();
	virtual int GetDim();
	virtual void SetName(const TString& _name);
	virtual TString& GetName();
	virtual TVector<Type>& operator [] (int i);
};

template<class Type>
inline TLine<Type>::TLine()
{
	cout << "input dim of first point" << endl;
	cin >> FirstPoint;

	cout << endl;

	cout << "input dim of second point" << endl;
	cin >> SecondPoint;

	dim = FirstPoint.GetLen();
	name.SetConstStr("line");
	if (FirstPoint.GetLen() != SecondPoint.GetLen()) throw "dim of 1-st point != dim of 2-d point !!!";

	printer.clear();
}

template<class Type>
inline TLine<Type>::~TLine()
{

}

template<class Type>
inline TLine<Type>::TLine(const TLine& _line)
{
	FirstPoint = _line.FirstPoint;
	SecondPoint = _line.SecondPoint;
	dim = _line.dim;
	name = _line.name;
}

template<class Type>
inline void TLine<Type>::Print()
{
	cout << "name = " << name;
	cout << "dim =" << dim << endl;
	cout << "FirstVector = " << FirstPoint << endl;
	cout << "SecondVector = " << SecondPoint << endl;

}

template<class Type>
inline void TLine<Type>::Plot()
{
	printer.drawLine(FirstPoint[1], FirstPoint[0], SecondPoint[1], SecondPoint[0]);
	printer.Print();
}

template<class Type>
inline int TLine<Type>::GetDim()
{
	return 0;
}

template<class Type>
inline void TLine<Type>::SetName(const TString& _name)
{
	name = _name;
}

template<class Type>
inline TString& TLine<Type>::GetName()
{
	return name;
}

template<class Type>
inline TVector<Type>& TLine<Type>::operator[](int i)//ïðîâåðèòü
{
	switch (i)
	{
	case 0:
		return FirstPoint;
	case 1:
		return SecondPoint;
		break;

	default:
		throw "undefined behavior. You trying to get unexist cell of array";
	}
}