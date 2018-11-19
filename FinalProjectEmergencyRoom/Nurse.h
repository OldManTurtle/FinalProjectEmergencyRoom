#ifndef NURSE_H
#define NURSE_H
#include "caregiver.h"
class Nurse :
	public caregiver
{
public:
	Nurse();
	~Nurse();
	void setTime();
	void addPatient(patient);
};

#endif