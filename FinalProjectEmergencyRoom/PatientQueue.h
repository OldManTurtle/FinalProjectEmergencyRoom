#ifndef ERHEAP_H
#define ERHEAP_H
#include <vector>
#include <exception>
#include <stdexcept>
#include <iostream>
#include "patient.h"

class PatientQueue {
public:
	Patient docTop();

	Patient nurseTop();

	void docPop();

	void nursePop();

	void push(Patient input);

	void display() { display(0, 0); }

	bool hasName(std::string); //Check if name is in the queue

	int getSize() { return data.size(); }
	PatientQueue();
	~PatientQueue();
private:
	void pop(int);

	void display(int lvl, int loc);

	int nurseLoc();

	void swap(int locA, int locB);

	std::vector<Patient> data;

	int left(int i) { return i * 2 + 1; }
	int right(int i) { return i * 2 + 2; }
	int up(int i) { return (i - 1) / 2; }
};

#endif