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

//Patients get treated by Caregivers. They have a name,
//a severity, and an arrival time. There
//are also two static vectors which hold the master list
//of names and the names that are currently being used
//so that we don't get the same person twice in the queue.
class Patient
{
public:
	//The default constructer creates a null Patient with all values -1 and ""
	Patient();
	Patient(const Patient&);

	//This takes the time of arrival and generates a random name and severity
	//There is a 70% chance the severity is 1-10, 20% it's 11-15, and 10% that
	//it's 16-20. The name is generated from the masterlist and crosschecked with
	//the names in use so that there is no overlap.
	Patient(int);

	~Patient();

	//Comparison operators. They compare severites of two patients.
	bool operator>(Patient i) { return this->severity > i.severity; }
	bool operator<(Patient i) { return this->severity < i.severity; }

	//getters
	int getSeverity() { return severity; }
	std::string getName() { return name; }
	int getArrivalTime() { return arrivalTime; }
	static int getDeaths() { return deadList.size(); }
	static void showDeaths();

	static void kill(std::string);
	//This retrieves the names from the file and stores them in the master list
	static void initNames();
	
	//Increases the severity
	void iterateSeverity() { severity++; }
private:
	//This retrieves a name from the master vector of names and crosschecks it with
	//the vector of names in use.
	std::string getRandName();


	std::string name;
	int severity; //Value between 1-20
	int arrivalTime;

	//Vectors of names used to prevent duplicates
	static std::vector<std::string> namesInUse;
	static std::vector<std::string> nameList;
	static std::vector<std::string> deadList; //Stores the names of the people who died

	
};

#endif