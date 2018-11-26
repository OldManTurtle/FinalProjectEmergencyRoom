#ifndef PATIENT_H
#define PATIENT_H
#include <string>
class patient
{
public:
	patient();
	patient(int);
	patient(int, std::string);
	~patient();

	bool operator>(patient i) { return this->severity > i.severity; }
	bool operator<(patient i) { return this->severity < i.severity; }

	int getSeverity() { return severity; }
private:
	std::string name;
	int severity;
};

#endif