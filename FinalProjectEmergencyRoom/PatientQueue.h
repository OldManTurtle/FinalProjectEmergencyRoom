#ifndef ERHEAP_H
#define ERHEAP_H
#include <vector>
#include <exception>
#include <stdexcept>
#include <iostream>
#include "patient.h"

class PatientQueue {
public:
	patient docTop();

	patient nurseTop();

	void docPop();

	void nursePop();

	void push(patient input);

	void display() { display(0, 0); }

	PatientQueue();
	~PatientQueue();
private:

	void display(int lvl, int loc);

	int nurseLoc();

	void swap(int locA, int locB);

	std::vector<patient> data;

};

#endif