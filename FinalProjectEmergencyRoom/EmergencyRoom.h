//////////////////////////////////
//Title: EmergencyRoom.h
//Authors: Abby Jahns, Aiden McIlraith, Chris Roberts
//Last Modified: 12/7/2018
//Purpose: Define the EmergencyRoom class
//////////////////////////////////

#ifndef EMERGENCYROOM_H
#define EMERGENCYROOM_H

#include "Doctor.h"
#include "Nurse.h"

//This is the emergency room. It aggregates doctors and nurses
//and holds a record and a PatientQueue. It knows how many patients
//have been treated and organizes everything.  It also knows the rate
//at which patients arrive at the hospital. It is the only object type 
//that should be implemented in main.
class EmergencyRoom {
public:
	//This runs the program and allows record access
	//It takes the number of minutes to run for
	void run(unsigned int numTicks);

	//This runs the simulation
	//It takes the number of minutes to simulate.
	void simpleRun(unsigned int numTicks);

	//Constructor. It requires the number of doctors, nurses
	//and the rate at which patients are going to arrive
	EmergencyRoom(int numDoc, int numNurse, int rate);

	//This returns a string that can be placed into a
	//data file as a csv. The format is: 
	//avg wait time, avg time between patient arrivals,
	//number of doctors, number of nurses
	std::string getData();

private:
	
	Record record;//This holds a record of all of the patients who have gotten treated
	PatientQueue queue;//This holds the patients that are still waiting to be treated.
	std::vector<Caregiver*> healers;//This holds pointers to all of the doctors and nurses
	std::vector<int> patientWaitTimes; //This stores how long each treated patient waited.

	int minutesPerPatient; //This stores the average time between patient arrivals
};

#endif
