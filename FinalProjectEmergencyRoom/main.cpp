#include<iostream>

#include "EmergencyRoom.h"

int main() {
	//fileio here
	std::ofstream myfile;
	myfile.open("data.txt",std::ios::out);
	myfile << "New Log" << std::endl;
	//for loop 7x24x60 random chance to add someone to queue
	Patient::initNames();

	double rate;
	int doc, nurse;
	std::cin >> doc;
	if (doc) {
		std::cout << "Enter average hourly patient arrival rate, the number of Doctors working, and the number of Nurses working\n";

		std::cin >> rate >> doc >> nurse;

		rate = 60 / rate;

		EmergencyRoom er(doc, nurse, int(rate));
		er.run(24 * 60 * 7);
	}
	else {
		for (int i = 2; i <= 15; i++) {
			EmergencyRoom er(1, 2, i);
			er.altrun(24 * 60 * 7);
			myfile << er.getData() << ", 1, 2" << std::endl;
		}
		for (int i = 2; i <= 15; i++) {
			EmergencyRoom er(2, 1, i);
			er.altrun(24 * 60 * 7);
			myfile << er.getData() << ", 2, 1" << std::endl;
		}
		for (int i = 2; i <= 15; i++) {
			EmergencyRoom er(1, 1, i);
			er.altrun(24 * 60 * 7);
			myfile << er.getData() << ", 1, 1" << std::endl;
		}

	}
	myfile.close();
	


}