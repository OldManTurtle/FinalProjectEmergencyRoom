#ifndef EMERGENCYROOM_H
#define EMERGENCYROOM_H
#include "PatientQueue.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Record.h"

class EmergencyRoom {
public:
	void run(int numTicks);
	EmergencyRoom(int numDoc, int numNurse);
private:
	Record record;
	PatientQueue queue;
	std::vector<caregiver*> healers;

	std::vector<int> patientWaitTimes;
	int endTick;

	int minutesPerPatient;
};

#endif
