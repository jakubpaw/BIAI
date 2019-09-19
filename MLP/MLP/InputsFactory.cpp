#include "InputsFactory.h"

Inputs InputsFactory::makeInputs(vector<double> inputs, int diceType)
{
	DiceType type;
	switch(diceType)
	{
	case 4: type = DiceType::d4;
		break;
	case 6: type = DiceType::d6;
		break;
	case 8: type = DiceType::d8;
		break;
	case 9: type = DiceType::d10;
		break;
	case 3: type = DiceType::d12;
		break;
	case 2: type = DiceType::d20;
		break;
	default:
		throw;
	}
	Inputs ret(inputs, type);
	return ret;
}

vector<Inputs> InputsFactory::makeAllInputsOfTargetDiceType(string trainOrValid, string diceType, int count)
{
	vector<Inputs> ret;
	for (int i = 1; i <= count; i++)
	{
		vector<double> vec =TxtReader::read(trainOrValid, diceType, i);
		int dType = (int)vec[vec.size() - 1];
		vec.pop_back();
		ret.push_back(InputsFactory::makeInputs(vec, dType));
	}
	return ret;
}