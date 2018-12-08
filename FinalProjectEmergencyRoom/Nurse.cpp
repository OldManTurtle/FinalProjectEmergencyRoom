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
