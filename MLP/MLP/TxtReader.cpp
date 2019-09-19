#include "TxtReader.h"

vector<double> TxtReader::read(string trainOrValid, string diceType, int number)
{
	stringstream ss;
	ss << number;
	string str = ss.str();

	string path = trainOrValid + "/" + diceType + "/dice (" + str + ").txt";

	vector<double> ret;

	std::ifstream is(path); 
	char c;
	bool isFirst = true;
	double diceTypeFromFile;
	while (is.get(c))
	{
		double d = double(c) - 48;
		if (isFirst)
		{
			isFirst = false;
			diceTypeFromFile = d;
		}
		else
			ret.push_back(d);
	}
	ret.push_back(diceTypeFromFile);

	is.close();

	return ret;
}