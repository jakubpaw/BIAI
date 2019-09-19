#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(vector<int> topology, ActivatingFunctionType functionType)
{
	this->functionType = functionType;
	this->topologySize = topology.size();
	this->topology = topology;

	initializeLayers();
	initializeWeightMatrices();

	for (int i = 0; i < topology[topology.size() - 1]; i++)
		errors.push_back(0.0);
}


void NeuralNetwork::printToConsole()
{
	for (int i = 0; i < this->layers.size(); i++)
	{
		cout << "Layer: " << i << endl;
		if (i == 0)
		{
			Matrix*m = this->layers[i]->makeMatrixRepresentationOfValues();
			m->printToConsole();
		}
		else
		{
			Matrix*m = this->layers[i]->makeMatrixRepresentationOfActivatedValues();
			m->printToConsole();
		}

		if (i < this->layers.size() - 1)
		{
			cout << "----------" << endl;
			cout << "Weight Matrix: " << i << endl;
			this->getWeightMatrix(i)->printToConsole();
			cout << "----------" << endl;


		}
	}
}

void NeuralNetwork::feedForward()
{
	for (int i = 0; i < (this->layers.size() - 1); i++)
	{
		Matrix *a = this->getNeuronMatrix(i);
		if(i!=0)
		{
			a = this->getActivatedNeuronMatrix(i);
		}

		Matrix*b = this->getWeightMatrix(i);
		Matrix *c = (new MultiplyMatrix(a, b))->execute();

		for (int c_index = 0; c_index < c->getNumberOfColumns(); c_index++)
		{
			this->setNeuronValue(i + 1, c_index, c->getValue(0, c_index));
		}
		delete a;
		//delete b;
		delete c;
	}
}

void NeuralNetwork::backPropagation()
{
	vector<Matrix*> newWeights;
	Matrix*gradient;

	int outputLayerIndex = this->layers.size() - 1;
	Matrix *derivedValuesFromYToZ = this->layers[outputLayerIndex]->makeMatrixRepresentationOfDerivedValues();
	Matrix *gradientFromYToZ = new Matrix(1, this->layers[outputLayerIndex]->getNeurons().size(), false);

	for (int i = 0; i < this->errors.size(); i++)
	{
		double d = derivedValuesFromYToZ->getValue(0, i);
		double e = this->errors[i];
		double g = d * e;
		gradientFromYToZ->setValue(0, i, g);
	}

	int LastHiddenLayerIndex = outputLayerIndex - 1;
	Layer*lastHiddenLayer = this->layers[LastHiddenLayerIndex];
	Matrix *weightsOutputToHidden = this->weightMatrices[outputLayerIndex - 1];
	MultiplyMatrix multiplyMatrix(
								gradientFromYToZ->transpose(), 
								lastHiddenLayer->makeMatrixRepresentationOfActivatedValues()
								);
	Matrix *deltaOutputToHidden = multiplyMatrix.execute()->transpose();

	Matrix *newWeightsOutputToHidden = new Matrix(deltaOutputToHidden->getNumberOfRows(), deltaOutputToHidden->getNumberOfColumns(), false);




	for (int r = 0; r < deltaOutputToHidden->getNumberOfRows(); r++)
	{
		for (int c = 0; c < deltaOutputToHidden->getNumberOfColumns(); c++)
		{
			double originalWeight = weightsOutputToHidden->getValue(r, c);
			double deltaWeight = deltaOutputToHidden->getValue(r, c);
			newWeightsOutputToHidden->setValue(r, c, (originalWeight-deltaWeight));
		}
	}

	newWeights.push_back(newWeightsOutputToHidden);

	
	gradient = new Matrix(gradientFromYToZ->getNumberOfRows(), gradientFromYToZ->getNumberOfColumns(), false);
	for (int r = 0; r < gradientFromYToZ->getNumberOfRows(); r++)
	{
		for (int c = 0; c < gradientFromYToZ->getNumberOfColumns(); c++)
		{
			gradient->setValue(r, c, gradientFromYToZ->getValue(r, c));
		}
	}

	///
	for (int i = outputLayerIndex - 1; i > 0; i--)
	{
		Layer*l = this->layers[i];
		//todo usun¹æ
		//Matrix *derivedHidden = l->makeMatrixRepresentationOfDerivedValues();
		Matrix *activatedHidden = l->makeMatrixRepresentationOfActivatedValues();
		Matrix *derivedGradients = new Matrix(1, l->getNeurons().size(), false);

		Matrix*weightMatrix = this->weightMatrices[i];
		Matrix*originalWeight = this->weightMatrices[i - 1];

		for (int r = 0; r < weightMatrix->getNumberOfRows(); r++)
		{
			double sum = 0;
			for (int c = 0; c < weightMatrix->getNumberOfColumns(); c++)
			{
				double p = gradient->getValue(0,c)*weightMatrix->getValue(r, c);
				sum += p;
			}
			double g = sum * activatedHidden->getValue(0, r);
			derivedGradients->setValue(0, r, g);
		}
		Matrix *leftNeurons = (i-1)==0 ? this->layers[0]->makeMatrixRepresentationOfValues() : this->layers[i - 1]->makeMatrixRepresentationOfActivatedValues();

		Matrix*deltaWeights = (new MultiplyMatrix(derivedGradients->transpose(), leftNeurons))->execute()->transpose();
		Matrix* newWeightsHidden = new Matrix(
			deltaWeights->getNumberOfRows(),
			deltaWeights->getNumberOfColumns(),
			false);

		for (int r = 0; r < newWeightsHidden->getNumberOfRows(); r++)
		{
			for (int c = 0; c < newWeightsHidden->getNumberOfColumns(); c++)
			{
				double w = originalWeight->getValue(r, c);
				double d = deltaWeights->getValue(r, c);
				double n = w - d;
				newWeightsHidden->setValue(r, c, n);
			}
		}

		delete gradient;

		gradient = new Matrix(derivedGradients->getNumberOfRows(), derivedGradients->getNumberOfColumns(), false);
		for (int r = 0; r < derivedGradients->getNumberOfRows(); r++)
		{
			for (int c = 0; c < derivedGradients->getNumberOfColumns(); c++)
			{
				gradient->setValue(r, c, derivedGradients->getValue(r, c));
			}
		}
		newWeights.push_back(newWeightsHidden);

		delete deltaWeights;
		delete activatedHidden;
		delete derivedGradients;
		delete gradient;

	}

	delete deltaOutputToHidden;
	delete derivedValuesFromYToZ;
	delete gradientFromYToZ;

	reverse(newWeights.begin(), newWeights.end());

	for (int i = this->weightMatrices.size() - 1; i > 0; i--)
	{
		delete this->weightMatrices[i];
	}

	this->weightMatrices = newWeights;
}

void NeuralNetwork::setNeuronValue(int layerIndex, int neuronIndex, double value)
{
	this->layers[layerIndex]->setValue(neuronIndex, value);
}

void NeuralNetwork::initializeLayers()
{
	for (int i = 0; i < this->topologySize; i++)
	{
		Layer*l = new Layer(this->topology[i], this->functionType);
		this->layers.push_back(l);
	}
}

void NeuralNetwork::initializeWeightMatrices()
{
	for (int i = 0; i < this->topologySize - 1; i++)
	{
		Matrix*m = new Matrix(this->topology[i], this->topology[i + 1], true);
		this->weightMatrices.push_back(m);
	}
}

void NeuralNetwork::setCurrentInput(vector<double> inputs)
{
	this->inputs = inputs;

	for (int i = 0; i < inputs.size(); i++)
	{
		this->layers[0]->setValue(i, this->inputs[i]);
	}
}

Matrix* NeuralNetwork::getNeuronMatrix(int index)
{
	return this->layers[index]->makeMatrixRepresentationOfValues();
}

Matrix* NeuralNetwork::getActivatedNeuronMatrix(int index)
{
	return this->layers[index]->makeMatrixRepresentationOfActivatedValues();
}

Matrix* NeuralNetwork::getDerivedNeuronMatrix(int index)
{
	return this->layers[index]->makeMatrixRepresentationOfDerivedValues();
}

Matrix* NeuralNetwork::getWeightMatrix(int index)
{
	return this->weightMatrices[index];
}

double NeuralNetwork::getTotalError()
{
	return this->error;
}

vector<double> NeuralNetwork::getErrors()
{
	return this->errors;
}

void NeuralNetwork::setCurrentTarget(vector<double> target)
{
	this->target = target;
}

void NeuralNetwork::setErrors()
{
	if (this->target.size() == 0)
		cout << "Brak Targetu" << endl;

	if (this->target.size() != layers[this->layers.size() - 1]->getNeurons().size())
		cout << "Z³y rozmiar targetu" << endl;

	this->error = 0.0;
	int outputLayerIndex = this->layers.size() - 1;
	vector<Neuron*> outputNeurons = this->layers[outputLayerIndex]->getNeurons();
	for (int i = 0; i < this->target.size(); i++)
	{
		double tempError = (outputNeurons[i]->getActivatedValue() - this->target[i]);
		this->errors[i] = tempError;
		this->error += pow(tempError,2);
	}

	this->error = 0.5*this->error;

	historicalErrors.push_back(this->error);
}

void NeuralNetwork::setCurrentInput(Inputs inputs)
{
	setCurrentInput(inputs.getInputs());
}


void NeuralNetwork::setCurrentTarget(Inputs inputs)
{
	vector<double> targetVec;
	for (int i = 0; i < topology[topology.size() - 1]; i++)
	{
		targetVec.push_back(0);
	}

	switch (inputs.getDiceType())
	{
	case DiceType::d4:
		targetVec[0] = 1;
		break;
	case DiceType::d6:
		targetVec[1] = 1;
		break;
	case DiceType::d8:
		targetVec[2] = 1;
		break;
	case DiceType::d10:
		targetVec[3] = 1;
		break;
	case DiceType::d12:
		targetVec[4] = 1;
		break;
	case DiceType::d20:
		targetVec[5] = 1;
		break;
	}

	this->target = targetVec;
}