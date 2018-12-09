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
	//Just calls Caregiver()
	Nurse();

	//Does nothing
	~Nurse();

	//This treats the patient with the highest
	//priority under 11. See Doctor::addPatient
	//for more information.
	void addPatient(PatientQueue&, Record&);
};

#endif