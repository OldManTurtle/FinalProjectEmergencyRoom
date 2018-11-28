#ifndef PATIENT_H
#define PATIENT_H
#include <string>
#include <fstream>
#include "Record.h"
#include <vector>
#include <iostream>

class PatientQueue;

class patient
{
public:
	patient();
	patient(const patient&);
	patient(int);
	patient(int, std::string);
	~patient();

	bool operator>(patient i) { return this->severity > i.severity; }
	bool operator<(patient i) { return this->severity < i.severity; }

	int getSeverity() { return severity; }

	static void initNames();
private:
	std::string getRandName();
	std::string name;
	int severity;

	static std::vector<std::string> namesInUse;
	static std::vector<std::string> nameList;
};

#endif