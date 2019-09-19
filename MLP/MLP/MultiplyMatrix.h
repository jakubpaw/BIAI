#pragma once

#include "Matrix.h"

class MultiplyMatrix
{
public:
	MultiplyMatrix(Matrix*a, Matrix*b);

	Matrix*execute();

	~MultiplyMatrix()
	{
		delete a;
		delete b;
	}
private:
	Matrix*a;
	Matrix*b;
};