#include<iostream>

#include "Doctor.h"
#include "Nurse.h"
#include "Record.h"
#include "PatientQueue.h"

int main() {
	//fileio here
	//for loop 7x24x60 random chance to add someone to queue
	
	double rate;
	int doc, nurse;

	std::cout << "Enter average hourly patient arrival rate, the number of Doctors working, and the number of Nurses working\n";

	std::cin >> rate >> doc >> nurse;

	rate = 60 / rate;


	


}