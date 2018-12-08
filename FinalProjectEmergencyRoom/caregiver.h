//////////////////////////////////
//Title:
//Authors: Abby Jahns, Aiden McIlraith, Chris Roberts
//Last Modified: 12/7/2018
//Purpose:
//////////////////////////////////


#ifndef CAREGIVER_H
#define CAREGIVER_H
#include "PatientQueue.h"
#include "Record.h"

class Caregiver
{
public:
	Caregiver() {}
	virtual ~Caregiver() {}
	virtual void addPatient(PatientQueue&, Record&) = 0;
	virtual bool hasPatient() { return timeRemaining > 0; }
	virtual Patient& getPatient() { return currentPatient; }

	void decTime() { timeRemaining--; }
protected:
	Patient currentPatient;
	int timeRemaining;
};
#endif