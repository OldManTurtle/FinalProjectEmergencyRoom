#ifndef CAREGIVER_H
#define CAREGIVER_H
#include "PatientQueue.h"
#include "Record.h"

class caregiver
{
public:
	caregiver() {}
	virtual ~caregiver() {}
	virtual void addPatient(PatientQueue&, Record&) = 0;
	virtual bool hasPatient() { return timeRemaining > 0; }
	virtual Patient& getPatient() { return currentPatient; }

	void decTime() { timeRemaining--; }
protected:
	Patient currentPatient;
	int timeRemaining;
};
#endif