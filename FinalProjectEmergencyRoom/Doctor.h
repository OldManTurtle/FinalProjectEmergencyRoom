#pragma once
#include "caregiver.h"
class Doctor :
	public caregiver
{
public:
	Doctor();
	virtual ~Doctor();
	void setTime(int time){
		timeRemaining = time;
	}
	void addPatient(patient);
};

