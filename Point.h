#pragma once
#include<iostream>
#include"Vector.h"
#include"Object.h"

using namespace std;

template <class Type>
class TPoint : public TObject<Type>
{
protected:
    TString name;
    TVector<Type> Vec;
    int dim;

public:
    TPoint(int _dim);
    TDrawing<Type> printer;
    virtual void Plot();
    virtual void Print();
    virtual TVector<Type>& operator [](int i);
    virtual int GetDim();
    virtual void SetName(const TString& _name);
    virtual TString& GetName();
};

template<class Type>
TPoint<Type>::TPoint(int _dim)
{
    dim = _dim;
    Vec.ReSize(_dim);

    name.SetConstStr("qwerty");

    for (int q = 0; q < _dim; q++)
    {
        Vec[q] = 5;
    }
}

template<class Type>
inline void TPoint<Type>::Plot()
{
    printer.PastePoint(Vec);
    printer.Print();

}

template<class Type>
void TPoint<Type>::Print()
{
    cout << Vec << endl;
    cout << name << endl;
}

template<class Type>
inline TVector<Type>& TPoint<Type>::operator[](int i)
{
    return Vec;
}

template<class Type>
inline int TPoint<Type>::GetDim()
{
    return dim;
}

template<class Type>
inline void TPoint<Type>::SetName(const TString& _name)
{
    name = _name;
}

template<class Type>
inline TString& TPoint<Type>::GetName()
{
    return name;
}