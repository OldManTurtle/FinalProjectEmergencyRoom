#include "patient.h"



patient::patient() //This should be random?
{
	severity = -1;
	name = "";
	namesInUse.push_back(name);
}

patient::patient(const patient & input)
{
	namesInUse.push_back(input.name);
}

patient::patient(int sev)
{
	severity = sev;
	if (sev == -1)
		name = "";
	else {
		name = getRandName();
	}
	namesInUse.push_back(name);
}

patient::patient(int sev_, std::string name_)
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
}

std::string patient::getRandName()
{
	
	return std::string();
}

