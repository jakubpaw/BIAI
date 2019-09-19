#pragma once

#include <iostream>
#include<vector>
#include<fstream>
#include <sstream>
using namespace std;

static class TxtReader
{
public:
	static vector<double> read(string trainOrValid,string diceType, int number);
};