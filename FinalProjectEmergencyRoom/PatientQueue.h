#ifndef PATIENTQUEUE_H
#define PATITNEQUEUE_H
#include <vector>
#include "patient.h"
class PatientQueue
{
public:
	PatientQueue();
	~PatientQueue();

	void add(patient);

	patient topDoctor();
	patient topNurse();

	void popDoctor();
	void popNurse();
private:
	std::vector<patient> list;
	void swap(int a, int b);
};

#endif