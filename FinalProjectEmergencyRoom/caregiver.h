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

//This is the parent class for Doctors and Nurses.
//It holds a patient and a time left to treat the patient.
class Caregiver
{
public:
	//Theconstructor takes no arguements because there is no 
	//situation in which a caregiver should be built with a 
	//patient already inside of it
	Caregiver() { timeRemaining = 0; }

	//Default virtual constructor
	virtual ~Caregiver() {}
	
	//pulls a patient off of the queue and adds it to either
	//a doctor or a nurse depending on who calls the function.
	//This is purely virtual, so it must be adjusted to force
	//a certain starting position
	virtual void addPatient(PatientQueue&, Record&) = 0;

	//returns true if the cargiver is still treating a patient
	virtual bool hasPatient() { return timeRemaining > 0; }

	//returns current patient by reference-
	virtual Patient& getPatient() { return currentPatient; }

	//decreases the time reamining to treat the current patient
	void decTime() { timeRemaining--; }

protected:
	Patient currentPatient; //Holds a copy of the patient currently being treated
	int timeRemaining; //Holds the time remaining to treat a patient
};
#endif