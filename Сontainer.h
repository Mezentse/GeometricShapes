#pragma once
#include"Vector.h"
#include"Complex.h"
#include"Drawing.h"
#include"Line.h"
#include"Object.h"
#include"Point.h"
#include"Circle.h"
#include"Square.h"
#include"Triangle.h"

template<class Type>
class TCont
{
public:
    int count;
    TObject<Type>** data;
    TCont();
    ~TCont();
    void SetObject(TObject<Type>* _object);
    void Print();
    void Plotting();
    void Print(int _numb);
    void Plotting(int _numb);
    void DelObj();
    int GetCount();
};

template<class Type>
inline TCont<Type>::TCont()
{
    data = 0;
    count = 0;
}

template<class Type>
inline TCont<Type>::~TCont()
{
    delete[] data;
    data = 0;
}

template<class Type>
inline void TCont<Type>::SetObject(TObject<Type>* _object)
{
    if (data == 0)
    {
        data = new TObject<Type>*[1];
        count++;
        data[0] = _object;
    }
    else
    {
        TObject<Type>** temp = new TObject<Type>*[count + 1];
        for (int q = 0; q < count; q++)
            temp[q] = data[q];
        delete[] data;
        data = 0;

        data = new TObject<Type>*[count + 1];
        for (int q = 0; q < count; q++)
            data[q] = temp[q];
        data[count] = _object;
        count++;

        delete[] temp;
        temp = 0;
    }
}

template<class Type>
inline void TCont<Type>::Print()
{
    if (count > 0)
        for (int q = 0; q < count; q++)
            data[q]->Print();
}

template<class Type>
inline void TCont<Type>::Plotting()
{
    if (count > 0)
        for (int q = 0; q < count; q++)
            data[q]->Plot();
}

template<class Type>
inline void TCont<Type>::Print(int _numb)
{
    if (_numb < 0 || _numb >(count - 1)) throw "Trying to get access to out of array";
    else
        data[_numb]->Print();
}

template<class Type>
inline void TCont<Type>::Plotting(int _numb)
{
    if (_numb < 0 || _numb >(count - 1)) throw "Trying to get access to out of array";
    else
        data[_numb]->Plot();
}

template<class Type>
inline void TCont<Type>::DelObj()
{
    if (data == 0) throw "array is empty";
    else if (data != 0)
    {
        TObject<Type>** temp = new TObject<Type>*[count - 1];
        for (int q = 0; q < count - 1; q++)
            temp[q] = data[q];
        delete[] data;
        data = 0;

        count--;
        data = new TObject<Type>*[count];
        for (int q = 0; q < count; q++)
            data[q] = temp[q];
    }
}

template<class Type>
inline int TCont<Type>::GetCount()
{
    return count;
}