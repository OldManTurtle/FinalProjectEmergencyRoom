//////////////////////////////////
//Title: PatientQueue.h
//Authors: Abby Jahns, Aiden McIlraith, Chris Roberts
//Last Modified: 12/7/2018
//Purpose: Define the PatientQueue class
//////////////////////////////////

#ifndef ERHEAP_H
#define ERHEAP_H
#include <vector>
#include <exception>
#include <stdexcept>
#include <iostream>
#include "Patient.h"

class PatientQueue {
public:
	Patient docTop();

	Patient nurseTop();

	void docPop();

	void nursePop();

	void push(Patient input);

	void display() { 
		if(data.size())
			display(0, 0); 
	}

	bool hasName(std::string); //Check if name is in the queue

	void uptickWait(int currentTick);

	int getSize() { return data.size(); }
	PatientQueue();
	~PatientQueue();
private:
	void reorganize(int i);

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