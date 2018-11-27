#ifndef CAREGIVER_H
#define CAREGIVER_H
#include "PatientQueue.h"
class caregiver
{
public:
	caregiver() {}
	virtual ~caregiver() {}
	virtual void addPatient(PatientQueue) = 0;
	virtual bool hasPatient() {
		return true;
	}
	virtual void setTime(int time) = 0;
	void operator--() { timeRemaining--; }
protected:
	patient currentPatient;
	int timeRemaining;
};
#endif