#ifndef RECORD_H
#define RECORD_H
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include "patient.h"
//This records who is being treated and who has been treated already
class Record
{
public:
	Record() {}
	~Record() {}

	void addName(patient input) { addName(input.getName(), input.getSeverity()); }

	void addName(std::string, int severity);

	int getNumVisits(std::string input);

	void display();

	int getSeverityOfVisit(std::string name, int visit);
private:
	std::map<std::string, std::vector<int>> data;
};

#endif