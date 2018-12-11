//////////////////////////////////
//Title: Doctor.cpp
//Authors: Abby Jahns, Aiden McIlraith, Chris Roberts
//Last Modified: 12/7/2018
//Purpose: Implement the Doctor Class
//////////////////////////////////

#include "Doctor.h"



Doctor::Doctor():Caregiver()
{
}

Doctor::~Doctor()
{
}

void Doctor::addPatient(PatientQueue& p, Record& r)
{
	
	currentPatient = p.docTop(); //retrives the first patient in the queue
	if (p.docTop().getSeverity() == -1) { //returns if patients severity is -1
		return;
	}
	p.docPop(); //removes the patient from the queue 

	timeRemaining = rand() % 20 + 1; //randomizes time remaining to 1-20

	r.addName(currentPatient); //adds the patient name to the record
}
