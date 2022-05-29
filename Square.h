#pragma once
#include"Object.h"
#include"Point.h"
#include"Vector.h"

template <class Type>
class TSquare : public TObject<Type>
{
protected:
	int dim;
	TVector<Type> FirstPoint, SecondPoint;
	TString name;

public:
	TDrawing<Type> printer;
	TSquare();
	TSquare(const TSquare<Type>& square);
	virtual void Print();
	virtual void Plot();
	virtual int GetDim();
	virtual void SetName(const TString& _name);
	virtual TString& GetName();
	virtual TVector<Type>& operator [] (int i);
};

template<class Type>
inline TSquare<Type>::TSquare()
{
	std::cout << "input dim of first point" << std::endl;
	std::cin >> FirstPoint;

	std::cout << std::endl;

	std::cout << "input dim of second point" << std::endl;
	std::cin >> SecondPoint;

	dim = FirstPoint.GetLen();
	name.SetConstStr("Square");
	if (FirstPoint.GetLen() != SecondPoint.GetLen()) throw "dim of 1-st point != dim of 2-d point !!!";

	printer.clear();
}

template<class Type>
inline TSquare<Type>::TSquare(const TSquare<Type>& square)
{
	FirstPoint = square.FirstPoint;
	SecondPoint = square.SecondPoint;
	dim = square.dim;
	name = square.name;
}

template<class Type>
inline void TSquare<Type>::Print()
{
	std::cout << "name = " << name;
	std::cout << "dim =" << dim << std::endl;
	std::cout << "FirstPointOfSquare = " << FirstPoint << std::endl;
	std::cout << "SecondPointOfSquare = " << SecondPoint << std::endl;
}

template<class Type>
inline void TSquare<Type>::Plot()
{
	printer.drawLine(FirstPoint[1], FirstPoint[0], FirstPoint[1], SecondPoint[0]);
	printer.drawLine(FirstPoint[1], FirstPoint[0], SecondPoint[1], FirstPoint[0]);
	printer.drawLine(FirstPoint[1], SecondPoint[0], SecondPoint[1], SecondPoint[0]);
	printer.drawLine(SecondPoint[1], FirstPoint[0], SecondPoint[1], SecondPoint[0]);
	printer.Print();
}

template<class Type>
inline int TSquare<Type>::GetDim()
{
	return 0;
}

template<class Type>
inline void TSquare<Type>::SetName(const TString& _name)
{
	name = _name;
}

template<class Type>
inline TString& TSquare<Type>::GetName()
{
	return name;
}

template<class Type>
inline TVector<Type>& TSquare<Type>::operator[](int i)
{
	switch (i)
	{
	case 0:
		return FirstPoint;
	case 1:
		return SecondPoint;
		break;

	default:
		throw "Oops. You`re trying to get a non-exist array cell";
	}
}