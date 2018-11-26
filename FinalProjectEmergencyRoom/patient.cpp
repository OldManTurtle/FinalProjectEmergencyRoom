#include "patient.h"



patient::patient() //This should be random?
{
	severity = -1;
	name = "";
}

patient::patient(int sev)
{
	severity = sev;
	if (sev == -1)
		name = "";
	else
		name = "John Doe";
}

patient::patient(int sev_, std::string name_)
{
	name = name_;
	severity = sev_;
}

patient::~patient()
{
}
