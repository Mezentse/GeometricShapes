#pragma once
#include<iostream>
#include<fstream>
template<class Type>
class TVector
{
protected:
	Type* data;
	int len;

public:

	TVector(int _len = 0);
	TVector(const TVector<Type>& _vector);
	~TVector();
	Type GetLen();
	Type PopBack();
	void PushBack(Type variable);
	Type& operator[](int number);
	TVector<Type> operator + (const TVector<Type>& _vector);
	TVector<Type> operator - (const TVector<Type>& _vector);
	TVector<Type> operator / (const TVector<Type>& _vector);
	TVector<Type>& operator = (const TVector<Type>& _vector);
	TVector<Type> operator *(const TVector<Type>& _vector);
	Type ScalarMult(const TVector<Type>& FirstVector, const TVector<Type>& SecondVector);

	void ReSize(int Newlen = 0);

	bool operator == (const TVector<Type>& _vector);
};

template<class Type>
std::istream& operator>>(std::istream& stream, TVector<Type>& _vector)
{

	int count = 0;
	stream >> count;
	Type variable = 0;
	int len = _vector.GetLen();
	_vector.ReSize(0);

	variable = 0;
	for (int q = 0; q < count; q++)
	{
		stream >> variable;
		_vector.PushBack(variable);
	}
	return stream;
}

template<class Type>
std::ostream& operator<<(std::ostream& stream, TVector<Type>& _vector)
{
	for (int q = 0; q < _vector.GetLen(); q++)
	{
		stream << _vector[q] << ' ';
	}
	return stream;
}

template<class Type>
inline TVector<Type>::TVector(int _len)
{
	data = 0;
	data = new Type[_len];
	len = _len;
}
template <class Type>
inline TVector<Type>::TVector(const TVector<Type>& _vector)
{
	if (_vector.data == 0) throw "varriable of vector is empty!";
	else
	{
		if (data != 0)
		{
			delete[] data;
			data = 0;
			data = new Type[_vector.len];
		}
		else
			data = new Type[_vector.len];
		len = _vector.len;
		for (int q = 0; q < len; q++)
		{
			data[q] = _vector.data[q];
		}
	}
}

template<class Type>
inline TVector<Type>::~TVector()
{
	if (data != 0)
		delete[] data;
	data = 0;
}

template<class Type>
inline Type TVector<Type>::GetLen()
{
	return len;
}

template<class Type>
inline Type TVector<Type>::PopBack()
{
	if (len <= 0) { throw"vector is empty"; }
	else
	{
		Type* temporary = new Type[len];
		for (int i = 0; i < len; i++)
		{
			temporary[i] = data[i];
		}
		Type variable = data[len - 1];

		data = 0;
		delete[] data;
		data = 0;
		data = new Type[len - 1];
		len--;
		for (int q = 0; q < len; q++)
		{
			data[q] = temporary[q];
		}
		temporary = 0;
		delete[] temporary;
		temporary = 0;

		return variable;
	}
}

template<class Type>
inline void TVector<Type>::PushBack(Type variable)
{

	Type* temporary = new Type[len];
	for (int i = 0; i < len; i++)
	{
		temporary[i] = data[i];
	}
	data = 0;
	delete[] data;
	data = 0;
	data = new Type[len + 1];
	for (int i = 0; i < len; i++)
	{
		data[i] = temporary[i];
	}
	data[len] = variable;
	len++;

}

template<class Type>
inline Type& TVector<Type>::operator[](int number)
{
	return data[number];
}

template<class Type>
TVector<Type> TVector<Type>::operator+ (const TVector<Type>& _vector)
{
	if (_vector.data == 0 && _vector.len < 0) throw "empty variable";
	if (_vector.len != this->len) throw "len of 1-st vector isn't equals to the 2-d vector";
	else
	{
		TVector<Type> result(*this);
		for (int q = 0; q < len; q++)
		{
			result.data[q] = (this->data[q]) + _vector.data[q];
		}

		return result;
	}
}

template<class Type>
TVector<Type> TVector<Type>::operator-(const TVector<Type>& _vector)
{
	if (_vector.data == 0 && _vector.len < 0) throw "empty variable";
	if (_vector.len != this->len) throw "len of 1-st vector isn't equals to the 2-d vector";
	else
	{
		TVector<Type> result(*this);
		for (int q = 0; q < len; q++)
		{
			result.data[q] = (this->data[q]) - _vector.data[q];
		}

		return result;
	}
}

template<class Type>
TVector<Type> TVector<Type>::operator/(const TVector<Type>& _vector)
{
	if (_vector.data == 0 && _vector.len < 0) throw "empty variable";
	if (_vector.len != this->len) throw "len of 1-st vector isn't equals to the 2-d vector";
	else
	{
		TVector<Type> result(*this);
		for (int q = 0; q < len; q++)
		{
			if (_vector.data[q] != 0)
				result.data[q] = (this->data[q]) / _vector.data[q];
			else throw "division by zero";
		}

		return result;
	}
}

template<class Type>
inline TVector<Type>& TVector<Type>::operator=(const TVector<Type>& _vector)
{
	if (data == 0) data = new Type[_vector.len];
	else if (data != 0)
	{
		data = 0;
		delete[] data;
		data = 0;
		data = new Type[_vector.len];
	}

	len = _vector.len;
	for (int q = 0; q < len; q++)
	{
		data[q] = _vector.data[q];
	}
	return *this;
}

template<class Type>
inline TVector<Type> TVector<Type>::operator*(const TVector<Type>& _vector)
{
	if (_vector.len != len) throw "Error!";
	TVector<Type> result(*this);
	for (int q = 0; q < result.len; q++)
	{
		result.data[q] = result.data[q] * _vector.data[q];
	}
	return result;
}

template<class Type>
inline Type TVector<Type>::ScalarMult(const TVector<Type>& FirstVector, const TVector<Type>& SecondVector)
{
	Type result = 0;
	if (FirstVector.len != SecondVector.len) throw "Error";
	for (int q = 0; q < FirstVector.len; q++)
		result += FirstVector.data[q] * SecondVector.data[q];
	return result;
}

template<class Type>
inline void TVector<Type>::ReSize(int Newlen)
{
	if (Newlen < 0) throw "The new len (or equals) less than zero";
	if (Newlen >= 0)
	{
		Type* temporary = new Type[Newlen];
		for (int q = 0; q < Newlen; q++)
		{
			temporary[q] = data[q];
		}

		delete[] data;
		data = 0;

		bool IsBigger = false;
		int Prevlen = len;
		data = new Type[Newlen];
		if (Newlen > len)  IsBigger = true;
		len = Newlen;

		if (IsBigger == false)
			for (int q = 0; q < len; q++)
				data[q] = temporary[q];

		if (IsBigger == true)
		{
			for (int q = 0; q < Prevlen; q++)
			{
				data[q] = temporary[q];
			}
			for (int q = Prevlen; q < len; q++)
			{
				data[q] = 0;
			}

		}

		delete[] temporary;
		temporary = 0;
	}

}

template<class Type>
inline bool TVector<Type>::operator==(const TVector<Type>& _vector)
{
	if (len != _vector.len) return false;
	for (int q = 0; q < len; q++)
	{
		if (data[q] != _vector.data[q]) return false;
	}
	return true;
}