#include "Neuron.h"

Neuron::Neuron(double value, ActivatingFunctionType functionType)
{
	switch (functionType)
	{
	case SIGMOID:
		function = new SigmoidActivatingFunction(value);
		break;
	default:
		break;
	}
	this->value = value;
	activate();
	deriveActivatedValue();
}
Neuron::~Neuron()
{
	if (this->function != NULL)
		delete function;
}

void Neuron::setValue(double value)
{
	this->value = value;
	activate();
	deriveActivatedValue();
}

void Neuron::activate()
{
	this->function->setValue(this->value);
	this->activatedValue = this->function->getActivatedValue();
}

void Neuron::deriveActivatedValue()
{
	this->derivedValue = this->function->getDerivedActivatedValue();
}

double Neuron::getActivatedValue()
{
	activate();
	return this->activatedValue;
}

double Neuron::getDerivedValue()
{
	deriveActivatedValue();
	return this->derivedValue;
}

double Neuron::getValue()
{
	return this->value;
}