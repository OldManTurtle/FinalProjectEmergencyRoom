//////////////////////////////////
//Title:
//Authors: Abby Jahns, Aiden McIlraith, Chris Roberts
//Last Modified: 12/7/2018
//Purpose:
//////////////////////////////////

#ifndef DOCTOR_H
#define DOCTOR_H


#include "caregiver.h"
class Doctor : public Caregiver
{
public:
	Doctor();
	virtual ~Doctor();
	void addPatient(PatientQueue&, Record&);
};

#endif // !DOCTOR_H