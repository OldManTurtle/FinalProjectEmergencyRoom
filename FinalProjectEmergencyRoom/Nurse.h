//////////////////////////////////
//Title: Nurse.h
//Authors: Abby Jahns, Aiden McIlraith, Chris Roberts
//Last Modified: 12/7/2018
//Purpose: Define the nurse class
//////////////////////////////////

#ifndef NURSE_H
#define NURSE_H
#include "caregiver.h"
class Nurse :
	public Caregiver
{
public:
	Nurse();
	~Nurse();

	//pulls the top patient from the queue with a 
	//severity less than or equal to 10
	//and sets it as the nurses  current patient
	void addPatient(PatientQueue&, Record&);
};

#endif