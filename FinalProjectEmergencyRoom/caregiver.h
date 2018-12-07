#ifndef CAREGIVER_H
#define CAREGIVER_H
#include "PatientQueue.h"

class caregiver
{
public:
	caregiver() {}
	virtual ~caregiver() {}
	virtual void addPatient(PatientQueue, Record) = 0;
	virtual bool hasPatient() { return timeRemaining > 0; }
	virtual patient& getPatient() { return currentPatient; }

	void operator--() { timeRemaining--; }
protected:
	patient currentPatient;
	int timeRemaining;
};
#endif