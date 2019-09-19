#pragma once
#include<vector>
#include<random>
#include<iostream>
using namespace std;

class Matrix
{
public:
	Matrix(int numberOfRows, int numberOfColumns, bool isRandom);
	void printToConsole();

	Matrix *transpose();

	double generateRandomValue();
	void setValue(int row, int column, double value);
	double getValue(int row, int column);

	int getNumberOfRows();
	int getNumberOfColumns();
private:
	int numberOfRows;
	int numberOfColumns;

	vector <vector<double>> values;
};