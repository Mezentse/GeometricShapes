#pragma once
#include"Object.h"
#include"Point.h"
#include"Vector.h"

using namespace std;

template <class Type>
class TCube : public TObject<Type>
{
protected:
	int dim;
	TVector<Type> FirstPoint, SecondPoint, ThirdPoint, FourthPoint;
	TString name;

public:
	TDrawing<Type> printer;
	TCube();
	TCube(const TCube<Type>& cube);
	virtual void Print();
	virtual void Plot();
	virtual int GetDim();
	virtual void SetName(const TString& _name);
	virtual TString& GetName();
	virtual TVector<Type>& operator [] (int i);
};

template<class Type>
inline TCube<Type>::TCube()
{
	cout << "input dim of first point" << endl;
	cin >> FirstPoint;

	cout << endl;

	cout << "input dim of second point" << endl;
	cin >> SecondPoint;

	cout << endl;

	cout << "input dim of third point" << endl;
	cin >> ThirdPoint;

	cout << endl;

	cout << "input dim of fourth point" << endl;
	cin >> FourthPoint;

	dim = FirstPoint.GetLen();
	name.SetConstStr("Cube");
	if (FirstPoint.GetLen() != SecondPoint.GetLen()) throw "dim of 1-st point != dim of 2-d point";
	if (ThirdPoint.GetLen() != FourthPoint.GetLen()) throw "dim of 3-d point != dim of 4-th point";
	printer.clear();
}

template<class Type>
inline TCube<Type>::TCube(const TCube<Type>& cube)
{
	FirstPoint = cube.FirstPoint;
	SecondPoint = cube.SecondPoint;
	ThirdPoint = cube.ThirdPoint;
	FourthPoint = cube.FourthPoint;
	dim = cube.dim;
	name = cube.name;
}

template<class Type>
inline void TCube<Type>::Print()
{
	cout << "name = " << name;
	cout << "dim =" << dim << endl;
	cout << "FirstPointOfCube = " << FirstPoint << endl;
	cout << "SecondPointOfCube = " << SecondPoint << endl;
	cout << "ThirdPointOfCube = " << ThirdPoint << endl;
	cout << "FourthPointOfCube = " << FourthPoint << endl;
}

template<class Type>
inline void TCube<Type>::Plot()
{
	printer.drawLine(FirstPoint[1], FirstPoint[0], FirstPoint[1], SecondPoint[0]); //ïåðâûé êâàäðàò
	printer.drawLine(FirstPoint[1], FirstPoint[0], SecondPoint[1], FirstPoint[0]);
	printer.drawLine(FirstPoint[1], SecondPoint[0], SecondPoint[1], SecondPoint[0]);
	printer.drawLine(SecondPoint[1], FirstPoint[0], SecondPoint[1], SecondPoint[0]);

	printer.drawLine(ThirdPoint[1], ThirdPoint[0], ThirdPoint[1], FourthPoint[0]);	//âòîðîé êâàäðàò
	printer.drawLine(ThirdPoint[1], ThirdPoint[0], FourthPoint[1], ThirdPoint[0]);
	printer.drawLine(ThirdPoint[1], FourthPoint[0], FourthPoint[1], FourthPoint[0]);
	printer.drawLine(FourthPoint[1], ThirdPoint[0], FourthPoint[1], FourthPoint[0]);

	printer.drawLine(FirstPoint[1], FirstPoint[0], ThirdPoint[1], ThirdPoint[0]);
	printer.drawLine(FirstPoint[1], FirstPoint[0], ThirdPoint[1], ThirdPoint[0]);
	printer.drawLine(FirstPoint[1], SecondPoint[0], ThirdPoint[1], FourthPoint[0]);
	printer.drawLine(SecondPoint[1], FirstPoint[0], FourthPoint[1], ThirdPoint[0]);

	printer.drawLine(FirstPoint[1], SecondPoint[0], ThirdPoint[1], FourthPoint[0]);
	printer.drawLine(SecondPoint[1], FirstPoint[0], FourthPoint[1], ThirdPoint[0]);
	printer.drawLine(SecondPoint[1], SecondPoint[0], FourthPoint[1], FourthPoint[0]);
	printer.drawLine(SecondPoint[1], SecondPoint[0], FourthPoint[1], FourthPoint[0]);

	printer.Print();
}

template<class Type>
inline int TCube<Type>::GetDim()
{
	return 0;
}

template<class Type>
inline void TCube<Type>::SetName(const TString& _name)
{
	name = _name;
}

template<class Type>
inline TString& TCube<Type>::GetName()
{
	return name;
}

template<class Type>
inline TVector<Type>& TCube<Type>::operator[](int i)
{
	switch (i)
	{
	case 0:
		return FirstPoint;
	case 1:
		return SecondPoint;
	case 2:
		return ThirdPoint;
	case 3:
		return FourthPoint;
		break;

	default:
		throw "Oops. You`re trying to get a non-exist array cell";
	}
}