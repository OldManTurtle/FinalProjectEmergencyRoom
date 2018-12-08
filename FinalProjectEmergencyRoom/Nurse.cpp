//////////////////////////////////
//Title: Nurse.cpp	
//Authors: Abby Jahns, Aiden McIlraith, Chris Roberts
//Last Modified: 12/7/2018
//Purpose: Implement the Nurse class
//////////////////////////////////

#include "Nurse.h"



Nurse::Nurse()
{
}


Nurse::~Nurse()
{
}

void Nurse::addPatient(PatientQueue& p, Record& r)
{
	if (p.nurseTop().getSeverity() == -1) {
		return;
	}
	currentPatient = p.nurseTop();
	p.nursePop();

	timeRemaining = rand() % 10 + 1;

	r.addName(currentPatient);
}
