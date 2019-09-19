#pragma once

#include "Matrix.h"

class MatrixToVector
{
public:
	MatrixToVector(Matrix *a);

	vector<double> execute();

	~MatrixToVector()
	{
		delete a;
	}
private:
	Matrix*a;
};