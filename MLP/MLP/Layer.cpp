#include "Layer.h"

Layer::Layer(int size, ActivatingFunctionType functionType)
{
	this->functionType = functionType;
	this->size = size;
	for (int i = 0; i < size; i++)
	{
		Neuron *n = new Neuron(0.0, this->functionType);
		this->neurons.push_back(n);
	}
}

void Layer::setValue(int index, double value)
{
	this->neurons[index]->setValue(value);
}

Matrix* Layer::makeMatrixRepresentationOfValues()
{
	Matrix* m = new Matrix(1, this->neurons.size(), false);
	for (int i = 0; i < this->neurons.size(); i++)
	{
		m->setValue(0, i, this->neurons[i]->getValue());
	}
	return m;
}

Matrix* Layer::makeMatrixRepresentationOfActivatedValues()
{
	Matrix* m = new Matrix(1, this->neurons.size(), false);
	for (int i = 0; i < this->neurons.size(); i++)
	{
		m->setValue(0, i, this->neurons[i]->getActivatedValue());
	}
	return m;
}

Matrix* Layer::makeMatrixRepresentationOfDerivedValues()
{
	Matrix* m = new Matrix(1, this->neurons.size(), false);
	for (int i = 0; i < this->neurons.size(); i++)
	{
		m->setValue(0, i, this->neurons[i]->getDerivedValue());
	}
	return m;
}

vector<Neuron*> Layer::getNeurons()
{
	return this->neurons;
}
void Layer::setNeurons(vector<Neuron*>neurons)
{
	this->neurons = neurons;
}