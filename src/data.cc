#include "../include/Data.hpp"

void Data::setDistance(double dist)
{

	distance = dist;
}

void Data::setFeatureVector(std::vector<uint8_t> *vec)
{
	featureVector = vec;
}

void Data::setNormalizedFeatureVector(std::vector<double> *vec)
{
	normalizedFeatureVector = vec;
}

void Data::setClassVector(int counts)
{
	classVector = new std::vector<int>();
	for (int i = 0; i < counts; i++)
	{
		if (i == label)
		{
			classVector->push_back(1);
		}
		else
		{
			classVector->push_back(0);
		}
	}
}

void Data::appendToFeatureVector(uint8_t val)
{
	featureVector->push_back(val);
}

void Data::appendToFeatureVector(double val)
{
	featureVector->push_back(val);
}

void Data::setLabel(uint8_t val)
{
	label = val;
}

void Data::setEnumeratedLabel(int val)
{
	enumeratedLabel = val;
}

int Data::getFeatureVectorSize()
{
	return featureVector->size();
}

uint8_t Data::getLabel()
{
	return label;
}

uint8_t Data::getEnumeratedLabel()
{
	return enumeratedLabel;
}

std::vector<uint8_t> *Data::getFeatureVector()
{
	return featureVector;
}

std::vector<double> *Data::getNormalizedFeatureVector()
{
	return normalizedFeatureVector;
}

std::vector<int> *Data::getClassVector()
{
	return classVector;
}