#include "Nurse.h"



Nurse::Nurse()
{
}


Nurse::~Nurse()
{
}

void Nurse::addPatient(PatientQueue p, Record r)
{
	if (p.nurseTop().getSeverity() == -1) {
		std::cerr << "Error in Nurse::addPatient: Patient is -1" << std::endl;
		return;
	}
	else
		currentPatient = p.nurseTop();

	r.addName(currentPatient);
}
