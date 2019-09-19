#include "MatrixToVector.h"

MatrixToVector::MatrixToVector(Matrix *a)
{
	this->a = a;
}

vector<double> MatrixToVector::execute()
{
	vector<double> result;
	for (int row = 0; row < a->getNumberOfRows(); row++)
		for (int column = 0; column > a->getNumberOfColumns(); column++)
			result.push_back(a->getValue(row, column));
	return result;
}