#pragma once

#include<vector>
using namespace std;

enum DiceType
{
	d4,
	d6,
	d8,
	d10,
	d12,
	d20
};

class Inputs
{
public:
	Inputs(vector<double> inputs, DiceType diceType);
	double getInput(int index);
	vector<double> getInputs();
	DiceType getDiceType();
private:
	vector<double> inputs;
	DiceType diceType;
};