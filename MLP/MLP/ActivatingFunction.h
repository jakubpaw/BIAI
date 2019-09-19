#pragma once
#include <cmath>
enum ActivatingFunctionType
{
	SIGMOID = 0
};
class ActivatingFunction 
{
public:
	virtual void calculateActivatedValue()=0;
	virtual void calculateDerivedActivatedValue()=0;
	double getActivatedValue();
	double getDerivedActivatedValue();
	void setValue(double value);
protected:
	double value;
	double activatedValue;
	double derivedActivatedValue;
	bool isActivatedValueCalculated;
};

class SigmoidActivatingFunction : public ActivatingFunction
{
public:
	SigmoidActivatingFunction(double value);
	void calculateActivatedValue();
	void calculateDerivedActivatedValue();
};