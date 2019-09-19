#pragma once

#include <iostream>
#include "ActivatingFunction.h"
using namespace std;

class Neuron
{
public:
	Neuron(double value, ActivatingFunctionType functionType);
	~Neuron();


	void setValue(double value);

	double getValue();
	double getActivatedValue();
	double getDerivedValue();

	void activate();
	void deriveActivatedValue();
private:
	double value;
	double activatedValue;
	double derivedValue;
	ActivatingFunction* function;


};