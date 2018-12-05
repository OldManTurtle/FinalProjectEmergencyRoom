#include "Doctor.h"



Doctor::Doctor()
{
}

Doctor::~Doctor()
{
}

void Doctor::addPatient(PatientQueue p, Record& r)
{
	if (p.docTop().getSeverity() == -1) {
		std::cerr << "Error in Doctor::addPatient: Patient is -1" << std::endl;
		return;
	}
	else 
		currentPatient = p.docTop();

	r.addName(currentPatient);
}
