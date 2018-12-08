#ifndef EMERGENCYROOM_H
#define EMERGENCYROOM_H

#include "Doctor.h"
#include "Nurse.h"

class EmergencyRoom {
public:
	void run(unsigned int numTicks);
	void altrun(unsigned int numTicks);
	EmergencyRoom(int numDoc, int numNurse, int rate);
	std::string getData();

private:
	Record record;
	PatientQueue queue;
	std::vector<caregiver*> healers;
	

	std::vector<int> patientWaitTimes;
	int endTick;

	int minutesPerPatient;
};

#endif
