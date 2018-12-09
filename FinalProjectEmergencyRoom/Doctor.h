//////////////////////////////////
//Title: Doctor.h
//Authors: Abby Jahns, Aiden McIlraith, Chris Roberts
//Last Modified: 12/7/2018
//Purpose: Implement Doctor Class
//////////////////////////////////

#ifndef DOCTOR_H
#define DOCTOR_H

#include "caregiver.h"

//subclass of Caregiver
class Doctor : public Caregiver
{
public:

	//constructor
	Doctor();

	//destructor
	virtual ~Doctor();

	//pulls the top patient from the queue and sets it as 
	//the doctors current patient
	void addPatient(PatientQueue&, Record&);
};

#endif // !DOCTOR_H