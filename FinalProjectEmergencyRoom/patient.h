#ifndef PATIENT_H
#define PATIENT_H
#include <string>
class patient
{
public:
	patient();
	~patient();
private:
	std::string name;
	int severity;
};

#endif