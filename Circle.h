#pragma once
#include"Object.h"

template<class Type>
class TCircle : public TObject<Type>
{
protected:
	TVector<Type> point;
	Type rad;
	int dim;
	TString name;
public:
	TDrawing<Type> printer;
	Type x, y, r;
	TCircle(Type _rad);
	TCircle(const TCircle& _round);
	~TCircle();
	virtual void Print();
	virtual void Plot();
	virtual int GetDim();
	void SetRad(Type _rad);
	Type GetRad();
	virtual void SetName(const TString& _name);
	virtual TString& GetName();
	virtual TVector<Type>& operator [] (int i);
};

template<class Type>
inline TCircle<Type>::TCircle(Type _rad)
{
	std::cout << "input dim of round" << std::endl;
	std::cin >> point;
	dim = point.GetLen();
	name.SetConstStr("Round");
	rad = _rad;
	x = 0;
	y = 0;
	r = 0;
}


template<class Type>
inline TCircle<Type>::TCircle(const TCircle& _round)
{
	point = _round.point;
	dim = _round.dim;
	name = _round.name;
	rad = _round.rad;
}

template<class Type>
inline TCircle<Type>::~TCircle()
{

}

template<class Type>
inline void TCircle<Type>::Print()
{
	std::cout << "dim =" << dim << std::endl;
	std::cout << "Coordinates: " << point << std::endl;
	std::cout << "name = " << name << std::endl;
	std::cout << "rad = " << rad << std::endl;
}

template<class Type>
inline void TCircle<Type>::Plot()
{
	x = point[0];
	y = point[1];
	r = rad;
	printer.PasteRound(x, y, r);
	printer.Print();
}

template<class Type>
inline int TCircle<Type>::GetDim()
{
	return dim;
}

template<class Type>
inline void TCircle<Type>::SetRad(Type _rad)
{
	rad = _rad;
}

template<class Type>
inline Type TCircle<Type>::GetRad()
{
	return rad;
}

template<class Type>
inline void TCircle<Type>::SetName(const TString& _name)
{
	name = _name;
}

template<class Type>
inline TString& TCircle<Type>::GetName()
{
	return name;
}

template<class Type>
inline TVector<Type>& TCircle<Type>::operator[](int i)
{
	return point;
}