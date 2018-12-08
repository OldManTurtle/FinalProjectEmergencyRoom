//////////////////////////////////
//Title: Caregiver.h
//Authors: Abby Jahns, Aiden McIlraith, Chris Roberts
//Last Modified: 12/7/2018
//Purpose: Implement Caregiver Class
//////////////////////////////////


#ifndef CAREGIVER_H
#define CAREGIVER_H
#include "PatientQueue.h"
#include "Record.h"

class Caregiver
{
public:

	//constructor
	Caregiver() {}

	//destructor
	virtual ~Caregiver() {}
	
	//pulls a patient off of the queue and adds it to either
	//a doctor or a nurse depending on who calls the function
	virtual void addPatient(PatientQueue&, Record&) = 0;

	//returns true if the doctor or nurse that calls the
	//function is currently treating a patient  
	virtual bool hasPatient() { return timeRemaining > 0; }

	//returns current patient
	virtual Patient& getPatient() { return currentPatient; }

	//decreases the time reamining to treat the current patient
	void decTime() { timeRemaining--; }

protected:
	Patient currentPatient;
	int timeRemaining;
};
#endif