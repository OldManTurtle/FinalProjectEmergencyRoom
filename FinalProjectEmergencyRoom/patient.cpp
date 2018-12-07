#include "patient.h"



Patient::Patient() //This should be random?
{
	severity = rand() % 20 + 1;
	name = getRandName();
	namesInUse.push_back(name);
}

Patient::Patient(const Patient & input)
{
	this->name = input.name;
	this->severity = input.severity;
	namesInUse.push_back(input.name);
}

Patient::Patient(int arrival):arrivalTime(arrival)
{
	int sev = rand() % 10;
	if (sev < 7) {
		sev = rand() % 10 + 1;
	}
	else if (sev < 9) {
		sev = rand() % 5 + 11;
	}
	else {
		sev = rand() % 5 + 16;
	}

	severity = sev;
	name = getRandName();
}

Patient::Patient(int sev, int arrival):arrivalTime(arrival)
{
	severity = sev;
	if (sev == -1)
		name = "";
	else {
		name = getRandName();
	}
	namesInUse.push_back(name);
}

Patient::Patient(int sev_, std::string name_, int arrival):arrivalTime(arrival)
{
	name = name_;
	severity = sev_;
	namesInUse.push_back(name);
}

Patient::~Patient()
{
	for (int i = 0; i < namesInUse.size(); i++) {
		if (namesInUse[i] == name) {
			namesInUse.erase(namesInUse.begin() + i);
			return;
		}
	}
	std::cerr << "Couldn't find a name to delete" << std::endl;
}

void Patient::initNames()
{
	std::string line;
	std::ifstream myFile;
	myFile.open("Names.txt", std::ios::in);
	while (std::getline(myFile, line)) {
		nameList.push_back(line);
	}
	std::srand(std::time(NULL));
}

std::string Patient::getRandName()
{
	std::string name = nameList[rand() % nameList.size()];
	for (int i = 0; i < namesInUse.size(); i++) {
		if (namesInUse[i] == name)
			return getRandName();
	}

	return name;
}

std::vector<std::string> Patient::namesInUse = {};

std::vector<std::string> Patient::nameList = {};

