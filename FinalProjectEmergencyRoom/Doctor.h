//////////////////////////////////
//Title: Doctor.h
//Authors: Abby Jahns, Aiden McIlraith, Chris Roberts
//Last Modified: 12/7/2018
//Purpose: Implement Doctor Class
//////////////////////////////////

#ifndef DOCTOR_H
#define DOCTOR_H


#include "caregiver.h"

//Subclass of Caregiver. It can treat patients of severity 1-20
//and takes 1-20 mins to do so.
class Doctor : public Caregiver
{
public:
	//Default constructor. Just calls Caregiver()
	Doctor();
	virtual ~Doctor();

	//Takes patient from the very top of the PatientQueue
	//that gets passed in and saves it. The time remaining
	//gets set to a random number between 1 and 20, and
	//the patient is recorded.
	void addPatient(PatientQueue&, Record&);
};

#endif // !DOCTOR_H