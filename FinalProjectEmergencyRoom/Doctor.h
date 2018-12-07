#ifndef DOCTOR_H
#define DOCTOR_H


#include "caregiver.h"
class Doctor : public caregiver
{
public:
	Doctor();
	virtual ~Doctor();
	void addPatient(PatientQueue&, Record&);
};

#endif // !DOCTOR_H