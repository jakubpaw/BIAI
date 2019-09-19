#pragma once

#include <cmath>
#include <iostream>
#include <vector>
#include "Neuron.h"
#include "ActivatingFunction.h"
#include "Matrix.h"

using namespace std;

class Layer
{
public:
	Layer(int size, ActivatingFunctionType functionType);
	void setValue(int index, double value);
	Matrix* makeMatrixRepresentationOfValues();
	Matrix* makeMatrixRepresentationOfActivatedValues();
	Matrix* makeMatrixRepresentationOfDerivedValues();

	vector<Neuron*> getNeurons();
	void setNeurons(vector<Neuron*>neurons);

	~Layer()
	{
		for (int i = neurons.size()-1; i > 0; i--)
			delete(neurons[i]);
	}
private:
	ActivatingFunctionType functionType;
	int size;
	vector<Neuron*> neurons;
};