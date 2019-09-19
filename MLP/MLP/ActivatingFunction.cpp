#include "ActivatingFunction.h"

double ActivatingFunction::getActivatedValue()
{
	calculateActivatedValue();
	return this->activatedValue;
}
double ActivatingFunction::getDerivedActivatedValue()
{
	calculateDerivedActivatedValue();
	return this->derivedActivatedValue;
}

SigmoidActivatingFunction::SigmoidActivatingFunction(double value)
{
	this->value = value;
	calculateActivatedValue();
	calculateDerivedActivatedValue();
}

void SigmoidActivatingFunction::calculateActivatedValue()
{
	this->isActivatedValueCalculated = true;
	this->activatedValue = this->value / (1 + abs(this->value));
}

void SigmoidActivatingFunction::calculateDerivedActivatedValue()
{
	if (this->isActivatedValueCalculated == false)
		calculateActivatedValue();
	this->derivedActivatedValue= this->activatedValue*(1-this->activatedValue);
}


void ActivatingFunction::setValue(double value)
{
	this->value = value;
}