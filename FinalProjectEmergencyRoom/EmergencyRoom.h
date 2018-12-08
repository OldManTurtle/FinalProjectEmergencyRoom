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
	void run(unsigned int numTicks);
	void simpleRun(unsigned int numTicks);
	EmergencyRoom(int numDoc, int numNurse, int rate);
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
