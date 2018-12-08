//////////////////////////////////
//Title: Patient.h
//Authors: Abby Jahns, Aiden McIlraith, Chris Roberts
//Last Modified: 12/7/2018
//Purpose: Define the Patient class
//////////////////////////////////

#ifndef PATIENT_H
#define PATIENT_H
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <random>
#include <ctime>

class Record;
class PatientQueue;

class Patient
{
public:
	Patient();
	Patient(const Patient&);
	Patient(int);
	Patient(int, int);
	Patient(int, std::string, int);

	~Patient();

	bool operator>(Patient i) { return this->severity > i.severity; }
	bool operator<(Patient i) { return this->severity < i.severity; }

	int getSeverity() { return severity; }

	static void initNames();

	std::string getName() { return name; }

	int getArrivalTime() { return arrivalTime; }

	void iterateSeverity() { severity++; }
private:
	std::string getRandName();


	std::string name;
	int severity;

	static std::vector<std::string> namesInUse;
	static std::vector<std::string> nameList;

	int arrivalTime;
};

#endif