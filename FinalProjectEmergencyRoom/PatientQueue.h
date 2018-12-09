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

	//returns the patient at the top of the queue
	Patient docTop();
	//returns the highest patient in the queue with a severity 
	//of 10 or less
	Patient nurseTop();

	//removes the top patient in the queue
	void docPop();

	//removes the top patient with a severity of 10 or less
	void nursePop();

	//pushes a new patient onto the queue
	void push(Patient input);

	//displays the entire queue (not used in the main simulation)
	void display() { 
		if(data.size())
			display(0, 0); 
	}


	//Check if name is in the queue
	bool hasName(std::string); 

	//increases the severity of any patients that have been waiting 
	//every 30 ticks
	void uptickWait(int currentTick);

	int getSize() { return data.size(); }
	
	//default constructor
	PatientQueue();
	//destructor
	~PatientQueue();
private:
	//reorganizes the heap to preserve it's heapness
	void reorganize(int i);

	//pops the patient at the specified location 
	//and reorganizes the heap
	void pop(int);

	//displays the queue starting at the specified location
	void display(int lvl, int loc);

	//returns the first patient in the queue with a severity of 10 or less
	int nurseLoc();

	//swaps two locations in the queue
	void swap(int locA, int locB);

	std::vector<Patient> data;
	
	//defines useful functions for working with the queue
	int left(int i) { return i * 2 + 1; }
	int right(int i) { return i * 2 + 2; }
	int up(int i) { return (i - 1) / 2; }
};

#endif