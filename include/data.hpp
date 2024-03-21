#ifndef DATA_H
#define DATA_H

#include <vector>
#include <stdint.h>
#include <stdio.h>

class Data
{

	std::vector<uint8_t> *featureVector; // no class at the end
	std::vector<double> *normalizedFeatureVector;
	std::vector<int> *classVector;
	uint8_t label;
	int enumeratedLabel; // might not need this but good practice
	double distance;

public:
	void setDistance(double);
	void setFeatureVector(std::vector<uint8_t> *);
	void setNormalizedFeatureVector(std::vector<double> *);
	void setClassVector(int counts);
	void appendToFeatureVector(uint8_t);
	void appendToFeatureVector(double);
	void setLabel(uint8_t);
	void setEnumeratedLabel(int);

	void printVector();
	void printNormalizedVector();

	int getFeatureVectorSize();
	uint8_t getLabel();
	uint8_t getEnumeratedLabel();

	std::vector<uint8_t> *getFeatureVector();
	std::vector<double> *getNormalizedFeatureVector();
	std::vector<int> *getClassVector();
};

#endif
