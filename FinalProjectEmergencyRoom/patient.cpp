#include "patient.h"



patient::patient() //This should be random?
{
	severity = -1;
	name = "";
	namesInUse.push_back(name);
}

patient::patient(const patient & input)
{
	this->name = input.name;
	this->severity = input.severity;
	namesInUse.push_back(input.name);
}

patient::patient(int sev, int arrival):arrivalTime(arrival)
{
	severity = sev;
	if (sev == -1)
		name = "";
	else {
		name = getRandName();
	}
	namesInUse.push_back(name);
}

patient::patient(int sev_, std::string name_, int arrival):arrivalTime(arrival)
{
	name = name_;
	severity = sev_;
	namesInUse.push_back(name);
}

patient::~patient()
{
	for (int i = 0; i < namesInUse.size(); i++) {
		if (namesInUse[i] == name) {
			namesInUse.erase(namesInUse.begin() + i);
			return;
		}
	}
	std::cerr << "Couldn't find a name to delete" << std::endl;
}

void patient::initNames()
{
	std::string line;
	std::ifstream myFile;
	myFile.open("Names.txt", std::ios::in);
	while (std::getline(myFile, line)) {
		nameList.push_back(line);
	}
	std::srand(std::time(NULL));
}

std::string patient::getRandName()
{
	std::string name = nameList[rand() % nameList.size()];
	for (int i = 0; i < namesInUse.size(); i++) {
		if (namesInUse[i] == name)
			return getRandName();
	}

	return name;
}

std::vector<std::string> patient::namesInUse = {};

std::vector<std::string> patient::nameList = {};

