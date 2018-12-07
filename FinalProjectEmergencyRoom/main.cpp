#include<iostream>

#include "EmergencyRoom.h"

int main() {
	//fileio here
	//for loop 7x24x60 random chance to add someone to queue
	Patient::initNames();

	double rate;
	int doc, nurse;

	std::cout << "Enter average hourly patient arrival rate, the number of Doctors working, and the number of Nurses working\n";

	std::cin >> rate >> doc >> nurse;

	rate = 60 / rate;

	EmergencyRoom er(doc, nurse, int(rate));
	er.run(24*60);


	


}