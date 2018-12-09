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

class EmergencyRoom {
public:

	//Simulates for a specified number of ticks
	//does not have any options at the end of the simulation
	//used to run many tests in a row without having to interact
	//with the program
	void simpleRun(unsigned int numTicks);
	
	//calls simpleRun and gives the user menu options at the end 
	//of the simulation
	void run(unsigned int numTicks);
	

	//constructor initializes number of Doctors, number of
	//Nurses, and the rate of incoming patients
	EmergencyRoom(int numDoc, int numNurse, int rate);

	//returns a csv string of the average wait time per patient and
	//the rate of minutes per patient
	std::string getData();

private:
	Record record;
	PatientQueue queue;
	std::vector<Caregiver*> healers;
	
	std::vector<int> patientWaitTimes;
	int endTick;
	int minutesPerPatient;
};

#endif
