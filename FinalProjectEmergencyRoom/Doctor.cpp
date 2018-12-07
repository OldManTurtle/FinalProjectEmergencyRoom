#include "Doctor.h"



Doctor::Doctor()
{
}

Doctor::~Doctor()
{
}

void Doctor::addPatient(PatientQueue& p, Record& r)
{
	if (p.docTop().getSeverity() == -1) {
		std::cerr << "Error in Doctor::addPatient: Patient is -1" << std::endl;
		return;
	} 
	currentPatient = p.docTop();
	p.docPop();

	timeRemaining = rand() % 20 + 1;

	r.addName(currentPatient);
}
