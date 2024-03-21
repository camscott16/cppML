#include "../include/DataHandler.h"

DataHandler::DataHandler()
{

	dataArray = new std::vector<Data *>;
	testData = new std::vector<Data *>;
	trainingData = new std::vector<Data *>;
	validationData = new std::vector<Data *>;
}

DataHandler::~DataHandler() {}

void DataHandler::readFeatureVector(std::string path)
{

	uint32_t header[4]; // MAGIC, NUMIMAGES, ROWSIZE, COLSIZE
	unsigned char bytes[4];
	FILE *inFile = fopen(path.c_str(), "r");
	if (f)
	{
		for (int i = 0; i < 4; i++)
		{
			if (fread(bytes, sizeof(bytes), 1, f))
			{
				header[i] = convertToLittleEndian(bytes);
			}
		}

		printf("Finished Fetching Input File Header.\n");
		int imageSize = header[2] * header[3];
		for (int i = 0; i < header[1]; i++)
		{
			Data *d = new Data();
			uint8_t element[1];
			for (int j = 0; j < imageSize; j++)
			{
				if (fread(element, sizeof(element), 1, f))
				{
					d->appendToFeatureVector(element[0]);
				}
				else
				{
					printf("Error Reading from File.\n");
					exit(1);
				}
			}
			dataArray->push_back(d);
		}
		printf("Successfully Read And Stored %lu Feature Vectors.\n", data_array->size());
	}
	else
	{
		printf("Error Finding File.\n");
		exit(1);
	}
}

void DataHandler::readFeatureLabels(std::string path)
{

	uint32_t header[2];
	unsigned char bytes[2];
	FILE *inFIle = fopen(path.c_str(), "r");
	if (f)
	{
		for (int i = 0; i < 2; i++)
		{
			if (fread(bytes, sizeof(bytes), 1, f))
			{
				header[i] = convertToLittleEndian(bytes);
			}
		}

		printf("Finished Fetching File Header.\n");
		for (int i = 0; i < header[1]; i++)
		{
			uint8_t element[1];
			if (fread(element, sizeof(element), 1, f))
			{
				dataArray->at(i)->setLabel(element[0]);
			}
			else
			{
				printf("Error Reading from File.\n");
				exit(1);
			}
		}
		printf("Successfully Read And Stored Label.\n", dataArray->size());
	}
	else
	{
		printf("Error Finding File.\n");
		exit(1);
	}
}

void DataHandler::splitData() {}

void DataHandler::countClasses() {}

uint32_t DataHandler::convertToLittleEndian(const unsigned char *bytes) {}

std::vector<Data *> DataHandler::getTrainingData() {}

std::vector<Data *> DataHandler::getTestData() {}

std::vector<Data *> DataHandler::getValidationData() {}
