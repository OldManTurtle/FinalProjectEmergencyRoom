#ifndef EMERGENCYROOM_H
#define EMERGENCYROOM_H

#include "Doctor.h"
#include "Nurse.h"

class EmergencyRoom {
public:
	void run(int numTicks);
	EmergencyRoom(int numDoc, int numNurse, int rate);
private:
	Record record;
	PatientQueue queue;
	std::vector<caregiver*> healers;

	std::vector<int> patientWaitTimes;
	int endTick;

	int minutesPerPatient;
};

#endif
