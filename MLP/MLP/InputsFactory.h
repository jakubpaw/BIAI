#pragma once

#include "Inputs.h"
#include <vector>
#include "TxtReader.h"

using namespace std;

static class InputsFactory
{
public: 
	static Inputs makeInputs(vector<double> inputs, int diceType);
	static vector<Inputs> makeAllInputsOfTargetDiceType(string trainOrValid, string diceType, int count);
};