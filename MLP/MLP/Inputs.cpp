#include "Inputs.h"

Inputs::Inputs(vector<double> inputs, DiceType diceType)
{
	this->inputs = inputs;
	this->diceType = diceType;
}

double Inputs::getInput(int index)
{
	return inputs[index];
}

vector<double> Inputs::getInputs()
{
	return inputs;
}

DiceType Inputs::getDiceType()
{
	return diceType;
}