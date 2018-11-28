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

	bool hasName(std::string); //Check if name is in the queue

	PatientQueue();
	~PatientQueue();
private:

	void display(int lvl, int loc);

	int nurseLoc();

	void swap(int locA, int locB);

	std::vector<patient> data;

	int left(int i) { return i * 2 + 1; }
	int right(int i) { return i * 2 + 2; }
	int up(int i) { return (i - 1) / 2; }
};

#endif