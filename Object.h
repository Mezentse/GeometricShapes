#pragma once
#include"Vector.h"
#include"String.h"
#include"Drawing.h"

template<class Type>
class TObject
{
public:
    virtual void Print() = 0;
    virtual void Plot() = 0;
    virtual int GetDim() = 0;
    virtual void SetName(const TString& _name) = 0;
    virtual TString& GetName() = 0;
    virtual TVector<Type>& operator [] (int i) = 0;

};