#include<iostream>
#include"String.h"
#include"Vector.h"
#include"Complex.h"
#include"Drawing.h"
#include"Line.h"
#include"Object.h"
#include"Point.h"
#include"Circle.h"
#include"Square.h"
#include"Triangle.h"
#include"Pyramid.h"
#include"Ñontainer.h"
#include"Cube.h"
using namespace std;

int main()
{
	TCont<int> cont;
	TPyramid<int> pyr;
	TCircle<int> round(10);
	TLine<int> line;
	TTriangle<int> triangle;
	TSquare<int> square;
	TCube<int> cube;
	cont.SetObject(&pyr);
	cont.SetObject(&round);
	cont.SetObject(&line);
	cont.SetObject(&triangle);
	cont.SetObject(&square);
	cont.SetObject(&cube);
	cont.Print();
	cont.Plotting();

	return 0;
}