#ifndef CAREGIVER_H
#define CAREGIVER_H
#include "PatientQueue.h"
//This and children are not done
class caregiver
{
public:
	caregiver() {}
	virtual ~caregiver() {}
	virtual void addPatient(PatientQueue, Record) = 0;
	virtual bool hasPatient();
	virtual patient& getPatient() { return currentPatient; }
	virtual void setTime(int time) = 0;
	void operator--() { timeRemaining--; }
protected:
	patient currentPatient;
	int timeRemaining;
};
#endif