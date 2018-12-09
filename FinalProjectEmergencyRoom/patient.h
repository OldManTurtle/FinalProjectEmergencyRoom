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

	//default constructor sets severity and arrivalTime to -1 and the name to ""
	Patient();
	//copy constructor
	Patient(const Patient&);
	//constructor takes arrival time and randomizes severity and randomizes name
	Patient(int);
	//constructor takes arrival time and sevarity and randomizes name
	Patient(int, int);
	//constructor takes arrival time, name, and severity
	Patient(int, std::string, int);

	//destructor
	~Patient();

	//operator overload > compares severity
	bool operator>(Patient i) { return this->severity > i.severity; }
	//operator overload < compares severity
	bool operator<(Patient i) { return this->severity < i.severity; }

	//returns severity
	int getSeverity() { return severity; }

	//pulls names from the Names.txt file and adds them to the namesList vector
	static void initNames();

	//returns name
	std::string getName() { return name; }

	//returns arrival time
	int getArrivalTime() { return arrivalTime; }

	//increases severity by 1
	void iterateSeverity() { severity++; }
private:
	//returns random name from the namesList vector that is not in the 
	//namesInUse vector
	std::string getRandName();


	std::string name;
	int severity;

	static std::vector<std::string> namesInUse;
	static std::vector<std::string> nameList;

	int arrivalTime;
};

#endif