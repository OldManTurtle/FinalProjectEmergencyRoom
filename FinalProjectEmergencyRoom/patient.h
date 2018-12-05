#ifndef PATIENT_H
#define PATIENT_H
#include <string>
#include <fstream>
#include "Record.h"
#include <vector>
#include <iostream>
#include <random>
#include <ctime>

class PatientQueue;

class patient
{
public:
	patient();
	patient(const patient&);
	patient(int, int);
	patient(int, std::string, int);

	~patient();

	bool operator>(patient i) { return this->severity > i.severity; }
	bool operator<(patient i) { return this->severity < i.severity; }

	int getSeverity() { return severity; }

	static void initNames();

	std::string getName() { return name; }
private:
	std::string getRandName();


	std::string name;
	int severity;

	static std::vector<std::string> namesInUse;
	static std::vector<std::string> nameList;

	int arrivalTime;
};

#endif