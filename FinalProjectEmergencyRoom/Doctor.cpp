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
	
	currentPatient = p.docTop();
	if (p.docTop().getSeverity() == -1) {
		return;
	}
	p.docPop();

	timeRemaining = rand() % 20 + 1;

	r.addName(currentPatient);
}
