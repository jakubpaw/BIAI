#pragma once
#include <vector>
#include "Layer.h"
#include "Matrix.h"
#include "ActivatingFunction.h"
#include "MultiplyMatrix.h"
#include <algorithm>
#include "Inputs.h"

class NeuralNetwork
{
public:
	NeuralNetwork(vector<int> topology, ActivatingFunctionType functionType);
	void printToConsole();
	void setCurrentInput(vector<double> inputs);
	void setCurrentInput(Inputs inputs);
	void setCurrentTarget(vector<double> target);
	void setCurrentTarget(Inputs inputs);
	void setNeuronValue(int layerIndex, int neuronIndex, double value);
	void setErrors();

	void feedForward();
	void backPropagation();

	Matrix*getNeuronMatrix(int index);
	Matrix*getActivatedNeuronMatrix(int index);
	Matrix*getDerivedNeuronMatrix(int index);
	Matrix*getWeightMatrix(int index);

	double getTotalError();
	vector<double> getErrors();

	~NeuralNetwork()
	{
		for (int i = layers.size()-1; i > 0; i--)
			delete layers[i];

		for (int i = weightMatrices.size()-1; i > 0; i--)
			delete weightMatrices[i];

		for (int i = gradientMatrices.size()-1; i > 0; i--)
			delete gradientMatrices[i];
	}
private:
	ActivatingFunctionType functionType;
	int topologySize;
	vector<int> topology;
	vector<Layer*> layers;
	vector<Matrix *> weightMatrices;
	vector<Matrix *> gradientMatrices;
	vector<double> inputs;

	vector<double> target;

	double error;
	vector<double> errors;
	vector<double> historicalErrors;

	void initializeLayers();
	void initializeWeightMatrices();
};