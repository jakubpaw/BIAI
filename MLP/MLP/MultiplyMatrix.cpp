#include "MultiplyMatrix.h"
#include <iostream>
using namespace std;

MultiplyMatrix::MultiplyMatrix(Matrix*a, Matrix*b)
{
	this->a = a;
	this->b = b;

	if (a->getNumberOfColumns() != b->getNumberOfRows())
		cout << "B³¹d przy mno¿eniu macierzy" << endl;
}

Matrix* MultiplyMatrix::execute()
{

	Matrix *c = new Matrix(a->getNumberOfRows(), b->getNumberOfColumns(), false);
	for (int i = 0; i < a->getNumberOfRows(); i++)
		for (int j = 0; j < b->getNumberOfColumns(); j++)
			for (int k = 0; k < b->getNumberOfRows(); k++)
			{
				double p = this->a->getValue(i, k) * this->b->getValue(k, j);
				double newValue = c->getValue(i, j) + p;
				c->setValue(i, j, newValue);
			}
	return c;
}