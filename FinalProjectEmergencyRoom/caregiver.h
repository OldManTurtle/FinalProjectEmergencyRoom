#ifndef CAREGIVER_H
#define CAREGIVER_H
#include "PatientQueue.h"
class caregiver
{
public:
	caregiver();
	virtual ~caregiver();
	virtual void addPatient(PatientQueue) = 0;
	bool hasPatient();
	virtual void setTime() = 0;
	void operator--() { timeRemaining--; }
private:
	patient currentPatient;
	int timeRemaining;
};
#endif