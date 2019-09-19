#include "Matrix.h"

Matrix::Matrix(int numberOfRows, int numberOfColumns, bool isRandom)
{
	this->numberOfRows = numberOfRows;
	this->numberOfColumns = numberOfColumns;

	for (int i = 0; i < numberOfRows; i++)
	{
		vector<double> columnValues;
		for (int j = 0; j < numberOfColumns; j++)
		{
			double r = 0.0;
			if (isRandom)
			{
				r = this->generateRandomValue();
			}

			columnValues.push_back(r);
		}

		this->values.push_back(columnValues);
	}
}


void Matrix::printToConsole()
{
	for (int i = 0; i < numberOfRows; i++)
	{
		for (int j = 0; j < numberOfColumns; j++)
		{
			cout << this->values[i][j] << "\t\t";
		}
		cout << endl;
	}
}

Matrix*Matrix::transpose()
{
	Matrix*m = new Matrix(this->numberOfColumns, this->numberOfRows, false);
	for (int i = 0; i < numberOfRows; i++)
	{
		for (int j = 0; j < numberOfColumns; j++)
		{
			m->setValue(j, i, this->getValue(i, j));
		}
	}
	return m;
}

double Matrix::generateRandomValue()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis(0, 1);

	return dis(gen);
}

void Matrix::setValue(int row, int column, double value)
{
	values[row][column] = value;
}

double Matrix::getValue(int row, int column)
{
	return values[row][column];
}

int Matrix::getNumberOfRows()
{
	return this->numberOfRows;
}

int Matrix::getNumberOfColumns()
{
	return this->numberOfColumns;
}