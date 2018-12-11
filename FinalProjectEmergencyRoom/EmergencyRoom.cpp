//////////////////////////////////
//Title: EmergencyRoom.cpp
//Authors: Abby Jahns, Aiden McIlraith, Chris Roberts
//Last Modified: 12/7/2018
//Purpose: Implement the EmergencyRoom class
//////////////////////////////////

#include "EmergencyRoom.h"

void EmergencyRoom::run(unsigned int numTicks)
{
	//run simulation
	simpleRun(numTicks);

	while (true) {
		std::cout << "Would you like to see the [r]ecord or a [s]pecific patient by name or [e]xit? ";
		std::string response;
		std::cin >> response;
		double sum = 0;
		switch (response[0]) {
		case 'r':
			record.display();
			std::cout << "Average Wait Time: ";
			for (int i = 0; i < patientWaitTimes.size(); i++) {
				sum += patientWaitTimes[i];
			}
			sum = sum / patientWaitTimes.size();
			std::cout << sum << std::endl;

			std::cout << "Patients left in queue: " << queue.getSize() << std::endl;
			std::cout << "Number of total Treatments: " << patientWaitTimes.size() << std::endl;
			std::cout << "Number of Patients Treated: " << record.numPeople() << std::endl;
			std::cout << "Number of Deaths: " << Patient::getDeaths() << std::endl;
			std::cout << "People who died:" << std::endl;
			Patient::showDeaths();
			break;
		case 's':
			std::cout << "What name? ";
			std::cin >> response;
			std::cout << record.getNumVisits(response) << std::endl;
			break;
		case 'e':
			return;
			break;
		default:
			break;
		}
	}

}

void EmergencyRoom::simpleRun(unsigned int numTicks)
{
	Patient::initNames();
	
	for (unsigned int currentTick = 0; currentTick < numTicks; currentTick++) {
		queue.uptickWait(currentTick);
		
		//calculates percent done
		if (currentTick % 101 == 0) {
			std::cout << currentTick / 101 << "% Patients dead: " << Patient::getDeaths() << std::endl;
		}
		if (rand() % minutesPerPatient == 0)
			queue.push(Patient(currentTick));


		//adds a patient if a healer doesn't have one
		//and pushes that patient's arrival time
		for (int i = 0; i < healers.size(); i++) {
			healers[i]->decTime();

			if (!(healers.at(i)->hasPatient())) {
				healers[i]->addPatient(queue, record);
				if (healers[i]->getPatient().getArrivalTime() != -1)
					patientWaitTimes.push_back(currentTick - (healers[i]->getPatient().getArrivalTime()));
			}
		}
	}
	std::cout << "100% --> Done!" << std::endl;
}

EmergencyRoom::EmergencyRoom(int numDoc, int numNurse, int rate):minutesPerPatient(rate)
{
	for (int i = 0; i < numDoc; i++)
		healers.push_back(new Doctor);

	for (int i = 0; i < numNurse; i++)
		healers.push_back(new Nurse);

}

std::string EmergencyRoom::getData()
{
	std::string x = "";
	double sum = 0;
	for (int i = 0; i < patientWaitTimes.size(); i++) {
		sum += patientWaitTimes[i];
	}
	sum = sum / patientWaitTimes.size();
	x = x +  std::to_string(minutesPerPatient) + "," + std::to_string(sum) + std::string(",") + std::to_string(Patient::getDeaths());
	return x;
}
