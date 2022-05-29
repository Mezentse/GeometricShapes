#pragma once
#include"Object.h"
#include<iostream>

template<class Type>
class TPyramid : public TObject<Type>
{
protected:
	TVector<Type> FirstPoint, SecondPoint, ThirdPoint, FourthPoint;
	int dim;
	TString name;
public:
	TPyramid();
	TPyramid(const TPyramid<Type>& _pyr);
	~TPyramid();
	TDrawing<Type> printer;
	virtual void Print();
	virtual void Plot();
	virtual int GetDim();
	virtual void SetName(const TString& _name);
	virtual TString& GetName();
	virtual TVector<Type>& operator [] (int i);

};

template<class Type>
inline TPyramid<Type>::TPyramid()
{
	std::cout << "input dim of first point" << std::endl;
	std::cin >> FirstPoint;

	std::cout << std::endl;
	std::cout << "input dim of second point" << std::endl;
	std::cin >> SecondPoint;

	std::cout << std::endl;
	std::cout << "input dim of third point" << std::endl;
	std::cin >> ThirdPoint;

	std::cout << std::endl;
	std::cout << "input dim of fourth point" << std::endl;
	std::cin >> FourthPoint;

	dim = FirstPoint.GetLen();
	name.SetConstStr("Pyramid");
	if (FirstPoint.GetLen() != SecondPoint.GetLen() && ThirdPoint.GetLen() != FourthPoint.GetLen()) throw "dim of points isn't equals!";
	else if (FirstPoint.GetLen() != FourthPoint.GetLen()) throw "dim of points isn't equals!";

}

template<class Type>
inline TPyramid<Type>::TPyramid(const TPyramid<Type>& _pyr)
{
	name = _pyr.name;
	FirstPoint = _pyr.FirstPoint;
	SecondPoint = _pyr.SecondPoint;
	ThirdPoint = _pyr.ThirdPoint;
	FourthPoint = _pyr.FourthPoint;
	dim = _pyr.dim;
}

template<class Type>
inline TPyramid<Type>::~TPyramid()
{

}

template<class Type>
inline void TPyramid<Type>::Print()
{
	std::cout << "name = " << name;
	std::cout << "dim =" << dim << std::endl;
	std::cout << "FirstVector = " << FirstPoint << std::endl;
	std::cout << "SecondVector = " << SecondPoint << std::endl;
	std::cout << "ThirdVector = " << ThirdPoint << std::endl;
	std::cout << "FourthVector = " << ThirdPoint << std::endl;
}

template<class Type>
inline void TPyramid<Type>::Plot()
{
	printer.drawLine(FirstPoint[1], FirstPoint[0], SecondPoint[1], SecondPoint[0]);
	printer.drawLine(FirstPoint[1], FirstPoint[0], ThirdPoint[1], ThirdPoint[0]);
	printer.drawLine(SecondPoint[1], SecondPoint[0], ThirdPoint[1], ThirdPoint[0]);
	printer.PastePoint((float)FourthPoint[0], (float)FourthPoint[1]);
	printer.drawLine(FirstPoint[1], FirstPoint[0], FourthPoint[0], FourthPoint[1]);
	printer.drawLine(SecondPoint[1], SecondPoint[0], FourthPoint[0], FourthPoint[1]);
	printer.drawLine(ThirdPoint[1], ThirdPoint[0], FourthPoint[0], FourthPoint[1]);
	printer.Print();
}

template<class Type>
inline int TPyramid<Type>::GetDim()
{
	return dim;
}

template<class Type>
inline void TPyramid<Type>::SetName(const TString& _name)
{
	name = _name;
}

template<class Type>
inline TString& TPyramid<Type>::GetName()
{
	return name;
}

template<class Type>
inline TVector<Type>& TPyramid<Type>::operator[](int i)
{
	switch (i)
	{
	case 0:
		return FirstPoint;
	case 1:
		return SecondPoint;
		break;
	case 2:
		return ThirdPoint;
		break;
	case 3:
		return FourthPoint;
		break;

	default:
		throw "undefined behavior. You trying to get unexist cell of array";
	}
}