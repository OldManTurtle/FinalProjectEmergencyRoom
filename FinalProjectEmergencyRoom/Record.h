//////////////////////////////////
//Title: Record.h
//Authors: Abby Jahns, Aiden McIlraith, Chris Roberts
//Last Modified: 12/7/2018
//Purpose: Define the Record class
//////////////////////////////////

#ifndef RECORD_H
#define RECORD_H
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include "Patient.h"

//This records who is being treated and who has been treated already
class Record
{
public:
	//default constructor
	Record() {}
	//deconstructor
	~Record() {}

	//
	void addName(Patient input) { addName(input.getName(), input.getSeverity()); }

	void addName(std::string, int severity);

	int getNumVisits(std::string input);

	int numPeople() { return data.size(); }

	void display();

	int getSeverityOfVisit(std::string name, int visit);
private:
	std::map<std::string, std::vector<int>> data;
};

#endif