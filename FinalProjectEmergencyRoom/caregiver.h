#ifndef CAREGIVER_H
#define CAREGIVER_H
#include "patient.h"
class caregiver
{
public:
	caregiver();
	virtual ~caregiver();
	virtual void addPatient(patient) = 0;
	bool hasPatient();
	virtual void setTime() = 0;
	void operator--();
private:
	patient currentPatient;
	int timeRemaining;
};
#endif