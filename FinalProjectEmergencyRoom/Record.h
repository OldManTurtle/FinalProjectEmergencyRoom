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

	//adds the name and severity of a patient to the record
	void addName(Patient input) { addName(input.getName(), input.getSeverity()); }

	//adds a specified name and severity to the record
	void addName(std::string, int severity);

	//returns the number of visits for a specified name
	int getNumVisits(std::string input);

	//returns how many people are in the record
	int numPeople() { return data.size(); }

	//displays all of the data stored in the record
	void display();

	//returns the severeity of a specific name on a specific visit
	int getSeverityOfVisit(std::string name, int visit);
private:
	std::map<std::string, std::vector<int>> data;
};

#endif