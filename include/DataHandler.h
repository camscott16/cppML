#ifndef DATA_HANDLER_H
#define DATA_HANDLER_H

#include <fstream>
#include <stdint.h>
#include "Data.hpp"
#include <map>
#include <string>
#include <vector>
#include <unordered_set>

class DataHandler
{

	std::vector<Data *> *dataArray; // all of the data (pre-split)i
	std::vector<Data *> *trainingData;
	std::vector<Data *> *testData;
	std::vector<Data *> *validationData;

	int numClasses;
	int featureVectorSize;
	std::map<uint8_t, int> classMap;

	// needed to split data, size of split determined at this point (should total to 1)
	const double TRAIN_SET_PERCENT = 0.75;
	const double TEST_SET_PERCENT = 0.20;
	const double VALIDATION_PERCENT = 0.05;

public:
	DataHandler();
	~DataHandler();

	void readFeatureVector(std::string path);
	void readFeatureLabels(std::string path);
	void splitData();
	void countClasses();

	uint32_t convertToLittleEndian(const unsigned char *bytes);

	std::vector<Data *> getTrainingData();
	std::vector<Data *> getTestData();
	std::vector<Data *> getValidationData();
};

#endif
