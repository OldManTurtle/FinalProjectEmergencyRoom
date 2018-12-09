//////////////////////////////////
//Title: Nurse.cpp	
//Authors: Abby Jahns, Aiden McIlraith, Chris Roberts
//Last Modified: 12/7/2018
//Purpose: Implement the Nurse class
//////////////////////////////////

#include "Nurse.h"

Nurse::Nurse():Caregiver()
{
}

Nurse::~Nurse()
{
}

void Nurse::addPatient(PatientQueue& p, Record& r)
{
	currentPatient = p.nurseTop(); //retrives the first patient that a nurse can treat
	if (p.nurseTop().getSeverity() == -1) { //returns if patient's severity is -1
		return;
	}
	p.nursePop(); //removes the patient from the queue

	timeRemaining = rand() % 10 + 1; //randomize time remaining from 1-10

	r.addName(currentPatient); //adds the patient to the record
}
