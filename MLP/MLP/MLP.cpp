// MLP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "NeuralNetwork.h"
#include "TxtReader.h"
#include "InputsFactory.h"
#include <algorithm>  
#include <ctime>   
#include <cstdlib>  


using namespace std;

int myrandom(int i) { return std::rand() % i; }

int main()
{

#pragma region MyRegion


	std::srand(unsigned(std::time(0)));

	vector<Inputs> vec1	 = InputsFactory::makeAllInputsOfTargetDiceType("train", "d4", 1000);	//max 1947
	vector<Inputs> vec2	 = InputsFactory::makeAllInputsOfTargetDiceType("train", "d6", 1000);	//max 4046
	//vector<Inputs> vec3	 = InputsFactory::makeAllInputsOfTargetDiceType("train", "d8", 1532);	//max 1532
	//vector<Inputs> vec4	 = InputsFactory::makeAllInputsOfTargetDiceType("train", "d10", 1722);	//max 1722
	//vector<Inputs> vec5	 = InputsFactory::makeAllInputsOfTargetDiceType("train", "d12", 1691);	//max 1691
	//vector<Inputs> vec6	 = InputsFactory::makeAllInputsOfTargetDiceType("train", "d20", 3346);	//max 3346
	vector<Inputs> vec7	 = InputsFactory::makeAllInputsOfTargetDiceType("valid", "d4", 278);	//max 278
	vector<Inputs> vec8	 = InputsFactory::makeAllInputsOfTargetDiceType("valid", "d6", 578);	//max 578
	//vector<Inputs> vec9	 = InputsFactory::makeAllInputsOfTargetDiceType("valid", "d8", 218);	//max 218
	//vector<Inputs> vec10 = InputsFactory::makeAllInputsOfTargetDiceType("valid", "d10", 246);	//max 246
	//vector<Inputs> vec11 = InputsFactory::makeAllInputsOfTargetDiceType("valid", "d12", 241);	//max 241
	//vector<Inputs> vec12 = InputsFactory::makeAllInputsOfTargetDiceType("valid", "d20", 478);	//max 478

	vector<Inputs> vectTrain;
	vector<Inputs> vectValid;

	for (int i = vec1.size()-1; i >= 0; i--)
	{
		vectTrain.push_back(vec1[i]);
		vec1.pop_back();
	}
	for (int i = vec2.size() - 1; i >= 0; i--)
	{
		vectTrain.push_back(vec2[i]);
		vec2.pop_back();
	}
	//for (int i = vec3.size() - 1; i >= 0; i--)
	//{
	//	vectTrain.push_back(vec3[i]);
	//	vec3.pop_back();
	//}
	//for (int i = vec4.size() - 1; i >= 0; i--)
	//{
	//	vectTrain.push_back(vec4[i]);
	//	vec4.pop_back();
	//}
	//for (int i = vec5.size() - 1; i >= 0; i--)
	//{
	//	vectTrain.push_back(vec5[i]);
	//	vec5.pop_back();
	//}
	//for (int i = vec6.size() - 1; i >= 0; i--)
	//{
	//	vectTrain.push_back(vec6[i]);
	//	vec6.pop_back();
	//}


	for (int i = vec7.size() - 1; i >= 0; i--)
	{
		vectValid.push_back(vec7[i]);
		vec7.pop_back();
	}
	for (int i = vec8.size() - 1; i >= 0; i--)
	{
		vectValid.push_back(vec8[i]);
		vec8.pop_back();
	}
	//for (int i = vec9.size() - 1; i >= 0; i--)
	//{
	//	vectValid.push_back(vec9[i]);
	//	vec9.pop_back();
	//}
	//for (int i = vec10.size() - 1; i >= 0; i--)
	//{
	//	vectValid.push_back(vec10[i]);
	//	vec10.pop_back();
	//}
	//for (int i = vec11.size() - 1; i >= 0; i--)
	//{
	//	vectValid.push_back(vec11[i]);
	//	vec11.pop_back();
	//}
	//for (int i = vec12.size() - 1; i >= 0; i--)
	//{
	//	vectValid.push_back(vec12[i]);
	//	vec12.pop_back();
	//}

	// using built-in random generator:
	std::random_shuffle(vectTrain.begin(), vectTrain.end());

	// using myrandom:
	std::random_shuffle(vectTrain.begin(), vectTrain.end(), myrandom);

	// using built-in random generator:
	std::random_shuffle(vectValid.begin(), vectValid.end());

	// using myrandom:
	std::random_shuffle(vectValid.begin(), vectValid.end(), myrandom);


	cout << "qwe" << endl;

	vector<int> topology;
	topology.push_back(4356);
	topology.push_back(512);
	topology.push_back(2);

	NeuralNetwork *network = new NeuralNetwork(topology, ActivatingFunctionType::SIGMOID);
	

	for (int i = 0; i < 200; i++)
	{
		network->setCurrentInput(vectTrain[i]);
		network->setCurrentTarget(vectTrain[i]);
		network->feedForward();
		network->setErrors();
		cout <<"Total error: "<< network->getTotalError() << endl;
		network->backPropagation();
	}
	/*network->setCurrentInput(inputs3);
	network->setCurrentTarget(inputs3);
	network->feedForward();
	network->setErrors();
	network->backPropagation();*/


	cout << "Total error: " << network->getTotalError() << endl;
	delete network;

#pragma endregion
#pragma region MyRegion


	//vector<int> topology;
	//topology.push_back(3);
	//topology.push_back(2);
	//topology.push_back(3);

	//vector<double> inputs;
	//inputs.push_back(1.0);
	//inputs.push_back(0.0);
	//inputs.push_back(1.0);

	//vector<double> inputs2;
	//inputs2.push_back(0.0);
	//inputs2.push_back(1.0);
	//inputs2.push_back(1.0);

	//vector<double> inputs3;
	//inputs3.push_back(1.0);
	//inputs3.push_back(1.0);
	//inputs3.push_back(1.0);

	//NeuralNetwork *network = new NeuralNetwork(topology, ActivatingFunctionType::SIGMOID);


	//for (int i = 0; i < 500; i++)
	//{
	//	network -> setCurrentInput(inputs);
	//	network -> setCurrentTarget(inputs);
	//	network -> feedForward();
	//	network -> setErrors();
	//	cout << "Total error: " << network->getTotalError() << endl;
	//	network->backPropagation();

	//	network -> setCurrentInput(inputs2);
	//	network -> setCurrentTarget(inputs2);
	//	network -> feedForward();
	//	network -> setErrors();
	//	cout << "Total error: " << network->getTotalError() << endl;
	//	network -> backPropagation();


	//}
	//network -> setCurrentInput(inputs3);
	//network -> setCurrentTarget(inputs3);
	//network -> feedForward();
	//network -> setErrors();
	//network -> backPropagation();


	//cout << "Total error: " << network->getTotalError() << endl;
	//delete network;
#pragma endregion

	return 0;
}
