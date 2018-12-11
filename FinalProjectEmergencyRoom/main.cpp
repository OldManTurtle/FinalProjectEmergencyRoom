//////////////////////////////////
//Title: main
//Authors: Abby Jahns, Aiden McIlraith, Chris Roberts
//Last Modified: 12/7/2018
//Purpose: Implement the er class
//////////////////////////////////
#include<iostream>
#include "EmergencyRoom.h"

int main() {
	Patient::initNames();
	char answer;
	std::cout << "Run the simulation manually? [y/n]";
	std::cin >> answer;

	double rate;

	int doc, nurse;
	
	if (answer == 'y') {
		std::cout << "Enter average hourly patient arrival rate, the number of Doctors working, and the number of Nurses working\n";

		std::cin >> rate >> doc >> nurse;

		rate = 60 / rate;

		EmergencyRoom er(doc, nurse, int(rate));
		er.run(24 * 60 * 7);
	}
	else {
		std::ofstream myfile;
		myfile.open("data.txt", std::ios::out);
			for (int i = 3; i <= 15; i++) {
				EmergencyRoom er(1, 2, i);
				er.simpleRun(24 * 60 * 7);
				myfile << er.getData() << ", 1, 2" << std::endl;

				EmergencyRoom era(1, 2, i);
				era.simpleRun(24 * 60 * 7);
				myfile << era.getData() << ", 1, 2" << std::endl;
			}
			for (int i = 3; i <= 15; i++) {
				EmergencyRoom er(2, 1, i);
				er.simpleRun(24 * 60 * 7);
				myfile << er.getData() << ", 2, 1" << std::endl;

				EmergencyRoom era(2, 1, i);
				era.simpleRun(24 * 60 * 7);
				myfile << era.getData() << ", 2, 1" << std::endl;
			}
			for (int i = 3; i <= 15; i++) {
				EmergencyRoom er(1, 1, i);
				er.simpleRun(24 * 60 * 7);
				myfile << er.getData() << ", 1, 1" << std::endl;

				EmergencyRoom era(1, 1, i);
				era.simpleRun(24 * 60 * 7);
				myfile << era.getData() << ", 1, 1" << std::endl;
			}
		myfile.close();

	}
	
	


}