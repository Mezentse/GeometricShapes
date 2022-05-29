#pragma once
#include"Object.h"

template <class Type>
class TTriangle : public TObject<Type>
{
protected:
	TVector<Type> FirstPoint, SecondPoint, ThirdPoint;
	int dim;
	TString name;

public:
	TDrawing<Type> printer;
	TTriangle();
	TTriangle(const TTriangle<Type>& q);
	virtual void Print();
	virtual void Plot();
	virtual int GetDim();
	virtual void SetName(const TString& _name);
	virtual TString& GetName();
	virtual TVector<Type>& operator [] (int i);
};

template<class Type>
inline TTriangle<Type>::TTriangle()
{
	std::cout << "input dim of first point" << std::endl;
	std::cin >> FirstPoint;

	std::cout << std::endl;

	std::cout << "input dim of second point" << std::endl;
	std::cin >> SecondPoint;

	std::cout << std::endl;

	std::cout << "input dim of third point" << std::endl;
	std::cin >> ThirdPoint;

	dim = FirstPoint.GetLen();
	name.SetConstStr("triangle");
	if (FirstPoint.GetLen() != SecondPoint.GetLen() && FirstPoint.GetLen() != ThirdPoint.GetLen()) throw "dim of 1-st point != dim of 2-d point !!!";

}

template<class Type>
inline TTriangle<Type>::TTriangle(const TTriangle<Type>& q)
{
	name = q.name;
	FirstPoint = q.FirstPoint;
	SecondPoint = q.SecondPoint;
	ThirdPoint = q.ThirdPoint;
	dim = q.dim;
}

template<class Type>
inline void TTriangle<Type>::Print()
{
	std::cout << "name = " << name;
	std::cout << "dim =" << dim << std::endl;
	std::cout << "FirstVector = " << FirstPoint << std::endl;
	std::cout << "SecondVector = " << SecondPoint << std::endl;
	std::cout << "ThirdVector = " << ThirdPoint << std::endl;
}

template<class Type>
inline void TTriangle<Type>::Plot()
{
	printer.drawLine(FirstPoint[1], FirstPoint[0], SecondPoint[1], SecondPoint[0]);
	printer.drawLine(FirstPoint[1], FirstPoint[0], ThirdPoint[1], ThirdPoint[0]);
	printer.drawLine(SecondPoint[1], SecondPoint[0], ThirdPoint[1], ThirdPoint[0]);
	printer.Print();

}

template<class Type>
inline int TTriangle<Type>::GetDim()
{
	return dim;
}

template<class Type>
inline void TTriangle<Type>::SetName(const TString& _name)
{
	name = _name;
}

template<class Type>
inline TString& TTriangle<Type>::GetName()
{
	return name;
}

template<class Type>
inline TVector<Type>& TTriangle<Type>::operator[](int i)
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

	default:
		throw "undefined behavior. You trying to get unexist cell of array";
	}
}